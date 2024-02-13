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
        audioOutput = std::make_unique<QAudioOutput>();
        this->setAudioOutput(audioOutput.get());
    }

    void setSource(const QString &filename)
    {
        if (filename.isEmpty()) {
            QMediaPlayer::setSource(QUrl());
        } else {
            QString AudioPrefix = QCoreApplication::applicationDirPath();
            this->path = QString("%1/%2").arg(AudioPrefix).arg(filename);
            QMediaPlayer::setSource(QFileInfo(filename).absoluteFilePath());
        }
    }
#if QT_VERSION < QT_VERSION_CHECK(6, 5, 0)
    bool isPlaying() const {
        return playbackState() == QMediaPlayer::PlaybackState::PlayingState;
    }
#endif
private:
    std::unique_ptr<QAudioOutput> audioOutput;
    QString path;
};

static QCache<QString, Sound> SoundCache;
static std::unique_ptr<Sound> BackgroundMusic;
static std::unique_ptr<QAudioOutput> bgmAudioOutput;

void Audio::init(){
    bgmAudioOutput = std::make_unique<QAudioOutput>();
}
void Audio::quit(){
    SoundCache.clear();
}
void Audio::play(const QString &filename, bool superpose){
    if (!SoundCache.contains(filename)) {
        Sound* ptr = new Sound(filename);
        SoundCache.insert(filename, ptr);
    }
    Sound* sound = SoundCache[filename];
    Q_ASSERT(sound);
    if (!superpose && sound->isPlaying())
        return;
    sound->stop();
    sound->play();
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

