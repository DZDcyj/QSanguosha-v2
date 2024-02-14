#ifndef _AUDIO_H
#define _AUDIO_H

#ifdef AUDIO_SUPPORT

class Audio
{
public:
    static void init();
    static void quit();

    static void play(const QString &filename, bool superpose = true);

    static void playBGM(const QString &filename);
    static void setBGMVolume(float volume);
    static void stopBGM();
};

#endif

#endif

