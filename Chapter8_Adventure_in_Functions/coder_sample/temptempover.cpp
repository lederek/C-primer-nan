// tempover.cpp -- template overloading
#include<iostream>

template <typename T>               // template A
void ShowArray(T arr[], int n);

template <typename T>               // template B
void ShowArray(T *arr[], int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    using namespace std;
    int things[6] = {13,31,103,301,310,130};
    struct debts mr_E[3] = 
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout",1800.0}
    };
    double * pd[3];

    // set pointers to the amount members of the structures in me_E
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;

    cout << "listing Mr.E's counts of things:\n";

    // things is an array of int
    ShowArray(things, 6);   // uses template A
    cout << "Listing Mr. E's counts of things:\n";
    // things is an array of double
    ShowArray(pd, 3);       // uses template B(more specialized)
}
