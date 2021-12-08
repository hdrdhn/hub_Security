#ifndef HUB_SECURITY_NODE_H
#define HUB_SECURITY_NODE_H
#include "string"
#include "unordered_set"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
enum NodeType { LENGTH_NODE, GENRE_NODE, ARTIST_NODE, BPM_NODE, PLAY_NODE, SKIP_NODE };

class Node {
public:
    Node* right = nullptr;
    Node* left = nullptr;
    NodeType nodeType;
    NodeType getNodeType() const;
    void setNodeType(NodeType nodeType);
    virtual void updateParam(string param) = 0;
    virtual bool isValid(string param) = 0;
    virtual void toStr() = 0;
    virtual ~Node();
};

class ListNode : public Node
{
private:
    unordered_set<string> params;
public:
    void updateParam(string param) override;
    bool isValid(string param) override;
    ~ListNode() override;
};

class IntNode : public Node
{
private:
    int threshold = 0;
public:
    void updateParam(string param) override;
    bool isValid(string param) override;
    ~IntNode() override;

};

class LengthNode : public IntNode
{
public:
    LengthNode();
    ~LengthNode() override;
    void toStr() override;
};
class BPMNode : public IntNode
{
public:
    ~BPMNode() override;
    BPMNode();
    void toStr() override;
};
class GenreNode : public ListNode
{
public:
    GenreNode();
    ~GenreNode() override;
    void toStr() override;
};

class ArtistNode : public ListNode
{
public:
    ArtistNode();
    ~ArtistNode() override;
    void toStr() override;
};

class PlayNode : public Node
{
public:
    PlayNode();
    void toStr() override;
    ~PlayNode() override;

private:
    void updateParam(string param) override {}
    bool isValid(string param) override;
};
class SkipNode : public Node
{
public:
    SkipNode();
    void toStr() override;
    ~SkipNode() override;
private:
    void updateParam(string param) override {}
    bool isValid(string param) override;
};

#endif//HUB_SECURITY_NODE_H
