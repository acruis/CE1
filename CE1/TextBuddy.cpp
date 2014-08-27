#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string ERROR_NO_FILENAME = "No filename specified! Usage: %s <FILENAME>";
const string WELCOME_MESSAGE = "Welcome to TextBuddy. %s is ready for use\n";
const string PROMPT_FOR_COMMAND = "command: ";

char buffer[255];

void printBuffer(string message = "") {
	if (message != "") {
		sprintf_s(buffer, message.c_str());
	}
	cout << buffer;
}

void checkFile(int argc, char* argv[]) {
	if (argc < 2) {
		sprintf_s(buffer, ERROR_NO_FILENAME.c_str(), argv[0]);
		printBuffer();
		exit(1);
	}
	else {
		sprintf_s(buffer, WELCOME_MESSAGE.c_str(), argv[0]);
		printBuffer();
	}
}

int main(int argc, char* argv[]) {
	
	checkFile(argc, argv);
	while (true) {
		printBuffer(PROMPT_FOR_COMMAND);
		string userCommand;
		getline(cin, userCommand);
		if (userCommand == "") exit(0);
		string result = "Command %s taken.\n";
		sprintf_s(buffer, result.c_str(), userCommand.c_str());
		printBuffer();
	}
	return 0;
}