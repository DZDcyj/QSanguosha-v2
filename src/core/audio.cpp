#ifdef AUDIO_SUPPORT

#include "audio.h"
#include <QMediaPlayer>
#include <QAudioOutput>
class Sound : public QMediaPlayer
{
public:
    Sound(const QString &filename = "", QObject *parent = nullptr)
        : QMediaPlayer(parent), path("")
    {
        this->setSource(filename);
    }

    void setSource(const QString &filename)
    {
        if (filename.isEmpty()) {
            QMediaPlayer::setSource(QUrl());
        } else {
            QString AudioPrefix = QCoreApplication::applicationDirPath();
            this->path = QString("%1/%2").arg(AudioPrefix).arg(filename);
            QMediaPlayer::setSource(QUrl::fromLocalFile(QFileInfo(filename).absoluteFilePath()));
        }
    }
#if QT_VERSION < QT_VERSION_CHECK(6, 5, 0)
    bool isPlaying() const {
        return playbackState() == QMediaPlayer::PlaybackState::PlayingState;
    }
#endif
private:
    QString path;
};

static QCache<QString, Sound> SoundCache;
static std::unique_ptr<Sound> BackgroundMusic;
static std::unique_ptr<QAudioOutput> audioOutput;
static std::unique_ptr<QAudioOutput> bgmAudioOutput;

void Audio::init(){
    audioOutput = std::make_unique<QAudioOutput>();
    bgmAudioOutput = std::make_unique<QAudioOutput>();
}
void Audio::quit(){
    SoundCache.clear();
}
void Audio::play(const QString &filename, bool superpose){
    if (!SoundCache.contains(filename)) {
        Sound* ptr = new Sound(filename);
        ptr->setAudioOutput(audioOutput.get());
        SoundCache.insert(filename, ptr);
    }
    Sound* sound = SoundCache[filename];
    Q_ASSERT(sound);
    if (!superpose && sound->isPlaying())
        return;
    sound->play();
}
void Audio::stop(){
    foreach (QString filename, SoundCache.keys()) {
        Sound *sound = SoundCache[filename];
        if (sound != NULL && sound->isPlaying()) {
            sound->stop();
        }
    }
    stopBGM();
}
void Audio::playBGM(const QString &filename){
    BackgroundMusic = std::make_unique<Sound>(filename);
    BackgroundMusic->setAudioOutput(bgmAudioOutput.get());
    BackgroundMusic->play();
}
void Audio::setBGMVolume(float volume){
    bgmAudioOutput->setVolume(volume);
}
void Audio::stopBGM(){
    if (BackgroundMusic && BackgroundMusic->isPlaying())
        BackgroundMusic->stop();
}

#endif

