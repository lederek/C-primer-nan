// while.cpp -- introducing the while loop
#include<iostream>
const int ArSize = 20;
int main()
{
    using namespace std;
    char name[ArSize];
    cout << "You first name, please: ";
    cin >> name;
    cout << "Here is your name, verticalized adn ASCIIized:\n";
    int i = 0;                  // start at beginning of string
    while (name[i] !=  '\0')    // process to end of string
    {
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;                    // don't forget this step
    }
    return 0;
} 