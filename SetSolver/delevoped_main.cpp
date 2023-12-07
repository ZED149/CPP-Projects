//
//  main.cpp
//  PEP Resit 2023 C++ Number Set
//
//
//


#include <memory>
#include "SetSolver.h"



using std::cout;
using std::unique_ptr;

// print vector
void print_vector(const vector<int> &v)
{
    for(int i=0; i<v.size(); i++)
        cout << v[i] << ",";
    cout << "}\n";
}


//int main()
//{
    /*{
        //Task 1

        // creating a unique pointer named = board
        unique_ptr<SetSolver>board(new SetSolver());

        // now, creating a vector of strings named = skeletonBoard
        // this skeletonBoard contains board in string format
        // so, we need to pass it to Populate board to convert it into integer format
        vector<string>
                skeletonBoard{  "-6*300**00",
                                "41*30*8*6",
                                "**0**0***",
                                "***-2***70",
                                "0-9**6**00",
                                "0****0***",
                                "**804*06*",
                                "**9*-12***",
                                "00560-42*0"};

        board->PopulateBoard(skeletonBoard);

        vector<string> skeletonAnswer
                {
                        {-6,99,3,0,0,99,99,0,0},
                        {4,1,99,3,0,99,8,99,6},
                        {99,99,0,99,99,0,99,99,99},
                        {99,99,99,-2,99,99,99},
                        {0,-9,99,99,6,99,99,0,0},
                        {0,99,99,99,99,0,99,99,99},
                        {99,99,8,0,4,99,0,6,99},
                        {99,99,9,99,-1,2,99,99,99},
                        {0,0,5,6,0,-4,2,99,0}
                };

        for(size_t row=0;row<9;++row)
        {
            for (size_t col=0; col<9;++col)
            {
                if(board->ReturnValue(row, col) != skeletonAnswer[row][col])
                {
                    cout << "Failed: when checking row: "<<row<<" col: "<< col <<"\n";
                    return 1;
                }
            }
        }
    }*/
    /*{
        //Task 2
        unique_ptr<SetSolver>board(new SetSolver());

        vector<string>
                skeletonBoard{  "-6*300**00",
                                "41*30*8*6",
                                "99*0**0***",
                                "***-2***70",
                                "0-9**6**00",
                                "0***0***",
                                "**804*06*",
                                "**9*-12***",
                                "00560-42*0"};

        board->PopulateBoard(skeletonBoard);
        board->DisplayBoard();  // added by me
        board->RemovePosibilities();
        cout << "\n\nAfter Calling Remove Possibilities\n\n";
        board->DisplayBoard(); // added by me

        vector<int> temp = board->ReturnPosibilities(0,1);
        vector<int> correct {2,4,5,7,8};
        if (temp != correct)
        {
            cout << "Failed: was expecting 2,4,5,7,8 \n";
            return 1;
        }


    }*/
    /*{
        //task 3
        unique_ptr<SetSolver>board(new SetSolver());

        vector<string>
                skeletonBoard{      "00**0-31*0",
                                    "*****0**0",
                                    "7*003*-5**",
                                    "**05**7**",
                                    "*0**0*6-9*",
                                    "4***650**",
                                    "*2-8**00**",
                                    "-23*0*****",
                                    "043-608*0-1"};

        board->PopulateBoard(skeletonBoard);
        board->RemovePosibilities();
        cout << "First Board Displaying\n"; // remove, added by me
        board->DisplayBoard();  // remove, added by me

        board->NearlyThere(2, 5, "vertical");
        cout << "\nDisplaying board after calling Nearly There\n\n";
        board->DisplayBoard();
        vector<int> tempTop = board->ReturnPosibilities(2,5);
        vector<int> tempMid = board->ReturnPosibilities(3,5);
        vector<int> tempLow = board->ReturnPosibilities(4,5);

        vector<int> correctTop {2,4,6};
        vector<int> correctMid {2,4};
        vector<int> correctLow {2,4,7};

        if((tempTop != correctTop)||(tempMid != correctMid)||(tempLow!=correctLow))
        {
            cout << "MyTop {";
            print_vector(tempTop);
            cout << "MyMid {";
            print_vector(tempMid);
            cout << "MyLow {";
            print_vector(tempLow);
            cout << "Failed: was expecting : \n";
            cout << "correctTop {2,4,6} \n";
            cout << "correctMid {2,4} \n";
            cout << "correctLow {2,4,7} \n";
            return 1;
        }



    }*/
    /*{
        //Task 4

        unique_ptr<SetSolver>board(new SetSolver());

        vector<string>
                skeletonBoard{      "00**0-31*0",
                                    "*****0**0",
                                    "7*003*-5**",
                                    "**05**7**",
                                    "*0**0*6-9*",
                                    "4***650**",
                                    "*2-8**00**",
                                    "-23*0*****",
                                    "043-608*0-1"};

        board->PopulateBoard(skeletonBoard);
        std::cout << "\nDisplay Before Solve\n";
        board->DisplayBoard();
        board->Solve();
        std::cout << "Displaying After Solve\n\n";
        board->DisplayBoard();

        vector<string> skeletonAnswer
                {
                        {0,0,6,7,0,-3,1,2,0},
                        {6,7,5,8,4,0,2,3,0},
                        {7,8,0,0,3,4,-5,1,2},
                        {8,9,0,5,2,6,7,4,3},
                        {5,0,1,2,0,7,6,-9,4},
                        {4,1,2,3,6,5,0,8,7},
                        {3,2,-8,4,5,0,0,7,6},
                        {-2,3,4,0,7,9,8,6,5},
                        {0,4,3,-6,0,8,9,0,-1}
                };

        std::cout << "\nNow calling remove possibilities and will match output\n";
        board->RemovePosibilities();
        board->DisplayBoard();
        for(size_t row=0;row<9;++row)
        {
            for (size_t col=0; col<9;++col)
            {
                if((board->ReturnValue(row,col))!= (skeletonAnswer[row][col]))
                {
                    cout << "Failed: when checking row: "<<row<<" col: "<< col <<"\n";
                    return 1;
                }
            }
        }
    }*/
//}