#include "Test.h"
#include <iostream>
#include <vector>
#include <json/json.h>
#include <fstream>
#include <string>
#include <utility>

Test::Test(string  testFilePath, string  songsFilePath) :
    songsFilePath(std::move(songsFilePath)), testFilePath(std::move(testFilePath)) {}


void Test::generatePlayList() {
  std::ifstream file_input(songsFilePath);
    Json::Reader reader;
    Json::Value file;
    reader.parse(file_input, file);
    cout << "List of songs to play:" << endl;
    for (auto& item : file)
    {
        Song song(item["Title"].asString() , item["Artist"].asString(), item["Genre"].asString(),
            item["Length"].asString(), item["BPM"].asString());
        if (tree->testSong(song))
        {
            play_songs_vec.push_back(item["Title"].toStyledString());
            cout << item["Title"].toStyledString();
        }

    }
}
Test::~Test() {
    delete tree;
}
void Test::doTest() {
    this->tree = new Tree(testFilePath);
    if (!this->tree->getIsValidTree())
    {
        return;
    }
    generatePlayList();
}
