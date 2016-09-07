#include <iostream>
#include <string>

#include "Algorithm.h"
#include "TestHash.h"

using namespace std;

void BruteForce(char *letters, char mid, myHash p)
{
    string check;
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            for(int u=0; u<6; u++)
            {
                for(int o=0; o<6; o++)
                {
                    for(int r=0; r<5; r++)
                    {
                        check={letters[u],letters[j],letters[i],letters[o]};
                        check.insert(check.begin()+r, mid);
                        if(p.Return(check)>0)
                        {
                            cout<<check<<"\n";
                        }
                        for(int b=0; b<5; b++)
                        {
                            check.insert(check.begin()+b, mid);
                            if(p.Return(check)>0)
                            {
                                cout<<check<<"\n";

                            }
                        }
                    }
                }
            }
        }
    }


    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            for(int u=0; u<6; u++)
            {
                for(int o=0; o<6; o++)
                {
                    for(int z=0; z<6; z++)
                    {
                        for(int r=0; r<6; r++)
                        {
                            check={letters[u],letters[j],letters[i],letters[o],letters[z]};
                            check.insert(check.begin()+r, mid);
                            if(p.Return(check)>0)
                            {
                                cout<<check<<"\n";
                            }
                            for(int b=0; b<5; b++)
                            {
                                check.insert(check.begin()+b, mid);
                                if(p.Return(check)>0)
                                {
                                cout<<check<<"\n";
                                }
                            }
                        }

                    }
                }

            }
        }
    }


    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            for(int u=0; u<6; u++)
            {
                for(int o=0; o<6; o++)
                {
                    for(int z=0; z<6; z++)
                    {
                        for(int y=0; y<6;y++)
                        {
                            for(int r=0; r<7; r++)
                            {
                                check={mid,letters[u],letters[j],letters[i],letters[o],letters[z],letters[y]};
                                check.insert(check.begin()+r, mid);
                                if(p.Return(check)>0)
                                {
                                    cout<<check<<"\n";
                                }
                                for(int b=0; b<5; b++)
                                {
                                    check.insert(check.begin()+b, mid);
                                    if(p.Return(check)>0)
                                    {
                                        cout<<check<<"\n";
                                    }
                                }
                            }
                        }
                    }

                }

            }
        }
    }



    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            for(int u=0; u<6; u++)
            {
                for(int o=0; o<6; o++)
                {
                    for(int z=0; z<6; z++)
                    {
                        for(int y=0; y<6;y++)
                        {
                            for(int h=0; h<6;h++)
                            {
                                for(int r=0; r<8; r++)
                                {
                                    check={letters[u],letters[j],letters[i],letters[o],letters[z],letters[y],letters[h]};
                                    check.insert(check.begin()+r, mid);
                                    if(p.Return(check)>0)
                                    {
                                        cout<<check<<"\n";
                                    }
                                    for(int b=0; b<5; b++)
                                    {
                                        check.insert(check.begin()+b, mid);
                                        if(p.Return(check)>0)
                                        {
                                            cout<<check<<"\n";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
