#ifndef HUB_SECURITY_SONG_H
#define HUB_SECURITY_SONG_H
#include <cstdio>
#include <string>
#include <utility>

class Song {
private:
    std::string          artist;
    std::string          genre;
    std::string          length;
    std::string          bpmParam;
    std::string          title;

public:
    const std::string& getTitle() const;
    const std::string& getArtist() const;
    const std::string& getGenre() const;
    const std::string& getLength() const;
    const std::string& getBpmParam() const;

public:
    Song(std::string newTitle, std::string newArtist, std::string newGenre, std::string newLength, std::string newBPM);
};


#endif//HUB_SECURITY_SONG_H
