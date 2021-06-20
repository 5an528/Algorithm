#include<iostream>

using namespace std;


int main()
{
    int node,edge,u,v,g[10][10]={0},c=0, j=0;

    cout<<"Input Node and Edge numbers :";
    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        cin>>u>>v;
        g[u][v]++;
        g[v][u]++;
        if(u==v)
            c++;
    }

    for(int i=0;i<node;i++)
    {
        for(int j=0;j<node;j++)
        {
            if(g[i][j]>1)
                c++;
        }
    }
    if(c>1)
        cout<<"Multi graph";
    else
        cout<<"Simple graph";




}


