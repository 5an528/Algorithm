#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>g[100];
vector<int>g2[100];
queue<int>Q;

int d[100],col[100],f[100],time,m;
int d2[100],col2[100],f2[100],time2,arr[100];

void DFS_Visit(int u)
{
    col[u]=2;
    time=time+1;
    d[u]=time;
    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if(col[v]==1)
        {
            DFS_Visit(v);
        }
    }

    col[u]=3;
    time=time+1;
    f[u]=time;
    arr[m]=u;
    m++;
}
void DFS_Visit2(int u)
{
    col2[u]=2;
    time2=time2+1;
    d2[u]=time2;
    for(int i=0; i<g2[u].size(); i++)
    {
        int v = g2[u][i];
        cout<<v<<" -> ";
        if(col2[v]==1)
        {
            DFS_Visit2(v);
        }
    }

    col2[u]=3;
    time2=time2+1;
    f2[u]=time2;
}

void transpose(int a, int n)
{
    for(int j=0; j<g[a].size(); j++)
    {
        int v=g[a][j];
        g2[v].push_back(a);
    }
}
int main()
{
    int node,edge,u,v,source;

    cout<<"Input Node and Edge numbers :";
    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
    }

    for(int i=0; i<node; i++)
    {
        d[i]=-1;
        col[i]=1;
        f[i]=-1;
    }
    time=0;
    for(int i=0; i<node; i++)
    {
        if(col[i]==1)
        {
            DFS_Visit(i);
        }
    }

    cout<<"The Results are : "<<endl;
    for(int i=0; i<node; i++)
    {
        cout<<"Size of "<<i<<" is : "<<g[i].size()<<endl;
        cout<<i<<": ";
        for(int j=0; j<g[i].size(); j++)
            cout<<g[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=node-1; i>=0; i--)
    {
        int a=arr[i];
        transpose(a,node);
    }
    for(int i=0; i<node; i++)
    {
        cout<<"Size of "<<i<<" is : "<<g2[i].size()<<endl;
        cout<<i<<": ";
        for(int j=0; j<g2[i].size(); j++)
            cout<<g2[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0; i<node; i++)
    {
        d2[i]=-1;
        col2[i]=1;
        f2[i]=-1;
    }
    time2=0;
    for(int i=node-1; i>=0; i++)
    {
        if(col2[arr[i]]==1)
        {
            int b=arr[i];
            DFS_Visit2(b);
        }
    }
}



