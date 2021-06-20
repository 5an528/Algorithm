#include<iostream>

using namespace std;

int main()
{
    int node,edge,u,v,adj[10][10];

    cout<<"Input Node and Edge numbers :";
    cin>>node>>edge;

    for(int i=0;i<edge;i++)
    {
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    for(int i=0;i<node;i++)
    {
        for(int j=0;j<node;j++)
        {
            if(adj[i][j]==1)
                cout<<1<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }

}
