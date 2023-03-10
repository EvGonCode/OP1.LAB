#include "header2.h"

using namespace std;

void usingPointers() {
    const char* myFile = "Pointers file.txt";
    const char* myFileChanged = "Pointers file changed.txt";
    const char* myFileNew = "Pointers file new.txt";

    createFile(myFile);
    printf("Created file:\n");
    printFile(myFile);

    printf("Enter specific word: ");
    char str[100];
    gets_s(str);
    printf("\n");

    replaceAllSpecificWordsInFileAndCreateNew(myFile, myFileChanged, myFileNew, str);

    printf("Changed file:\n");
    printFile(myFileChanged);
    printf("\n");

    printf("New file:\n");
    printFile(myFileNew);
    printf("\n");
}

void replaceAllSpecificWordsInFileAndCreateNew(const char* startFileName, const char* changedFileName, 
                                               const char* newFileName  , char substr[]){
    FILE* file;
    FILE* changedFile;
    FILE* newFile;
    file = fopen(startFileName, "r");
    changedFile = fopen(changedFileName, "w");
    char c;
    int globalCounter = 0;


    
    char line[1200];
    int k = 0;
    c = fgetc(file);
    while (c != EOF)
    {
        if (c == '\n') {
            int i = 0;

            int string_length = (int)strlen(line);
            int substr_length = (int)strlen(substr);
            int counter = 0;
            while (i < string_length)
            {
                if (strstr(&line[i], substr) == &line[i])
                {
                    counter++;
                    char strC[100];
                    sprintf(strC, "%d", counter);
                    string_length -= substr_length;

                    for (int j = i; j < string_length; j++)
                        line[j] = line[j + substr_length];
                    char newLine[1200];
                    string_length += strlen(strC);
                    for (int j = 0; j < i; j++) {
                        newLine[j] = line[j];
                    }
                    for (int j = 0; j < strlen(strC); j++) {
                        newLine[j + i] = strC[j];
                    }
                    for (int j = i; j < string_length; j++) {
                        newLine[j + strlen(strC)] = line[j];
                    }
                    for (int j = 0; j < strlen(newLine); j++) {
                        line[j] = newLine[j];
                    }
                }
                else i++;
            }
            char strC[100];
            sprintf(strC, "%d", counter);
            globalCounter += counter;
            fprintf(changedFile, line);
            fprintf(changedFile, "{");
            fprintf(changedFile, substr);
            fprintf(changedFile, ",");
            fprintf(changedFile, strC);
            fprintf(changedFile, "}");
            fprintf(changedFile, "\n");
            strcpy(line, "");
            k = 0;
        }
        else {
            line[k] = c;
            k++;
        }
        c = fgetc(file);
    }
    fclose(changedFile);
    fclose(file);

    newFile = fopen(newFileName, "w");
    changedFile = fopen(changedFileName, "r");

    char g;


    
    g = fgetc(changedFile);
    while (c != EOF)
    {
        fprintf(newFile, (char*)g);
        g = fgetc(changedFile);
    }
    fclose(changedFile);

    char strGC[10];
    sprintf(strGC, "%d", globalCounter);
    fprintf(newFile, strGC);
    //printf("\nstrGC");
    fclose(newFile);
}


void createFile(const char* fileName) {
    FILE* file;
    file = fopen(fileName, "w");
    char line[1024];

    printf("Enter a value :\n");
    while (true) {
        gets_s(line);
        //scanf("%[^]", line);
        if (strcmp(line, "Exit") == 0) {
            break;
        }
        fprintf(file, line);
        fprintf(file, "\n");
    }
    fclose(file);
    printf("\n");
}

void printFile(const char* fileName) {
    FILE* file;
    file = fopen(fileName, "r");
    char c;


    // Read contents from file
    c = fgetc(file);
    while (c != EOF and c != NULL)
    {
        printf("%c", c);
        c = fgetc(file);
    }
    fclose(file);
    printf("\n");
}