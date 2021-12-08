
#include "Song.h"
const std::string& Song::getBpmParam() const {
    return bpmParam;
}
const std::string& Song::getLength() const {
    return length;

}
const std::string& Song::getGenre() const {
    return genre;
}
const std::string& Song::getArtist() const {
    return artist;
}
const std::string& Song::getTitle() const {
    return title;
}
Song::Song(std::string newTitle, std::string newArtist, std::string newGenre, std::string newLength, std::string newBPM) :
    title(std::move(newTitle)), artist(std::move(newArtist)), genre(std::move(newGenre)), length(std::move(newLength)), bpmParam(std::move(newBPM)) {}