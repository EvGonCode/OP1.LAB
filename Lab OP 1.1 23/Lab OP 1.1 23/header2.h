#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

void usingPointers();
void createFile(const char* fileName);
void printFile(const char* fileName);
void replaceAllSpecificWordsInFileAndCreateNew(const char* startFileName, const char* changedFileName,
    const char* newFileName, char substr[]);