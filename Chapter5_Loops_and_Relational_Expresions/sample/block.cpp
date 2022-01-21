// block.cpp -- use a block statement
#include<iostream>
int main()
{
    using namespace std;
    // cout << "The Amazing Accounto will sum and average ";
    // cout << "five numbers for you.\n";
    // cout << "Please enter five values:\n";
    // double number;
    // double sum = 0.0;
    // // for (int i; i <= 5; i++)
    // // {                                    // block starts here
    // //     cout << "Value " << i << ": ";
    // //     cin >> number;
    // //     sum += number;
    // // }                                   // block ends here

    // for (int i; i <= 5; i++)                                    // block starts here
    //     cout << "Value " << i << ": ";
    //     cin >> number;
    //     sum += number;
      
    //                                  // block ends here
    // cout << "Five exquisite choices indeed! ";
    // cout << "They sum to " << sum << endl;
    // cout << "and average to " << sum / 5 << ".\n";
    // cout << "The Amazing Account bids you adieu!\n";

    int x = 20;
    { // block starts
        int y = 100;
        cout << x << endl; // ok
        cout << y << endl; // ok
    } // block ends
    cout << x << endl; // ok
    cout << y << endl; // invalid, won’t compile
    return 0;
}