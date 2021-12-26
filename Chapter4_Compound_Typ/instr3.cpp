// instr3.cpp -- reading more than one word with get() & get ()
#include<iostream>
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    char name1[ArSize];
    char name2[ArSize];

    cout << "Enter your name: \n";
    cin.get(name, ArSize).get();        //reading string, newline
    cout << "Enter your favorite dessert: \n";
    cin.get(dessert, ArSize).get();
    cout << "I have some delicious " << dessert;
    cout << "for you, " << name << ".\n"; 
    cin.getline(name1,ArSize).getline(name2, ArSize);
    cout << name1 << name2 << endl;
    return 0;
}