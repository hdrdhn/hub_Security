#include "Tree.h"

/**
 * helper functions
 */
static string ToHex(const string& s, bool upper_case)
{
    ostringstream ret;

    for (char i : s)
    {
        int z = i & 0xff;
        ret << std::hex << std::setfill('0') << std::setw(2) << (upper_case ? std::uppercase : std::nouppercase) << z;
    }

    return ret.str();
}
static vector<string> split(const string& s, const string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;
    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        if (token.empty()) continue;
        if (token.size() % 2 == 0)
            res.push_back(token);
        else
            res.push_back(token + "0");
    }

    res.push_back(s.substr(pos_start));
    return res;
}
static int stringToInt(const string& s)
{
    stringstream strStream(s);
    int num = 0;
    strStream >> num;
    return num;
}

/**
 * Tree functions
 * @param
 */
bool Tree::testSong(const Song& song) {
    NodeType res = DFS(root, song);
    if (res == SKIP_NODE)
        return false;
    return true;
}
void Tree::insert(Node* currNode, Node* newNode, int* flag) {
    if (root == nullptr)
    {
        root = newNode;
        *flag = 1;
        return;
    }
    if (currNode->left == nullptr && currNode->nodeType != SKIP_NODE && currNode->nodeType != PLAY_NODE) {
        currNode->left = newNode;
        *flag = 1;
        return;
    }
    if (currNode->right == nullptr && currNode->nodeType != SKIP_NODE && currNode->nodeType != PLAY_NODE) {
        currNode->right = newNode;
        *flag = 1;
        return;
    }
    if (currNode->left)
        insert(currNode->left, newNode, flag);
    if (currNode->right && !*flag)
        insert(currNode->right, newNode, flag);
}
std::string Tree::getFileContent(const string& input_file) {
    std::string tohexed;
    ifstream::pos_type size;
    char* memblock = nullptr;
    ifstream file(input_file, ios::in | ios::binary | ios::ate);
    if (file.is_open())
    {
        size = file.tellg();
        memblock = new char[size];
        file.seekg(0, ios::beg);
        file.read(memblock, size);
        file.close();
        tohexed = ToHex(std::string(memblock, size), true);
    }
    else
    {
        cout << "invalid test-file path" << endl;
        file.close();
        return "";
    }
    if (memblock != nullptr)
    {
        free(memblock);
        memblock = nullptr;
    }
    file.close();
    return tohexed;
}
Tree::Tree(const string& input_file) {
    string tohexed = getFileContent(input_file);
    if (tohexed.empty())
    {
        isValidTree = false;
        return;
    }
    CRC32 = tohexed.substr(0, 8);
    vector<string> v = split(tohexed.substr(10, tohexed.size() - 10), DELIMITER);

    int i = 0;
    while (i < v.size()) {
        Node* newNode = nullptr;
        int flag = 0;
        string type = v[i];
        i++;
        if (type == GENRE) {
            newNode = new GenreNode();
            int numOfGenres = stringToInt(v[i]);
            i++;
            for (int j = i; j < i + numOfGenres; ++j) {
                newNode->updateParam(v[j]);
            }
            i += numOfGenres;

        }
        else if (type == BPM) {
            newNode = new BPMNode();
            newNode->updateParam(v[i]);
            i++;

        }
        else if (type == LENGTH) {
            newNode = new LengthNode();
            newNode->updateParam(v[i]);
            i++;
        }

        else if (type == ARTIST) {
            newNode = new ArtistNode();
            int numOfArtists = stringToInt(v[i]);
            i++;
            for (int j = i; j < i + numOfArtists; ++j) {
                newNode->updateParam(v[j]);
            }
            i += numOfArtists;
        }

        else if (type == PLAY) {
            newNode = new PlayNode();
        }

        else if (type == SKIP) {
            newNode = new SkipNode();
        }
        else
        {
            i++;
            continue;
        }
        insert(root, newNode, &flag);
        i++;
    }
}
NodeType Tree::DFS(Node* currNode, const Song& song) {
    if (currNode->nodeType == SKIP_NODE || currNode->nodeType == PLAY_NODE)
        return currNode->nodeType;
    if ((currNode->nodeType == LENGTH_NODE && currNode->isValid(song.getLength())) || (currNode->nodeType == BPM_NODE && currNode->isValid(song.getBpmParam()))
        || (currNode->nodeType == ARTIST_NODE && currNode->isValid(song.getArtist())) || (currNode->nodeType == GENRE_NODE && currNode->isValid(song.getGenre())))
    {
        return DFS(currNode->left, song);
    }
    else {
        return DFS(currNode->right, song);
    }

}
Tree::~Tree() {
    delete root;
}
bool Tree::getIsValidTree() const {
    return isValidTree;
}
