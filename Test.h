#ifndef HUB_SECURITY_TEST_H
#define HUB_SECURITY_TEST_H
#include <string>
#include "Tree.h"
using namespace std;
class Test {
private:
    string songsFilePath;
    string testFilePath;
    Tree* tree = nullptr;
    std::vector<string> play_songs_vec;

public:
    Test(string  testFilePath, string  songsFilePath);
    ~Test();
    void generatePlayList();
    void doTest();
};


#endif//HUB_SECURITY_TEST_H
