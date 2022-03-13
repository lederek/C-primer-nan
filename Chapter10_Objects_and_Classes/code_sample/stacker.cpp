// stacker.cpp -- teseting the Stack class
#include<iostream>
#include<cctype>
#include"stack.h"

int main()
{
    using namespace std;
    Stack st;       // create an empty stack
    char ch;
    unsigned long po;
    cout << "please enter A to add a purchase order, \n"
         << "P to process a PO, or Q to quit.\n";

    while(cin >> ch&&toupper(ch) != 'Q')
    {
        while (cin.get() != '\n' )
        continue;
    if (!isalpha(ch))
    {
        cout << '\a';
        continue;
    }
    switch (ch)
    {
    case 'A':
    case 'a': cout << "Enter a PO member to add: ";
              cin >> po;
              if(st.isfull())
                cout << "stack already full\n";
              else
                st.push(po);
             break;

    case 'p':
    case 'P': if (st.isempty())
                cout << "stack already empty\n";
              else  
                {
                    st.pop(po);
                    cout << "PO #" << po << " poped\n";
                }
        break;
    }
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}