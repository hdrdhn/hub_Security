
#ifndef HUB_SECURITY_TREE_H
#define HUB_SECURITY_TREE_H
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "Node.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <cstdio>
#include "Song.h"
#include "Node.h"
#define GENRE "47656E7265"
#define BPM "42504D"
#define LENGTH "4C656E677468"
#define ARTIST "417274697374"
#define PLAY "506C6179"
#define SKIP "536B6970"
#define DELIMITER "00"

class Tree {
private:
    Node* root = nullptr;
    string CRC32;
    void insert(Node* currNode, Node* newNode, int* flag);
    static std::string getFileContent(const string& input_file);
    NodeType DFS(Node* currNode, const Song& song);
    bool isValidTree = true;

public:
    bool getIsValidTree() const;
    bool testSong(const Song& song);
    explicit Tree(const string& input_file);
    ~Tree();
};


#endif//HUB_SECURITY_TREE_H
