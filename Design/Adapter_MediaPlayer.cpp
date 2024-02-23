#include <iostream>
#include <string>

// Target interface
class MediaPlayer {
public:
    virtual void play(std::string audioType, std::string fileName) = 0;
};

// Adaptee class
class AdvancedMediaPlayer {
public:
    virtual void playVlc(std::string fileName) = 0;
    virtual void playMp4(std::string fileName) = 0;
};

// Concrete implementation of Adaptee class
class VlcPlayer : public AdvancedMediaPlayer {
public:
    void playVlc(std::string fileName) override {
        std::cout << "Playing vlc file. Name: " << fileName << std::endl;
    }

    void playMp4(std::string fileName) override {
        // Do nothing
    }
};

// Concrete implementation of Adaptee class
class Mp4Player : public AdvancedMediaPlayer {
public:
    void playVlc(std::string fileName) override {
        // Do nothing
    }

    void playMp4(std::string fileName) override {
        std::cout << "Playing mp4 file. Name: " << fileName << std::endl;
    }
};

// Adapter class
class MediaAdapter : public MediaPlayer {
private:
    AdvancedMediaPlayer *advancedMusicPlayer;

public:
    MediaAdapter(std::string audioType) {
        if (audioType == "vlc") {
            advancedMusicPlayer = new VlcPlayer();
        } else if (audioType == "mp4") {
            advancedMusicPlayer = new Mp4Player();
        }
    }

    void play(std::string audioType, std::string fileName) override {
        if (audioType == "vlc") {
            advancedMusicPlayer->playVlc(fileName);
        } else if (audioType == "mp4") {
            advancedMusicPlayer->playMp4(fileName);
        }
    }
};

// Concrete implementation of Target interface
class AudioPlayer : public MediaPlayer {
private:
    MediaAdapter *mediaAdapter;

public:
    void play(std::string audioType, std::string fileName) override {
        // Inbuilt support to play mp3 music files
        if (audioType == "mp3") {
            std::cout << "Playing mp3 file. Name: " << fileName << std::endl;
        }
        // MediaAdapter is providing support to play other file formats
        else if (audioType == "vlc" || audioType == "mp4") {
            mediaAdapter = new MediaAdapter(audioType);
            mediaAdapter->play(audioType, fileName);
        } else {
            std::cout << "Invalid media. " << audioType << " format not supported" << std::endl;
        }
    }
};

int main() {
    AudioPlayer audioPlayer;

    audioPlayer.play("mp3", "beyond_the_horizon.mp3");
    audioPlayer.play("mp4", "alone.mp4");
    audioPlayer.play("vlc", "far_far_away.vlc");
    audioPlayer.play("avi", "mind_me.avi");

    return 0;
}
