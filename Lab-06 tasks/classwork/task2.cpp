#include <iostream>
#include <string>

using namespace std;

class MediaFile {
protected:
    string path;
    double size;
public:
    MediaFile(string p, double s) : path(p), size(s) {}
    virtual ~MediaFile() {}
    virtual void play() { cout << "Playing media: " << path << "\n"; }
    virtual void stop() { cout << "Stopping media: " << path << "\n"; }
};

class VisualMedia : virtual public MediaFile {
protected:
    string resolution;
public:
    VisualMedia(string p, double s, string res) : MediaFile(p, s), resolution(res) {}
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;
public:
    AudioMedia(string p, double s, int rate) : MediaFile(p, s), sampleRate(rate) {}
};

class ImageFile : public VisualMedia {
public:
    ImageFile(string p, double s, string res) : MediaFile(p, s), VisualMedia(p, s, res) {}
    void show() { cout << "Displaying image: " << path << " with resolution " << resolution << "\n"; }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string p, double s, int rate) : MediaFile(p, s), AudioMedia(p, s, rate) {}
    void play() override { cout << "Playing audio: " << path << " at " << sampleRate << " Hz\n"; }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string p, double s, string res, int rate) 
        : MediaFile(p, s), VisualMedia(p, s, res), AudioMedia(p, s, rate) {}
    void play() override { cout << "Playing video: " << path << " at " << resolution << " and " << sampleRate << " Hz\n"; }
    void stop() override { cout << "Stopping video: " << path << "\n"; }
};

int main() {
    MediaFile* media[3];
    media[0] = new ImageFile("image.jpg", 2.5, "1920x1080");
    media[1] = new AudioFile("song.mp3", 5.0, 44100);
    media[2] = new VideoFile("movie.mp4", 700.0, "1280x720", 48000);
    
    for (int i = 0; i < 3; i++) {
        media[i]->play();
        media[i]->stop();
    }
    
    for (int i = 0; i < 3; i++) {
        delete media[i];
    }
    
    return 0;
}
