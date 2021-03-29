// Prog5Pentago.cpp
//     Play the two-player game of Pentago, trying to get 5 pieces in a row.
//
// Author: Dale Reed
// Program: #5, Pentago using classes
// 3/23/2020
//

#include <iostream>  // Needed to avoid compiler error for the exit() command
#include <cctype>    // For toupper()
using namespace std;


//-------------------------------------------------------------------------------------
void displayInstructions()
{
    cout << "\n"
         << "Play the two-player game of Pentago. Be the first to get 5 in a row. \n"
         << "                                                                 \n"
         << "Pentago is played on a 6 by 6 board, divided into four 3 by 3    \n"
         << "quadrants.  There are two players, X and O, who alternate turns. \n"
         << "The goal of each player is to get five of their pieces in a row, \n"
         << "either horizontally, vertically, or diagonally.                  \n"
         << "                                                                 \n"
         << "Players take turns placing one of their pieces into an empty     \n"
         << "space anywhere on the board, then choosing one of the four       \n"
         << "board quadrants to rotate 90 degrees left or right.              \n"
         << "                                                                 \n"
         << "If both players get five in a row at the same time, or the       \n"
         << "last move is played with no five in a row, the game is a tie.    \n"
         << "If a player makes five a row by placing a piece, there is no need\n"
         << "to rotate a quadrant and the player wins immediately.            \n"
         << "                                                                 \n"
         << "     Play online at:  https://perfect-pentago.net                \n"
         << "     Purchase at:     www.mindtwisterusa.com                     \n"
         << "                                                                 \n"
         << "For each move provide four inputs:                               \n"
         << "   row (A-F), column (1-6), quadrant (1-4), rotation direction (L or R) \n"
         << "For instance input of B32R places the next piece at B3 and then  \n"
         << "would rotate quadrant 2 (upper-right) to the right (clockwise).  \n"
         << "                                                                 \n"
         << "At any point enter 'x' to exit the program or 'i' to display instructions." << endl;
} // end displayInstructions()
class Board{
private:
    char pArray[36]; //array for the board
public:
    Board(){
        for(int i=0; i<36; i++){
            pArray[i]='.';  //ste the locations to dots
        }
    }
    char getpiece(int c){    //get position
        return pArray[c];
    }
    void setpiece(char a,int c, char Row, char columnPlay, char quadrant, char direction){
        pArray[c] = a;  //set the piece at the location
    }
    void displayBoard(){
        char column = 'A';        //the first row
        cout << endl;
        cout << "    1   2   3   4   5   6   \n"     //frame
             << "  1-----------------------2 \n";
        for (int i = 0; i<6; i++){
            cout << column << " |";              //building frame
            for (int j=0;j<6;j++){
                int pieceIndex = i * 6 + j;
                cout << " " << pArray[ pieceIndex];
                if ((pieceIndex - 2) % 6 == 0 || (pieceIndex + 1)%6 == 0){
                    cout << " |";             //middle bar
                }
                else
                    cout << "  ";
            }
            cout << " " << column++ << endl;
            if (column < 'G'){

                if (column == 'D')
                    cout << "  |-----------+-----------| \n";           // frame
                else
                    cout << "  |           |           | \n";
            }
        }
        cout << "  3-----------------------4  \n"
             << "    1   2   3   4   5   6    " << endl;
    }//frame
    int checkValid(char Row, char columnPlay, char quadrant, char direction,int &c, Board theBoard)
    {
        if (Row < 'A' || Row > 'F'){                         //check if the first input in within the range
            cout << "    *** Invalid move row.  Please retry." << endl;
            return 1;
        }
        if (columnPlay < '1' || columnPlay > '6'){          //check if the column input is in the range
            cout << "    *** Invalid move column.  Please retry."<< endl;
            return 1;
        }
        c = (Row - 'A') * 6 + (columnPlay -'1');
        if(theBoard.getpiece(c) != '.'){
            cout << "    *** That board location is already taken.  Please retry."<< endl;
            return 1;
        }
        if (quadrant < '1' || quadrant > '4'){               //check if the quadrant input is valid
            cout <<"    *** Selected quadrant is invalid.  Please retry. "<<endl;
            return 1;
        }
        if(direction != 'L' && direction != 'R'){               //check if rotation is valid
            cout<< "    *** Quadrant rotation direction is invalid.  Please retry. "<<endl;
            return 1;
        }
        return 0;
    }
    bool checkTie(){
        bool win = false;
        int counter = 0;
        while(counter < 38 ){
            if(pArray[counter] != '.'){  // count piece
                win = false;
                counter++;
                continue;
            }
            win = true;
            break;
        }
        if(win == true){
            return false;
        }
        else{
            cout << "*** No one has won.  Game is a tie." << endl;
            displayBoard();
            cout<<"Thanks for playing.  Exiting..."<<endl;
            exit(-1);
        }
    }
    void rotate(char quadrant,char direction) {
        int quad = quadrant - '0';      //2d array for quadrant
        int quadArray[5][8] ={ {-1,-1,-1,-1,-1,-1,-1,-1}, // row0
                               { 0, 1, 2, 8,14,13,12, 6}, // row1
                               { 3, 4, 5,11,17,16,15, 9}, // row2
                               {18,19,20,26,32,31,30,24}, // row3
                               {21,22,23,29,35,34,33,27}  // row4
        };
        int source, destination;
        int j;
        for (j=0;j<2;j++){
            if (direction == 'R'){ //R rotate
                source = quadArray[quad][7];   //store  index into source
                char lastOne = pArray[source]; // store the char in a variable
                for (int i=7;i>0;i--){ // to manipulate the indexes
                    source = quadArray[quad][i-1]; // going though every index
                    destination = quadArray[quad][i];   // going though every index
                    pArray[ destination] = pArray[source]; // Replacing the index
                }
                // replace the original piece spot with '.'
                destination = quadArray[quad][0];
                pArray[ destination] = lastOne;
            }
            if (direction == 'L'){            //L rotate
                char firstOne = pArray[quadArray[quad][0]];// store the char in a variable
                for (int i = 0;i<7;i++ ){ // to manipulate the indexes
                    destination = quadArray[quad][i]; // going though every index
                    source = quadArray[quad][i+1];  // going though every index
                    pArray[destination] = pArray[source];  // Replacing the index
                }
                destination = quadArray[quad][7];
                pArray[ destination] = firstOne;
            }
        }
    }
// Can write do all win conditions
// Rows, Col , Diagonals
    bool checkWin(char piece1) {
        bool win = false;

        //1   2   3   4   5   6
//      1-----------------------2
//    A | 0   1   2 | 3   4   5 | A
//      |           |           |
//    B | 6   7   8 | 9   10  11| B
//      |           |           |
//    C | 12  13  14| 15  16  17| C
//      |-----------+-----------|
//    D | 18  19  20| 21  22  23| D
//      |           |           |
//    E | 24  25  26| 27  28  29| E
//      |           |           |
//    F | 30  31  32| 33  34  35|  F
//      3-----------------------4
//        1   2   3   4   5   6
// check rows
        //check row 0 1 2 3 4
        if (pArray[0] == piece1 && pArray[1] == piece1 && pArray[2] == piece1 && pArray[3] == piece1 && pArray[4] == piece1){
            return true;
        }
        //check row 5 4 3 2 1
        if (pArray[5] == piece1 && pArray[4] == piece1 && pArray[3] == piece1 && pArray[2] == piece1 && pArray[1] == piece1){
            return true;
        }
        //check row 6 7 8 9 10
        if (pArray[6] == piece1 && pArray[7] == piece1 && pArray[8] == piece1 && pArray[9] == piece1 && pArray[10] == piece1){
            return true;
        }
        //check row 11 10 9 8 7
        if (pArray[11] == piece1 && pArray[10] == piece1 && pArray[9] == piece1 && pArray[8] == piece1 && pArray[7] == piece1){
            return true;
        }
        //check row 12 13 14 15 16
        if (pArray[12] == piece1 && pArray[13] == piece1 && pArray[14] == piece1 && pArray[15] == piece1 && pArray[16] == piece1){
            return true;
        }
        //check row 17 16 15 14 13
        if (pArray[17] == piece1 && pArray[16] == piece1 && pArray[15] == piece1 && pArray[14] == piece1 && pArray[13] == piece1){
            return true;
        }
        //check row 18 19 20 21 22
        if (pArray[18] == piece1 && pArray[19] == piece1 && pArray[20] == piece1 && pArray[21] == piece1 && pArray[22] == piece1){
            return true;
        }
        //check row 23 22 21 20 19
        if (pArray[23] == piece1 && pArray[22] == piece1 && pArray[21] == piece1 && pArray[20] == piece1 && pArray[19] == piece1){
            return true;
        }
        //check row 24 25 26 27 28
        if (pArray[24] == piece1 && pArray[25] == piece1 && pArray[26] == piece1 && pArray[27] == piece1 && pArray[28] == piece1){
            return true;
        }
        //check row 29 28 27 26 25
        if (pArray[29] == piece1 && pArray[28] == piece1 && pArray[27] == piece1 && pArray[26] == piece1 && pArray[25] == piece1){
            return true;
        }
        //check row 30 31 32 33 34
        if (pArray[30] == piece1 && pArray[31] == piece1 && pArray[32] == piece1 && pArray[33] == piece1 && pArray[34] == piece1){
            return true;
        }
        //check row 35 34 33 32 31
        if (pArray[35] == piece1 && pArray[34] == piece1 && pArray[33] == piece1 && pArray[32] == piece1 && pArray[31] == piece1){
            return true;
        }
//check columns
        //check column 6 12 18 24
        if (pArray[0] == piece1 && pArray[6] == piece1 && pArray[12] == piece1 && pArray[18] == piece1 && pArray[24] == piece1){
            return true;
        }
        //check column 12 18 24 30
        if (pArray[6] == piece1 && pArray[12] == piece1 && pArray[18] == piece1 && pArray[24] == piece1 && pArray[30] == piece1 ){
            return true;
        }
        //check column 1 7 13 19 25
        if (pArray[1] == piece1 && pArray[7] == piece1 && pArray[13] == piece1 && pArray[19] == piece1 && pArray[25] == piece1){
            return true;
        }
        //check column 7 13 19 25 31
        if (pArray[7] == piece1 && pArray[13] == piece1 && pArray[19] == piece1 && pArray[25] == piece1 && pArray[31] == piece1 ){
            return true;
        }
        //check column 2 8 14 20 26
        if (pArray[2] == piece1 && pArray[8] == piece1 && pArray[14] == piece1 && pArray[20] == piece1 && pArray[26] == piece1){
            return true;
        }
        //check column 8 14 20 26 32
        if (pArray[8] == piece1 && pArray[14] == piece1 && pArray[20] == piece1 && pArray[26] == piece1 && pArray[32] == piece1 ){
            return true;
        }
        //check column 3 9 15 21 27
        if (pArray[3] == piece1 && pArray[9] == piece1 && pArray[15] == piece1 && pArray[21] == piece1 && pArray[27] == piece1){
            return true;
        }
        //check column 9 15 21 27 33
        if (pArray[9] == piece1 && pArray[15] == piece1 && pArray[21] == piece1 && pArray[27] == piece1 && pArray[33] == piece1 ){
            return true;
        }
        //check column 4 10 16 22 28
        if (pArray[4] == piece1 && pArray[10] == piece1 && pArray[16] == piece1 && pArray[22] == piece1 && pArray[28] == piece1){
            return true;
        }
        //check column 10 16 22 28 34
        if (pArray[10] == piece1 && pArray[16] == piece1 && pArray[22] == piece1 && pArray[28] == piece1 && pArray[34] == piece1 ){
            return true;
        }
        //check column 5 11 17 23 29
        if (pArray[5] == piece1 && pArray[11] == piece1 && pArray[17] == piece1 && pArray[23] == piece1 && pArray[29] == piece1){
            return true;
        }
        //check column 11 17 23 29 35
        if (pArray[11] == piece1 && pArray[17] == piece1 && pArray[23] == piece1 && pArray[29] == piece1 && pArray[35] == piece1 ){
            return true;
        }
//check diagonal
        //check diagonal 6 13 20 27 34
        if (pArray[6] == piece1 && pArray[13] == piece1 && pArray[20] == piece1 && pArray[27] == piece1 && pArray[34] == piece1){
            return true;
        }
        //check diagonal 1 8 15 22 29
        if (pArray[1] == piece1 && pArray[8] == piece1 && pArray[15] == piece1 && pArray[22] == piece1 && pArray[29] == piece1){
            return true;
        }
        //check diagonal 0 7 14 21 28
        if (pArray[0] == piece1 && pArray[7] == piece1 && pArray[14] == piece1 && pArray[21] == piece1 && pArray[28] == piece1){
            return true;
        }
        //check diagonal 7 14 21 28 35
        if (pArray[7] == piece1 && pArray[14] == piece1 && pArray[21] == piece1 && pArray[28] == piece1 && pArray[35] == piece1){
            return true;
        }
        //check diagonal 4 9 14 19 24
        if (pArray[4] == piece1 && pArray[9] == piece1 && pArray[14] == piece1 && pArray[19] == piece1 && pArray[24] == piece1){
            return true;
        }
        //check diagonal 11 16 21 26 31
        if (pArray[11] == piece1 && pArray[16] == piece1 && pArray[21] == piece1 && pArray[26] == piece1 && pArray[31] == piece1){
            return true;
        }
        //check diagonal 5 10 15 20 25
        if (pArray[5] == piece1 && pArray[10] == piece1 && pArray[15] == piece1 && pArray[20] == piece1 && pArray[25] == piece1){
            return true;
        }
        //check diagonal 10 15 20 25 30
        if (pArray[10] == piece1 && pArray[15] == piece1 && pArray[20] == piece1 && pArray[25] == piece1 && pArray[30] == piece1){
            return true;
        }
        return false;
    }
};


//-------------------------------------------------------------------------------------
int main() {
    cout << "Welcome to Pentago, where you try to get 5 of your pieces in a line. \n"
         << "At any point enter 'x' to exit or 'i' for instructions." << endl;
    Board theBoard;            // Create the board as an instance of the Board class
    int moveNum = 1;
    char piece1 = 'X';
    char piece2 = 'O';
    char Row;
    int c;
    char columnPlay;
    char quadrant;
    char direction;
    Row = ' ';
    while(moveNum < 39) {
        if (theBoard.checkTie()==true){
        }
        theBoard.displayBoard();
        if (moveNum % 2==1){            //determine player
            piece1 = 'X';
        }
        else{
            piece1 = 'O';
        }
        cout << moveNum << ". Enter row, column, quadrant, direction for " << piece1 <<": ";
        cin >> Row;
        Row = toupper(Row);
        if(Row == 'I'){
            displayInstructions();
            continue;}
        else if (Row=='X'){
            cout << "Exiting program..." << endl;
            exit(-1);
        }
        cin >> columnPlay >> quadrant >> direction;
        direction = toupper(direction);
        if(theBoard.checkValid(Row, columnPlay, quadrant, direction , c,theBoard)){
            continue;
        }
        theBoard.setpiece(piece1,c, Row,  columnPlay, quadrant, direction);
        theBoard.rotate(quadrant, direction);
        if(theBoard.checkWin('X') && theBoard.checkWin('O')){
            cout <<  "   *** Both X and O have won.  Game is a tie." << endl;
            theBoard.displayBoard();
            break;
        }
        else if (theBoard.checkWin(piece1) == true){
            cout << "    *** "<< piece1 <<  " has won the game!" << endl;
            theBoard.displayBoard();
            break;
        }

        moveNum++;
    }
    cout << "Thanks for playing.  Exiting... " << endl;
    return 0;
} // end main()