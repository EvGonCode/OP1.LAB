#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void createFile(string fileName);
string replaceWord(string str, string word, int* globalCounter);
void replaceAllWordsInFileAndCreateNew(string fileName, string specificWord);
void printFile(string fileName);
void usingString();