#include <iostream>
#include <string>
#include <fstream>

#include "TestHash.h"
#include "Algorithm.h"

int main()
{
    myHash p;

    ifstream text ("WordsNoAc.txt");
    string line;
    if(text.is_open())
    {
        while(text.good())
        {
            getline(text, line);

            p.Insert(line);
        }
        text.close();
    }
    else
    {
        cout<<"file is not open";
    }

    char* letters = new char[6];
    char mid;
    cout<<"Enter Middle Letter"<<"\n";
    cin>>mid;
    cout<<"Enter First Peripheral Letter"<<"\n";
    cin>>letters[0];
    cout<<"Enter Second Peripheral Letter"<<"\n";
    cin>>letters[1];
    cout<<"Enter Third Peripheral Letter"<<"\n";
    cin>>letters[2];
    cout<<"Enter Fourth Peripheral Letter"<<"\n";
    cin>>letters[3];
    cout<<"Enter Fifth Peripheral Letter"<<"\n";
    cin>>letters[4];
    cout<<"Enter Sixth Peripheral Letter"<<"\n";
    cin>>letters[5];

    BruteForce(letters, mid,p);
}
