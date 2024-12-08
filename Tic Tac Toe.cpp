#include <iostream>
#include <string>

using namespace std;

int main()
{
    // game board
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    const char Player_X = 'X';
    const char Player_O = 'O';
    char Current_player = Player_X;
    int row = -1;
    int column = -1;
    char winner = ' ';
    bool tie = false;

    for (int i = 0; i < 9 && winner == ' '; i++) // Loop runs a maximum of 9 times or until there's a winner
    {
        // print game board
        cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        // Current player turn
        cout << "Current Player turn is " << Current_player << endl;

        // Turn
        while (true)
        {
            cout << "Enter the Row and Column you want to conquer (0-2): ";
            cin >> row >> column;

            // Error Handling
            if (row < 0 || row > 2 || column < 0 || column > 2)
            {
                cout << "Invalid Input! Try Again." << endl;
            }
            else if (board[row][column] != ' ')
            {
                cout << "Tile is full! Try Again." << endl;
            }
            else
            {
                break;
            }
            row = -1;
            column = -1;
            cin.clear();             // clear error log
            cin.ignore(10000, '\n'); // discard values
        }

        board[row][column] = Current_player;

        // Check for a winner
        for (int x = 0; x < 3; x++)
        {
            // Horizontal - row check
            if (board[x][0] != ' ' && board[x][0] == board[x][1] && board[x][1] == board[x][2])
            {
                winner = board[x][0];
                break;
            }

            // Vertical - column check
            if (board[0][x] != ' ' && board[0][x] == board[1][x] && board[1][x] == board[2][x])
            {
                winner = board[0][x];
                break;
            }
        }

        // Diagonal checks
        if (winner == ' ')
        {
            if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            {
                winner = board[0][0];
            }
            else if (board[0][2] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2])
            {
                winner = board[2][0];
            }
        }

        // If a winner is found, break the loop
        if (winner != ' ')
        {
            break;
        }

        // Switch players
        Current_player = (Current_player == Player_X) ? Player_O : Player_X;
    }

    // Display final board state
    cout << "   |   |   " << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "   |   |   " << endl;

    // Announce the result
    if (winner != ' ')
    {
        cout << "Winner is: " << winner << endl;
    }
    else
    {
        cout << "It is a Tie!" << endl;
    }

    cout<< "Enter any key to exit the program" <<endl;
    cin.ignore();
    cin.get();
    return 0;
}
