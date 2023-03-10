#include "header.h"
#include "header2.h"

using namespace std;
int main(int argc, char const *argv[])
{
	if (argc != 3) {
		cout << "You must enter at least ONE argument!";
		return 0;
	}

	if (strcmp(argv[2], "FileStream") == 0) {
		usingString();
	}
	else if(strcmp(argv[2], "FilePointer") == 0) {
		usingPointers();
		//cout << "Not done yet!" << endl;
	}
	else {
		cout << "Wrong argument!";
	}
}