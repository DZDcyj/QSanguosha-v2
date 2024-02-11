#include "audio.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QCoreApplication>

class Sound;

static QCache<QString, Sound> SoundCache;
static Sound *BackgroudMusic;
static QMediaPlaylist *BgmList;

class Sound : public QMediaPlayer
{
public:
    Sound(const QString &filename = "", QObject *parent = nullptr)
        : QMediaPlayer(parent, QMediaPlayer::LowLatency), path("")
    {
        this->setSource(filename);
    }

    void setSource(const QString &filename)
    {
        if (filename.isEmpty()) {
            this->setMedia(QUrl());
        } else {
            QString AudioPrefix = QCoreApplication::applicationDirPath();
            this->path = QString("%1/%2").arg(AudioPrefix).arg(filename);
            this->setMedia(QUrl::fromLocalFile(QFileInfo(filename).absoluteFilePath()));
        }
    }

    bool isPlaying() const
    {
        return this->state() == QMediaPlayer::State::PlayingState;
    }

private:
    QString path;
};

void Audio::init()
{
    BgmList = new QMediaPlaylist();
    BackgroudMusic = new Sound();
    BackgroudMusic->setPlaylist(BgmList);
}

void Audio::quit()
{
    SoundCache.clear();
    BgmList->clear();
}

void Audio::play(const QString &filename, bool superpose)
{
    Sound *sound = SoundCache[filename];
    if (sound == NULL) {
        sound = new Sound(filename);
        SoundCache.insert(filename, sound);
    } else if (!superpose && sound->isPlaying()) {
        return;
    }
    sound->play();
}

void Audio::stop()
{
    foreach (QString filename, SoundCache.keys()) {
        Sound *sound = SoundCache[filename];
        if (sound != NULL && sound->isPlaying()) {
            sound->stop();
        }
    }
    stopBGM();
}

void Audio::playBGM(const QString &filename)
{
    if (BackgroudMusic->isPlaying()) {
        BackgroudMusic->stop();
        BgmList->removeMedia(BgmList->currentIndex());
    }

    BgmList->addMedia(QUrl::fromLocalFile(QFileInfo(filename).absoluteFilePath()));
    BgmList->setPlaybackMode(QMediaPlaylist::PlaybackMode::Loop);
    BackgroudMusic->play();
}

void Audio::setBGMVolume(float volume)
{
    BackgroudMusic->setVolume(100 * volume);
}

void Audio::stopBGM()
{
    if (BackgroudMusic->isPlaying()) {
        BackgroudMusic->stop();
    }
}
