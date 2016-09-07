#ifndef TESTHASH_H
#define TESTHASH_H

#include <iostream>
#include <string>

using namespace std;

class myHash
{
private:
    struct node
    {
        node(string);
        string val;
        node* colPntr;
        unsigned counter;
    };

public:
    myHash();
    ~myHash();

        myHash(myHash&);
        myHash& operator=(myHash&);

    void Insert(string);
    unsigned Return(string);
    unsigned GetCollisions();
    unsigned GetSize();

    node* hashArray;
private:
    void Init();
    unsigned HashFunction(string);
    void NodeErase(node*);

    unsigned theSize;
    unsigned theCapacity;
    unsigned collisions;
};

#endif // TESTHASH_H
