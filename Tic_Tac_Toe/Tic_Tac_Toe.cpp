#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
char board_key[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
const string Nowplayer[] = { "Player_1","Player_2" };

void printboard() {
    cout << "\t\t" << board_key[6] << "|" << board_key[7] << "|" << board_key[8] << '\n';
    cout << "\t\t" << "-+-+-\n";
    cout << "\t\t" << board_key[3] << "|" << board_key[4] << "|" << board_key[5] << '\n';
    cout << "\t\t" << "-+-+-\n";
    cout << "\t\t" << board_key[0] << "|" << board_key[1] << "|" << board_key[2] << '\n';
}
void title() {
    cout << "---------Do you want to play a game?---------\n";
    cout << "-----------Welcome to Tic Tac Toe!-----------\n";
    cout << "---------Please use keyboard to play---------\n";
    cout << "   ---------------------------------------\n";
    cout << "      ---------------------------------\n\n";
    cout << "\tGame Start! Is your turn! " << Nowplayer[0] << endl;
    cout << "---------------------------------------------\n" << endl;
    printboard();
    cout << "---------------------------------------------\n" << endl;
}
void WinMessage(bool &i,bool &end) {   
    printboard();
    end = true;
    cout << "\t      Game Over! \n \t     " << Nowplayer[!i] << " Win!!\n\n ";
}
void PlayAgainOrNot(bool& end, int& count) {  //'&' is Call by reference & Call by address (Call by pointer)
    cout << "\tPlay again ? y or n ? ";
    char ch;
    cin >> ch;
    switch (ch)
    {
    case 'y':
        end = true,count = 0;
        fill_n(board_key, 9, ' ');
        break;
    case 'Y':
        end = true, count = 0;
        fill_n(board_key, 9, ' ');
        break;
    case 'n':
        count = 10;
        break;
    case 'N':
        count = 10;
        break;
    default:
        cout << "\nPlease keyin y or n !\n" << endl;
        PlayAgainOrNot(end,count);
        break;
    }
}

int main() {
    int count = 0, ch;
    bool i = false, end = false;
    char c = ' ';
    title();
    while (count < 10) {
       // if (_kbhit()) {     //When keyboard in
            ch = _getch();     //Get your keyin          
            if ((0 <= ch - 49 <= 8) && (board_key[ch - 49] == ' ')) {        //When keyin 1~9
                if (count % 2 == 0) {   // Input X
                    board_key[ch - 49] = 'X';
                    i = !i;
                }
                else {                 // Input O
                    board_key[ch - 49] = 'O';
                    i = !i;
                }
                count += 1;
            }
            if (count >= 5) {    //Determine winner
                if ((board_key[0] == board_key[1]) && (board_key[1] == board_key[2])) {
                    if (board_key[2] != ' ') {
                        WinMessage(i, end);
                        PlayAgainOrNot(end, count);
                    }
                }
                if ((board_key[3] == board_key[4]) && (board_key[4] == board_key[5])) {
                    if (board_key[5] != ' ') {
                        WinMessage(i, end);
                        PlayAgainOrNot(end, count);
                    }
                }
                if ((board_key[6] == board_key[7]) && (board_key[7] == board_key[8])) {
                    if (board_key[8] != ' ') {
                        WinMessage(i, end);
                        PlayAgainOrNot(end, count);
                    }
                }
                if ((board_key[6] == board_key[3]) && (board_key[3] == board_key[0])) {
                    if (board_key[0] != ' ') {
                        WinMessage(i, end);
                        PlayAgainOrNot(end, count);
                    }
                }
                if ((board_key[7] == board_key[4]) && (board_key[4] == board_key[1])) {
                    if (board_key[1] != ' ') {
                        WinMessage(i, end);
                        PlayAgainOrNot(end, count);
                    }
                }
                if ((board_key[8] == board_key[5]) && (board_key[5] == board_key[2])) {
                    if (board_key[2] != ' ') {
                        WinMessage(i, end);
                        PlayAgainOrNot(end, count);
                    }
                }
                if ((board_key[0] == board_key[4]) && (board_key[4] == board_key[8])) {
                    if (board_key[8] != ' ') {
                        WinMessage(i, end);
                        PlayAgainOrNot(end, count);
                    }
                }
                if ((board_key[6] == board_key[4]) && (board_key[4] == board_key[2])) {
                    if (board_key[2] != ' ') {
                        WinMessage(i, end);
                        PlayAgainOrNot(end, count);
                    }
                }
            }
            if (count < 9) {
                cout << "---------------------------------------------\n" << endl;
                printboard();
                cout << "\n\t Now is your turn!  " << Nowplayer[i] << " !! " << "\n\n";
                cout << "---------------------------------------------\n" << endl;
            }
            //}
        if (count == 9 && end == false) {   //Tic
            cout << "\tGame Over\n\tNo Winner!\n" << endl;
            end = true;
            PlayAgainOrNot(end, count);
        }
    }
    cout << "\nSee you next time!" << endl;
    system("pause");
}