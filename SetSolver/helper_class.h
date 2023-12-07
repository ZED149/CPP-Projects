//
// Created by salman on 7/25/23.
//

#ifndef SET_SOLVER_HELPER_CLASS_H
#define SET_SOLVER_HELPER_CLASS_H

#include <string>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;

class helper_class
{
public:
    // this class contains functions to aid in SetSolver and to organize code

    // Count Compartment Size
    int count_compartment_size(const int &row, const int &col, const string &direction,const  int board[][9])
    {
        // direction can be two ways
        // 1. Horizontal
        // 2. Vertical

        // if direction is horizontal,
        // we need to place the cursor at the left most cell in the grid
        // and then calculate compartment size
        // means, increment the counter until it meet some value other than 99

        // checking the string
        if(direction == "horizontal")
        {
            // calculate the compartment size
            int compartment_size = 0;
            // this loop computes compartment size
            // considering that the row is always constant
            // we can only iterate on j
            for(int j=col; j<9; j++)
            {
                compartment_size++;     // otherwise keep counting size
                if(board[row][j] <= 0)  // indicates a black square [with or without number]
                    break;
            }
            // Return!
            return compartment_size;
        }
        else if(direction == "vertical")
        {
            // calculate the compartment size
            int compartment_size = 0;
            // this loop computes compartment size
            // considering that the col is always constant
            // we can only iterate on i
            for(int i=row; i<9; i++)
            {
                if(board[i][col] <= 0)  // indicates a black square [with or without number]
                    break;
                compartment_size++;     // otherwise keep counting size
            }
            // Return!
            return compartment_size;
        }
    }

    // solve
    void solve(const int &row, const int &col, int board[][9])
    {
        // this function will solve that 1 particular cell
        // creating a vector including all numbers
        vector<int> all_numbers = {1,2,3,4,5,6,7,8,9};
        vector<int> row_numbers = count_numbers_in_row(row, board, all_numbers);
        vector<int> col_numbers = count_numbers_in_col(col, board, all_numbers);
        vector<int> to_be_minus = merge_both_vectors(row_numbers, col_numbers);
        vector<int> final_vector = subtract(all_numbers, to_be_minus);

        // now final vector contains all possible numbers that can be placed
        // we need to check for top, right, bottom, left square --> clockwise movement
        // in order to decide which number to place
        // checking top
        int check = top(row, col, board, final_vector);
        if(check != -1)
        {
            board[row][col] = check;
            return;
        }
        // checking right
        check = right(row, col, board, final_vector);
        if(check != -1)
        {
            board[row][col] = check;
            return;
        }
        // checking bottom
        check = bottom(row, col, board, final_vector);
        if(check != -1)
        {
            board[row][col] = check;
            return;
        }
        // checking left
        check = left(row, col, board, final_vector);
        if(check != -1)
        {
            board[row][col] = check;
            return;
        }

        check = 0;
        if (check == 0)
        {
            std::sort(final_vector.begin(), final_vector.end());
            board[row][col] = final_vector[0];
            return ;

        }
    }

    // Check Top
    int top(const int &row, const int &col, int board[][9], const vector<int> &final_vector)
    {
        // check for if we already at 0'th row OR there is a black square above us OR there is an empty square above us
        if(row == 0 || board[row - 1][col] == 0 || board[row - 1][col] == 99)    // can't check top
            return -1;

        int storing_value = board[row - 1][col];
        if(exists(storing_value - 1, final_vector))
        {
            return storing_value - 1;
        }
        else if(exists(storing_value + 1, final_vector))
        {
            return storing_value + 1;
        }
        return -1;
    }

    // Check Right
    int right(const int&row, const int &col, int board[][9], const vector<int> &final_vector)
    {
        // check for if we already at last col OR there is a black square ahead us OR there is an empty square ahead us
        if(col == 8 || board[row][col + 1] == 0 || board[row][col + 1] == 99)    // can't check right
            return -1;

        int storing_value = board[row][col + 1];
        if(exists(storing_value - 1, final_vector))
        {
            return storing_value - 1;
        }
        else if(exists(storing_value + 1, final_vector))
        {
            return storing_value + 1;
        }
        return -1;
    }

    // Check Bottom
    int bottom(const int &row, const int &col, int board[][9], const vector<int> &final_vector)
    {
        // check for if we already at last row OR there is a black square below us OR there is an empty square below us
        if(row == 8 || board[row + 1][col] == 0 || board[row + 1][col] == 99)    // can't check bottom
            return -1;

        int storing_value = board[row + 1][col];
        if(exists(storing_value - 1, final_vector))
        {
            return storing_value - 1;
        }
        else if(exists(storing_value + 1, final_vector))
        {
            return storing_value + 1;
        }
        return -1;
    }

    // Checking Left
    int left(const int &row, const int &col, int board[][9], const vector<int> &final_vector)
    {
        // check for if we already at the 0th col OR there is a black behind below us OR there is an empty square behind us
        if(col == 0 || board[row][col - 1] == 0 || board[row][col - 1] == 99)    // can't check left
            return -1;

        int storing_value = board[row][col - 1];
        if(exists(storing_value - 1, final_vector))
        {
            return storing_value - 1;
        }
        else if(exists(storing_value + 1, final_vector))
        {
            return storing_value + 1;
        }
        return -1;
    }

    void remove(vector<int> &x, const int value)
    {
        auto itr = x.begin();
        while(itr != x.end())
        {
            if(*itr == value)
            {
                x.erase(itr);
                break;
            }
            itr++;
        }
    }

    vector<int> subtract(const vector<int> &all_numbers, const vector<int> &to_be_minus)
    {
        vector<int> temp = all_numbers;
        for(int i=0; i<to_be_minus.size(); i++)
        {
            if(exists(all_numbers, to_be_minus[i]))
                remove(temp, to_be_minus[i]);
        }
        return temp;
    }

    static bool exists(const int &value, const vector<int> &row_numbers)
    {
        bool flag = false;
        for(auto itr:row_numbers)
            if (itr == value)
            {
                flag = true;
                break;
            }
        return flag;
    }

    static bool exists(const vector<int> &row_numbers, int value)
    {
        bool flag = false;
        for(auto itr:row_numbers)
            if (itr == value)
            {
                flag = true;
                break;
            }
        return flag;
    }

    vector<int> merge_both_vectors(const vector<int> &row_numbers, const vector<int> &col_numbers)
    {
        // this function merges two vectors and eliminates duplicates from them
        vector<int> temp = row_numbers;
        for(int i=0; i<col_numbers.size(); i++)
        {
            if(!exists(row_numbers, col_numbers[i]))
            {
                // add
                temp.push_back(col_numbers[i]);
            }
        }
        return temp;
    }

    // check_in_row
    vector<int> count_numbers_in_row(const int &row, int board[][9], vector<int> &all_numbers)
    {
        // this function iterates on row and eliminates all values in vector that are in row
        // iterating on row
        vector<int> temp;
        for(int j=0; j<9; j++)
        {
            if(board[row][j] != 0 && board[row][j] != 99)    // cell is neither black nor empty
            {
                if(board[row][j] < 0)     // converting -ve numbers to +ve
                    temp.push_back((board[row][j] * -1));
                else
                    temp.push_back(board[row][j]);
                //board[row][j] *= -1;
            }
        }
        return temp;
    }

    // check_in_col
    vector<int> count_numbers_in_col(const int &col, int board[][9], vector<int> &all_numbers)
    {
        // this function iterates on col and eliminates all values in vector that are in col
        // iterating on col
        vector<int> temp;
        for(int i=0; i<9; i++)
        {
            if(board[i][col] != 0 && board[i][col] != 99)    // cell is neither black nor empty
            {
                if(board[i][col] < 0)     // converting -ve numbers to +ve
                    temp.push_back((board[i][col] * -1));
                else
                    temp.push_back(board[i][col]);
                //board[i][col] *= -1;
            }
        }
        return temp;
    }

    // Insertion Sort
    void insertionSort (vector<int> &data) {
        int i, j, tmp;

        for (i = 1; i < data.size(); i++) {
            j = i;
            tmp = data[i];
            while (j > 0 && tmp < data[j - 1]) {
                data[j] = data[j - 1];
                j--;
            }
            data[j] = tmp;
        }
    }

    // Display Board
    void DisplayBoard(const int board[][9])
    {
        std::cout << "     ";
        for(int i=0; i<9; i++)
            std::cout << i << "  ";
        std::cout << std::endl;

        for(int i=0; i<9; i++)
        {
            std::cout << i << "--> ";
            for(int j=0; j<9; j++)
            {
                std::cout << board[i][j] << ", ";
            }
            std::cout << std::endl;
        }
    }
};

#endif //SET_SOLVER_HELPER_CLASS_H