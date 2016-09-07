#include <iostream>
#include <string>
#include <fstream>
#include "TestHash.h"

using namespace std;

//HASH TABLE
myHash::myHash()
{
    Init();
}

myHash::~myHash()
{
    for(int i=0;i<theCapacity; i++)
    {
        if(hashArray[i].colPntr)
        {
            node* nodePntr = hashArray[i].colPntr;
            NodeErase(hashArray[i].colPntr);
        }
    }
    delete hashArray;
}

myHash::myHash(myHash& other)
{
    Init();

    theSize=other.theSize;

    for(int i=0; i<theCapacity; i++)
    {
        hashArray[i]=other.hashArray[i];
    }
}

myHash& myHash::operator=(myHash& other)
{
    if(this != &other)
    {
        for(int i=0;i<theCapacity; i++)
        {
            if(hashArray[i].colPntr)
            {
                node* nodePntr = hashArray[i].colPntr;
                NodeErase(hashArray[i].colPntr);
            }
        }

        theSize=other.theSize;

        for(int i=0; i<theSize; i++)
        {
             hashArray[i]=other.hashArray[i];
        }
    }

    return *this;

}

myHash::node::node(string x = "")
{
    val.clear();
    val = x;
    counter = 0;
    colPntr = nullptr;
}

void myHash::Init()
{
    collisions = 0;
    theCapacity = 10000000;
    theSize = 0;
    hashArray = new node[theCapacity];

    for(int i=0; i<theCapacity; i++)
    {
        hashArray[i].val="";
    }
}

void myHash::Insert(string x)
{
    if(((int)x.front()-64)>0)
    {
        int theIndex = HashFunction(x);

        if(hashArray[theIndex].val.empty())//If there is no value in the node, we put the string there
        {
            hashArray[theIndex].val = x;
            hashArray[theIndex].counter++;
        }
        else if(hashArray[theIndex].val == x)//If the string is already there, we increment the word count
        {
            hashArray[theIndex].counter++;
        }
        else//Here we need to add linked nodes
        {
            if(!hashArray[theIndex].colPntr)//if the node is not pointing to another node we simply add another node with the desired string
            {
                hashArray[theIndex].colPntr = new node(x);
                collisions++;
            }
            else
            {
                bool done = false;
                node* nodePntr = hashArray[theIndex].colPntr;
                node* prevPntr= nullptr;
                while(!done)
                {
                    if(nodePntr->val == x)//if we have a duplicate string, we increase the counter
                    {
                        nodePntr->counter++;
                        done= true;
                    }
                    else if(!nodePntr->colPntr)//if the node does not point to another node, we add another node
                    {
                        prevPntr = nodePntr;
                        nodePntr = new node(x);
                        nodePntr->counter++;
                        prevPntr->colPntr = nodePntr;
                        done = true;
                    }
                    else//we continue the while loop, searching through the chain of nodes
                    {
                        prevPntr = nodePntr;
                        nodePntr=nodePntr->colPntr;
                    }
                    collisions++;

                }

            }
        }
        theSize++;
    }
}

unsigned myHash::Return(string x)
{
    int theIndex = HashFunction(x);
    if(hashArray[theIndex].val == x)
    {
        return hashArray[theIndex].counter;
    }
    else if(hashArray[theIndex].colPntr)
    {
        bool done = false;
        node* nodePntr = hashArray[theIndex].colPntr;
        node* prevPntr= nullptr;
        while(!done)
        {
            if(nodePntr->val == x)//we have found the string
            {
                return nodePntr->counter;
            }
            else if(!nodePntr->colPntr)//if the node does not point to another node, we did not find the string
            {
                return 0;
            }
            else//we continue the while loop, searching through the chain of nodes
            {
                prevPntr = nodePntr;
                nodePntr=nodePntr->colPntr;
            }

        }
    }
    else
    {
         return 0;
    }
}

unsigned myHash::GetSize()
{
    return theSize;
}

unsigned myHash::GetCollisions()
{
    return collisions;
}

unsigned myHash::HashFunction(string x)
{
    int theIndex = (theCapacity/53)*((int)x.front()-64);//We sort the hashArray into segments according to the first letters of the strings
    for(int i =0; i<x.size(); i++)//The following ensures that even words that start with the same char, are the same length and have the same chars ("crap" and "carp") are provided separate indexes
    {
        theIndex *= ((int)x.at(i));
        theIndex+=i;
    }
    theIndex %= theCapacity;

    return theIndex;
}

void myHash::NodeErase(node* x)
{
    if(x->colPntr)
    {
        NodeErase(x->colPntr);
        delete x;
    }
}

