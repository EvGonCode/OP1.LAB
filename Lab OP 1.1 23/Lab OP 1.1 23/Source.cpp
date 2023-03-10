#include "header.h"
using namespace std;


void createFile(string fileName) {
	fstream file;
	try {
		file.open(fileName + ".txt", ios::out);
		cout << "File with name " << fileName << " was succesfully created" << endl;
	}
	catch (exception e) {
		cout << "File was not created becouse exception " << e.what() << " happend";
	}

	cout << "Enter text to file, or Exit to stop:" << endl;
	cin.ignore();
	string str;
	while (true) {
		getline(cin, str);
		if (str == "Exit") {
			break;
		}
		file << str << endl;
	}

	file.close();
	cout << endl;
}

string replaceWord(string str, string word, int* globalCounter) {
	int counter = 0;
	while (true) {
		int i = str.find(word);
		if(i >= 0){
			++counter;
			int i = str.find(word);
			str.replace(i, word.length(), to_string(counter));
		}
		else { break; }
	}

	str += "{"s + word + "," + to_string(counter) + "}";
	*globalCounter += counter;
	return str;
}

void replaceAllWordsInFileAndCreateNew(string fileName, string specificWord) {
	int globalCounter = 0;
	fstream file;
	file.open(fileName + ".txt", ios::in);
	vector<string> fileText;
	string line;
	while (getline(file, line))
	{
		fileText.push_back(line);
	}
	file.close();
	for (int i = 0; i < fileText.size(); i++) {
		fileText[i] = replaceWord(fileText[i], specificWord, &globalCounter);
	}
	

	file.open(fileName + " changed" + ".txt", ios::out);
	for (int i = 0; i < fileText.size(); i++) {
		file << fileText[i] << endl;
	}

	file.close();

	file.open(fileName + " new" + ".txt", ios::out);
	for (int i = 0; i < fileText.size(); i++) {
		file << fileText[i] << endl;
	}
	file << to_string(globalCounter);

	file.close();
}

void printFile(string fileName) {
	fstream file;
	file.open(fileName + ".txt", ios::in);
	string line = "";
	while (getline(file, line))
	{
		cout << line << endl;
	}
	cout << endl;
}

void appAndDataToFile(string fileName) {
	fstream file;
	file.open(fileName + ".txt", ios::app);
	cout << "Enter text to file, or Exit to stop:" << endl;
	cin.ignore();
	string str;
	while (true) {
		getline(cin, str);
		if (str == "Exit") {
			break;
		}
		file << str << endl;
	}
	file.close();
	cout << endl;
}

void usingString() {
	string fileName = "";
	cout << "Enter file name: "; cin >> fileName; cout << endl;
	createFile(fileName);
	cout << "Created file: " << endl;
	printFile(fileName);

	string word = "";
	cout << "Enter specific word: "; cin >> word; cout << endl;

	replaceAllWordsInFileAndCreateNew(fileName, word);
	cout << "Changed file: " << endl;
	printFile(fileName + " changed");

	cout << "New file: " << endl;
	printFile(fileName + " new"); cout << endl;

	string str = "0";
	cout << "Do you want to add data to YOUR file? (1 - yes, 2 - no): "; cin >> str; cout << endl;

	while (str == "1") {
		appAndDataToFile(fileName);
		cout << "Updated start file: " << endl;
		printFile(fileName);

		replaceAllWordsInFileAndCreateNew(fileName, word);

		cout << "Updated changed file: " << endl;
		printFile(fileName + " changed");

		cout << "Udated new file: " << endl;
		printFile(fileName + " new"); cout << endl;

		cout << "Do you want to add data to YOUR file? (1 - yes, 2 - no): "; cin >> str; cout << endl;
	}
}