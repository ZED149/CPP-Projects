//“The work I submitted represents my own effort and that I have implemented the code
//entirely on my own and I have not copied any line from anyone or anywhere. If I have, a
//comment was added to denote the source of that line or lines.//



#ifndef SetSolver_h
#define SetSolver_h

#include <string>
#include <iostream>
#include <vector>



using std::vector;
using std::string;
//You can add another .h class to help you create a data structure of your choosing.
#include "helper_class.h"

class SetSolver
{
private:
    int boardSize = 9;  // size of board, always = 9
    int board[9][9];    // this contains the board
    helper_class help;

public:

    // PopulateBoard
    void PopulateBoard(vector<string>skeletonBoard)
    {
        // implement your code here
        // this function will populate board
        // skeletonBoard is a vector of strings that needs to be converted into a board of integers
        // initializing separate row and col indexes for board
        int board_row = 0;
        for(int i=0; i<boardSize; i++, board_row++)
        {
            for(int j=0, board_col = 0; j<skeletonBoard[i].size(); j++, board_col++)
            {
                // Following Rules to covert string board into integer board

                // If there is a negative number in string board
                if(skeletonBoard[i][j] == '-')
                {
                    // converting character into integer
                    board[board_row][board_col] = ((int)skeletonBoard[i][j+1] - 48);
                    // changing sign to -ve
                    board[board_row][board_col] *= -1;
                    //std::cout << board[board_row][board_col] << ", ";
                    //std::cout.flush();
                    j+=1;
                }
                    // If there is an * in string board
                else if(skeletonBoard[i][j] == '*')
                {
                    // then, it indicates an empty white square
                    // we need to place number 99 at that place
                    // placing 99
                    board[board_row][board_col] = 99;
                    //std::cout << board[board_row][board_col] << ", ";
                    //std::cout.flush();
                }
                else
                {
                    // convert as present in the string board
                    board[board_row][board_col] = (((int)skeletonBoard[i][j]) - 48);
                    //std::cout << board[board_row][board_col] << ", ";
                    //std::cout.flush();
                }
            }
            //std::cout << std::endl;
        }
    }

    int ReturnValue(size_t row, size_t col)
    {
        // implement your code here
        int temp = board[row][col];
        return temp;
    }

    void RemovePosibilities()
    {
        // implement your code here
        // this function works in such a way that it is always called 1 time after populating game board
        // its purpose is to remove all duplicates for a [black numbered square] as well as for
        // [white numbered square] to remove all the random, irregular, distorting possibilities in the game

        // logic starts here
        // iterate through whole grid and check all black and white squares with numbers
        // if a choice is found, remove it from that specific row and column
        // iterating through grid
        for(int i=0; i<boardSize; i++)
        {
            for(int j=0; j<boardSize; j++)
            {
                // if it's a black or white square with number
                bool black_square = (board[i][j] < 0);
                bool white_square_with_number = board[i][j] >= 1;
                bool white_square_with_number_ = board[i][j] <= 9;
                if(black_square || (white_square_with_number && white_square_with_number_))
                {
                    // we have found a cell, now iterate through its row and col and find whether that number exist or not
                    // if exists, remove it
                    // i == row
                    // j == col
                    // first check in that row
                    // storing number to verify
                    int guilty_integer = board[i][j];
                    // if it's a black square, convert its sign to +ve
                    if(black_square)
                        guilty_integer *= -1;
                    // also we need index, for not to remove at it
                    // storing index
                    int indexes_arr[2] = {i, j};
                    for(int k = 0; k < boardSize; k++)
                    {
                        // this loop iterate horizontally
                        // check: if number == matched number AND cell is not the same as found
                        if((board[i][k] == guilty_integer || board[i][k] == (guilty_integer *= -1)) && k != indexes_arr[1])
                        {
                            // assigning an empty white square to that cell
                            board[i][k] = 99;
                        }
                    }
                    // k<(boardSize%10)
                    for(int k = 0; k<boardSize; k++)
                    {
                        // this loop will iterate vertically
                        if((board[k][j] == guilty_integer || board[k][j] == (guilty_integer *= -1)) && k != indexes_arr[0])
                            // assigning an empty white square to that cell
                            board[k][j] = 99;
                    }
                }
            }
        }

    }

    vector<int> ReturnPosibilities(int row, int col)
    {
        // implement your code here
        // This function basically returns the all other numbers that are
        // present on that row of that specific cell as well as
        // numbers present on that col
        // it will return a vector of integers that contain all the possible numbers
        // creating a vector containing values from [0-9]
        vector<int> temp {1,2,3,4,5,6,7,8,9};
        vector<int> present_values;
        for(int i=0; i<boardSize; i++)
        {
            if((board[row][i] < 0) || (board[row][i] >= 1 && board[row][i] <= 9))
            {
                // it indicates there is a value present
                present_values.push_back(board[row][i]);
            }
        }

        for(int i=0; i<boardSize; i++)
        {
            if((board[i][col] < 0) || (board[i][col] >= 1 && board[i][col] <= 9))
            {
                // it indicates there is a value present
                present_values.push_back(board[i][col]);
            }
        }

        int i=0;
        while(i < present_values.size())
        {
            if(present_values[i] < 0)
                present_values[i] *= -1;
            i++;
        }

        // subtracting 2 vectors
        vector<int> result;

        help.insertionSort(temp);
        help.insertionSort(present_values);
        result = help.subtract(temp, present_values);

        return result;
    }

    void NearlyThere(int row, int col, string direction)
    {
        // implement your code here
        // first, we need to count the size of compartment in which we stand
        // counting compartment size
        int compartment_size = help.count_compartment_size(row, col, direction, board);

        // we know how much spaces we need to solve
        // now, we need to run loop < compartment_size based on direction
        if(direction == "horizontal")
        {
            for(int i=0; i<compartment_size; i++)
            {
                help.solve(row, col++, board);
            }
        }
        else if(direction == "vertical")
        {
            for(int i=0; i<compartment_size; i++)
            {
                if(board[row][col] == 99)
                {
                    help.solve(row++, col, board);
                }
            }
        }
    }

    void Solve()
    {
        // implement your code here
        for(int i=0; i<boardSize; i++)
            for(int j=0; j<boardSize; j++)
                if(board[i][j] == 99)
                    help.solve(i, j, board);
    }
};
#endif /* SetSolver_h */