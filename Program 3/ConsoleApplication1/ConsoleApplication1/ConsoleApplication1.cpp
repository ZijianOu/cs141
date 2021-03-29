/* Prog3Vigenere.cpp
 *     Encode/Decode using Vigenere cipher.
 */

#include <iostream>   // For Input and Output
#include <fstream>    // For file input and output
#include <cctype>     // Allows using the tolower() function
using namespace std;

// Global constants

void openDict(char storing[21735][81]) {
	// Open a file for reading
	ifstream inStream;             // declare an input stream 
	int numberOfWords = 0;             // Row for the current word
	inStream.open("dictionary.txt");
	if (!inStream.is_open()) {
		cout << "Could not find dictionary.txt.  Exiting..." << endl;
		exit(-1);
	}

	char theWord[81];    // declare input space to be clearly larger than largest word
	while (inStream >> theWord) {
	
		// Do something with the word that was read, such as store it, print it, etc.
		cout << theWord;
		if (strlen(theWord) >= 3) {
			for (int i = 0; i < strlen(theWord); i++) {
				theWord[i] = tolower(theWord[i]);
			}

		}
	}

	// close the file
	inStream.close();
}


//---------------------------------------------------------------------------
int main()
{
	// Declare variables
	int menuOption;                   // Userinput for menu option
	char returnCharacter;             // Separately store the return character so cin.getline does not consider it the next user input
	char Word;
	char storing[21735][81];
	openDict(storing);



	// Display menu and handle menu options
	cout << "21735 words of size >= 3 were read in from dictionary. \n"
		 << "Choose from the following options: \n"
		<< "    1. Lookup dictionary word \n"
		<< "    2. Encode some text  \n"
		<< "    3. Decode some text  \n"
		<< "    4. Auto-decode the ciphertext given with the assignment  \n"
		<< "    5. Exit program  \n"
		<< "Your choice: ";
	cin >> menuOption;
	returnCharacter = cin.get();  // Read and discard the return character at the end of the above input line.
								  // This is necessary because otherwise a subsequent cin.getline() reads it as
								  // an empty line of input.
	switch (menuOption) {
	case 1: // Do dictionary lookup of a word and indicate whether or not it was found.
		cout << "Enter a word to be looked up in dictionary: ";
		cin >> Word;


		break;

	case 2: // Encode some text
		cout << "Enter the text to be encoded: ";

		cout << "Enter a keyword for Vigenere encryption: ";

		cout << "Keyword, plainText and ciphertext are:  \n";

		break;

	case 3: // Decode using user-entered values
		cout << "Enter the cipherText to be decoded: ";

		cout << "Enter a Vigenere keyword to be tried: ";

		break;

	case 4: // Decode ciphertext given with the assignment
		cout << "Enter the cipherText to be decoded: ";

		break;

	case 5: // exit program
		cout << "Exiting program" << endl;
		exit(0);
		break;

	default:
		// Sanity check
		cout << "Invalid menu option.  Exiting program." << endl;
		break;
	}// end switch( menuOption)

	return 0;
}//end main()
