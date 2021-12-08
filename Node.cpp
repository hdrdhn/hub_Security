#include "Node.h"
NodeType Node::getNodeType() const {
    return nodeType;
}

void Node::setNodeType(NodeType _nodeType) {
    Node::nodeType = _nodeType;
}
Node::~Node() = default;


void ListNode::updateParam(string param) {
    params.insert(param);
}
bool ListNode::isValid(string param) {
    stringstream st;
    for (const auto& item : param) {
        st << std::uppercase << hex << int(item);
    }
    string hexedParam = st.str();

    if (params.find(hexedParam) != params.end())
    {
        return true;
    }
    return false;
}
ListNode::~ListNode() = default;

void IntNode::updateParam(string param) {
    threshold = stoi(param, nullptr, 16);
}
bool IntNode::isValid(string param) {
    std::replace(param.begin(), param.end(), ':', '.'); // replace all 'x' to 'y'
    stringstream floatStream(param);
    float num = 0;
    floatStream >> num;
    if (num <= (float)threshold)
        return true;
    return false;

}
IntNode::~IntNode() = default;

BPMNode::BPMNode() {
    setNodeType(BPM_NODE);
}
void BPMNode::toStr() {
    cout << "BPMNode" << endl;
}
BPMNode::~BPMNode() {
    if (this->left)
        delete this->left;
    if (this->right)
        delete this->right;
}

LengthNode::LengthNode() {
    setNodeType(LENGTH_NODE);
}
void LengthNode::toStr() {
    cout << "LengthNode" << endl;
}
LengthNode::~LengthNode() {
    if (this->left)
        delete this->left;
    if (this->right)
        delete this->right;
}

GenreNode::GenreNode() {
    setNodeType(GENRE_NODE);
}
void GenreNode::toStr() {
    cout << "GenreNode" << endl;
}
GenreNode::~GenreNode() {
    if (this->left)
        delete this->left;
    if (this->right)
        delete this->right;
}

ArtistNode::ArtistNode() {
    setNodeType(ARTIST_NODE);
}
void ArtistNode::toStr() {
    cout << "ArtistNode" << endl;
}
ArtistNode::~ArtistNode() {
    if (this->left)
        delete this->left;
    if (this->right)
        delete this->right;
}

PlayNode::PlayNode() {
    setNodeType(PLAY_NODE);
}

bool PlayNode::isValid(string param) {
    return true;
}
bool SkipNode::isValid(string param) {
    return true;
}
void PlayNode::toStr() {
    cout << "PlayNode" << endl;
}
PlayNode::~PlayNode() = default;

SkipNode::SkipNode() {
    setNodeType(SKIP_NODE);

}
void SkipNode::toStr() {
    cout << "SkipNode" << endl;
}
SkipNode::~SkipNode() = default;
