#include <iostream>
#include "Test.h"
using namespace std;
#define TEST_FILE 1
#define SONGS_FILE 2

int main(int argc, char* argv[]) {
    if (argc != 3)
    {
        std::cout << "Invalid number of parameters. please insert <test-file> full path and <songs-file> full path." << endl;
        return 1;
    }
    Test* test = new Test(argv[TEST_FILE], argv[SONGS_FILE]);
    test->doTest();
    delete test;
}




