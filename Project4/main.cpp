#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
void openConst(vector<string> &storing){
    ifstream inStream;
    string theText;
    inStream.open("ConstitutionAndBillOfRights.txt");
    if (!inStream.is_open()){
        cout << "Could not find ConstitutionAndBillOfRights.txt.  Exiting..." << endl;
        exit(-1);
    }
    while(getline(inStream, theText)){
        if(theText.length() > 1){
            storing.push_back(theText);
        }
    }
    inStream.close();
}
void display() {
    cout << endl;
    cout << "Select from the following choices : \n"
         << "   W  Enter word or phrase to find, and display enclosing text \n"
         << "   P  Display previous text \n"
         << "   F  Display following text \n"
         << "   A  Display all occurrences of found word or phrase \n"
         << "   X  Exit program \n"
         << "Your choice: ";

}

int main() {
    char menuOption;
    char str1[2500], str2[50];
    int numLine = 0; //initialize line number
    int currentLine = 0; // initialize current line
    vector<string> storing;
    openConst( storing);
    string theText;
    string menu = ""; // initialize menu
    string storeText;
    char returnCharacter;
    ifstream inStream;
    inStream.open("ConstitutionAndBillOfRights.txt");
    if (!inStream.is_open()){
        cout << "Could not find ConstitutionAndBillOfRights.txt.  Exiting..." << endl;
        exit(-1);
    }

    string a;
    int line = 1;
    int num = 0;
    while (getline(inStream, a))
    {
        if (a.length() <= 1)
            continue;
        storing.push_back(a);
        num++;
    }
    numLine = num;

    inStream.close();
    cout << "Select from the following choices: \n"
            "   W  Enter word or phrase to find, and display enclosing text \n"
            "   X  Exit program \n"
            "Your choice: ";
    while(1) {

        cin >> menuOption;
        menuOption = toupper(menuOption);
        returnCharacter = getchar();
        switch (menuOption) {
            case 'X':
                cout << "Exiting program." << endl;
                exit(-1);
            case 'W':
                cout << "\nEnter word or phrase : ";
                cin.get();
                getline(cin, theText);
                transform(theText.begin(), theText.end(), theText.begin(), ::tolower);

                for (int i = 0; i < numLine; i++)
                {
                    string str1 = storing[i];
                    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
                    if (str1.find(theText) == string::npos) {
                        continue;
                    }
                    else {
                        printf("Line %d:\n", i);
                        cout << storing[i] << endl << endl;
                        currentLine = i;
                        break;
                    }
                }
                display();
        }
        if (menuOption == 'P') {

            if (currentLine == 0)
            {
                cout << "There is no previous file contents." << endl << endl;
            }
            else {
                currentLine = currentLine - 1;
                printf("Line %d:\n", currentLine);
                cout << storing[currentLine] << endl << endl;
            }

            display();
        }
        else if (menuOption == 'F') {
            if (currentLine == numLine - 1)
            {
                cout << "There is no following file contents." << endl << endl;
            }
            else {
                currentLine = currentLine + 1;
                printf("Line %d:\n", currentLine);
                cout << storing[currentLine] << endl << endl;
            }
            display();
        }
        else if (menuOption == 'A') {
            int temp = 0;
            for (int i = 0; i < numLine; i++)
            {
                string str1 = storing[i];
                transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
                if (str1.find(theText) == string::npos) {
                    continue;
                }
                else {
                    printf("Line %d:\n", i);
                    cout << storing[i] << endl << endl;
                    currentLine = i;
                    if (temp == 0) {
                        temp = 1;
                        currentLine = i;
                    }
                }
            }
            display();
        }


    }
    return 0;
}
