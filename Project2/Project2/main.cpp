//  prog2Cuatro.cpp
//
//  Created 1/25/2020 by Dale Reed for CS 141 program 2.
//  System: Xcode on iMac
//
#include <iostream>   // for cin and cout
#include <iomanip>    // for setw()
#include <cctype>     // for toupper()
#include <string>
using namespace std;  // so that we don't need to preface every cin and cout with std::

// Global variables to represent the 16 board pieces and C++ strings representing
// the pieces that have not yet been played.  Since these are global they don't
// need to be passed as parameters to functions, and are shared over the entire program.
// Normally global variables will not be allowed.
char p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16;
string upperRowPiecesToPlay = "OO/CC  II/ZZ";
string lowerRowPiecesToPlay = "oo/cc  ii/zz";




//-------------------------------------------------------------------------------------
void displayInstructions()
{
	cout << "Welcome to the game of Cuatro, where you try to complete a set      \n"
		<< "of four pieces that are alike.  Players take turns making moves.    \n"
		<< "On each move your OPPONENT chooses the piece, then YOU get to       \n"
		<< "place it on the board.  If you create a set of four alike when      \n"
		<< "you place your piece, then you win!       \n"
		<< "\n"
		<< "A set of four alike can be completed by using four all upper (or all\n"
		<< "lower) case characters, four all vowels (or all consonants), or four\n"
		<< "all curved (or all straight-lined). Curved letters are 'O' and 'C'\n"
		<< "(upper or lower), and straight-line letters are 'I' and 'Z' (upper or\n"
		<< "lower). Groups of four can be created in a row, column, diagonal, or\n"
		<< "corner quadrant.\n"
		<< "\n"
		<< "When prompted for input you may also enter 'x' or 'X' to exit." << endl;
}// end displayInstructions()

void swap(int &x, int &y) {//switch turn to play piece and position
	int temp = x;
	x = y;
	y = temp;
}//end of swap

void displayBoard() {
	cout << endl << " ---------    Square #" << endl;
	cout << "|" << " " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << "|" << "  1" << "  2" << "  3" << "  4  " << endl;
	cout << "|" << " " << p5 << " " << p6 << " " << p7 << " " << p8 << " " << "|" << "  5" << "  6" << "  7" << "  8  " << endl;
	cout << "|" << " " << p9 << " " << p10 << " " << p11 << " " << p12 << " " << "|" << "  9" << " 10" << " 11" << " 12 " << endl;
	cout << "|" << " " << p13 << " " << p14 << " " << p15 << " " << p16 << " " << "|" << " 13" << " 14" << " 15" << " 16 " << endl;
	cout << " ---------" << endl;
	cout << "Pieces:     Curved Straight" << endl;
	cout << "      Upper: " << upperRowPiecesToPlay << endl;
	cout << "      Lower: " << lowerRowPiecesToPlay << endl;
	cout << "            Vowel/Consonant" << endl;
}
// You should have lots more functions here.
void makeMove(int position, char pieceToMove) {


	switch (position)//display chosen piece on the board
	{

	case 1:
		p1 = pieceToMove;
		break;
	case 2:
		p2 = pieceToMove;
		break;
	case 3:
		p3 = pieceToMove;
		break;
	case 4:
		p4 = pieceToMove;
		break;
	case 5:
		p5 = pieceToMove;
		break;
	case 6:
		p6 = pieceToMove;
		break;
	case 7:
		p7 = pieceToMove;
		break;
	case 8:
		p8 = pieceToMove;
		break;
	case 9:
		p9 = pieceToMove;
		break;
	case 10:
		p10 = pieceToMove;
		break;
	case 11:
		p11 = pieceToMove;
		break;
	case 12:
		p12 = pieceToMove;
		break;
	case 13:
		p13 = pieceToMove;
		break;
	case 14:
		p14 = pieceToMove;
		break;
	case 15:
		p15 = pieceToMove;
		break;
	case 16:
		p16 = pieceToMove;
		break;
	}
}
bool checkDot(int position) {
	//check if the position is avaliable

	 //char pieceToMove;
	switch (position)
	{

	case 1:
		return p1 == '.';
		break;
	case 2:
		return p2 == '.';
		break;
	case 3:
		return p3 == '.';
		break;
	case 4:
		return p4 == '.';
		break;
	case 5:
		return p5 == '.';
		break;
	case 6:
		return p6 == '.';
		break;
	case 7:
		return p7 == '.';
		break;
	case 8:
		return p8 == '.';
		break;
	case 9:
		return p9 == '.';
		break;
	case 10:
		return p10 == '.';
		break;
	case 11:
		return p11 == '.';
		break;
	case 12:
		return p12 == '.';
		break;
	case 13:
		return p13 == '.';
		break;
	case 14:
		return p14 == '.';
		break;
	case 15:
		return p15 == '.';
		break;
	case 16:
		return p16 == '.';
		break;
	}
}

bool findString(char pieceToMove) { //switch used pieces to empty space
	if (upperRowPiecesToPlay.find(pieceToMove) < upperRowPiecesToPlay.length()) {
		upperRowPiecesToPlay[upperRowPiecesToPlay.find(pieceToMove)] = ' ';
		return true;
	}
	if (lowerRowPiecesToPlay.find(pieceToMove) < lowerRowPiecesToPlay.length()) {
		lowerRowPiecesToPlay[lowerRowPiecesToPlay.find(pieceToMove)] = ' ';
		return true;
	}
	return false;
}

void checkValid(int position, char pieceToMove, int &moveNumber, int& piecePlayer, int& positionPlayer) {
	//check if the position input is within the range, 
	// if so, then check if the position is avaliable, 
	// last, check if the chosen piece is valid
	if ((position >= 1) && (position <= 16)) {
		if (checkDot(position)) {

			if (findString(pieceToMove)) {
				makeMove(position, pieceToMove);
				moveNumber = moveNumber + 1;
				swap(piecePlayer, positionPlayer);
			}

			else {
				cout << " *** Sorry, that is an invalid piece.  Please retry.";
			}
		}

		else {
			cout << " *** Sorry, that destination is occupied.  Please retry.";
		}
	}
	else {
		cout << " *** Sorry, that destination is invalid.  Please retry.";
	}

}


 bool iscurved(char v1, char v2, char v3, char v4){
    return ((v1 == 'o')||(v1 == 'c')||(v1 == 'o')||(v1 == 'c'))&&
          ((v2 == 'o')||(v2 == 'c')||(v2 == 'o')||(v2 == 'c'))&&
          ((v3 == 'o')||(v3 == 'c')||(v3 == 'o')||(v3 == 'c'))&&
          ((v4 == 'o')||(v4 == 'c')||(v4 == 'o')||(v4 == 'c'));}

 bool isvowel(char v1, char v2, char v3, char v4){
    return ((v1 == 'o')||(v1 == 'i')||(v1 == 'o')||(v1 == 'i'))&&
          ((v2 == 'o')||(v2 == 'i')||(v2 == 'o')||(v2 == 'i'))&&
          ((v3 == 'o')||(v3 == 'i')||(v3 == 'o')||(v3 == 'i'))&&
          ((v4 == 'o')||(v4 == 'i')||(v4 == 'o')||(v4 == 'i'));}        

 bool isconsonant(char v1, char v2, char v3, char v4){
    return ((v1 == 'c')||(v1 == 'c')||(v1 == 'z')||(v1 == 'z'))&&
          ((v2 == 'c')||(v2 == 'c')||(v2 == 'z')||(v2 == 'z'))&&
          ((v3 == 'c')||(v3 == 'c')||(v3 == 'z')||(v3 == 'z'))&&
          ((v4 == 'c')||(v4 == 'c')||(v4 == 'z')||(v4 == 'z'));}

 bool isstraight(char v1, char v2, char v3, char v4){
    return ((v1 == 'i')||(v1 == 'z')||(v1 == 'i')||(v1 == 'z'))&&
          ((v2 == 'i')||(v2 == 'z')||(v2 == 'i')||(v2 == 'z'))&&
          ((v3 == 'i')||(v3 == 'z')||(v3 == 'i')||(v3 == 'z'))&&
          ((v4 == 'i')||(v4 == 'z')||(v4 == 'i')||(v4 == 'z'));}

 bool isupper(char v1, char v2, char v3, char v4){
    return ((v1 == 'o')||(v1 == 'c')||(v1 == 'i')||(v1 == 'z'))&&
          ((v2 == 'o')||(v2 == 'c')||(v2 == 'i')||(v2 == 'z'))&&
          ((v3 == 'o')||(v3 == 'c')||(v3 == 'i')||(v3 == 'z'))&&
          ((v4 == 'o')||(v4 == 'c')||(v4 == 'i')||(v4 == 'z'));}

 bool islower(char v1, char v2, char v3, char v4){
    return ((v1 == 'o')||(v1 == 'c')||(v1 == 'i')||(v1 == 'z'))&&
          ((v2 == 'o')||(v2 == 'c')||(v2 == 'i')||(v2 == 'z'))&&
          ((v3 == 'o')||(v3 == 'c')||(v3 == 'i')||(v3 == 'z'))&&
          ((v4 == 'o')||(v4 == 'c')||(v4 == 'i')||(v4 == 'z'));}

bool checkUpper(char v1, char v2, char v3, char v4){
	if ((isupper(v1) && isupper(v2) && isupper(v3) && isupper(v4))){
		return true;}
	else{
		return false;
	}
}
bool checkLower(char v1, char v2, char v3, char v4){
	if ((islower(v1) && islower(v2) && islower(v3) && islower(v4))){
		return true;}
	else {
		return false;
	}
}
	
bool checkStraight(char v1, char v2, char v3, char v4){
	if ((isstraight(v1) && isstraight(v2) && isstraight(v3) && isstraight(v4))){
		return true;}
	else {
		return false;
	}
}
bool checkCurved(char v1, char v2, char v3, char v4) {
	if ((iscurved(v1) && iscurved(v2) && iscurved(v3) && iscurved(v4))) {
		return true;
	}
	else {
		return false;
	}
}
bool checkVowel(char v1, char v2, char v3, char v4) {
	if ((isvowel(v1) && isvowel(v2) && isvowel(v3) && isvowel(v4))) {
		return true;
	}
	else {
		return false;
	}
}
bool checkConsonant(char v1, char v2, char v3, char v4) {
	if ((isconsonant(v1) && isconsonant(v2) && isconsonant(v3) && isconsonant(v4))) {
		return true;
	}
	else {
		return false;
	}
}
//-------------------------------------------------------------------------------------
int main()
{
	p1 = p2 = p3 = p4 = p5 = p6 = p7 = p8 = p9 = p10 = p11 = p12 = p13 = p14 = p15 = p16 = '.';// Declare and initialize variables

	displayInstructions();
	displayBoard();
	int moveNumber = 1;
	int piecePlayer = 1;
	int positionPlayer = 2;
	char pieceToMove;
	int position;
	// 	checkValid( position,  pieceToMove,  moveNumber ,  piecePlayer ,  positionPlayer );


		// Your main game-playing loop should go here.
	while (moveNumber <= 16) {      // if winning condition not found the game stops after 16 moves
	//Player 1 enter piece, and Player 2 enter destination:


		cout << moveNumber << ". Player " << piecePlayer << " enter piece, and Player " << positionPlayer << " enter destination:";
		cin >> pieceToMove;
		if ((pieceToMove == 'X') || (pieceToMove == 'x')) {
			cout << " Exiting program..." << endl;
			break;
		}

		cin >> position;
		checkValid(position, pieceToMove, moveNumber, piecePlayer, positionPlayer);

		//cout << upperRowPiecesToPlay.find(pieceToMove) << endl;
		//cout << lowerRowPiecesToPlay.find(pieceToMove) << endl << endl;

	   // Prompt for and get move.
//        cin >> position;       // the position at which the move is made
// 		if (findString(pieceToMove) != true) {
// 			cout << " *** Sorry, that is an invalid piece.  Please retry.";
// 		}
// 		else if ((position < 1) || (position > 16)) {
// 			cout << " *** Sorry, that destination is invalid.  Please retry.";
// 		}

// 		else {
// 			makeMove(position, pieceToMove);
// 			moveNumber = moveNumber + 1;
// 			swap(piecePlayer, positionPlayer);
// 		}
		displayBoard();
		// make the move to place teh character on the board
	 //checkBoard();      //checks the board for winning condition
	}
}



//return 0;
//} // end main()


//return 0;
//} // end main()
