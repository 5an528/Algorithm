#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>g[100];
queue<int>Q;

int d[100],col[100],par[100],f[100],time,low[10],prev[100];

void DFS_Visit(int u)
{
    col[u]=2;
    time=time+1;
    d[u]=time;
    for(int i=0;i<g[u].size();i++)
    {
        int v = g[u][i];
        low[v]=d[u];
        if(col[v]==1)
        {
            prev[v]=u;
            cout<<u<<" and "<<v<<" is tree edge."<<endl;

            if(low[v]>=d[v])
                cout<<v<<" has an articulation point."<<endl;
            else if(low[v]<low[u])
                low[u]=low[v];
            DFS_Visit(v);

        }
        else if(col[v]==2)
        {
            cout<<u<<" and "<<v<<" is back edge."<<endl;
        }
        else if(col[v]==3)
        {
            if(d[u]<d[v])
                cout<<u<<" and "<<v<<" is forward edge."<<endl;
            if(d[v]<d[u])
                cout<<u<<" and "<<v<<" is cross edge."<<endl;
        }
    }

    col[u]=3;
    time=time+1;
    f[u]=time;
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

    for(int i=0;i<node;i++)
    {
        d[i]=-1;
        col[i]=1;
        par[i]=-1;
        f[i]=-1;
    }
    time=0;
    for(int i=0;i<node;i++)
    {
        if(col[i]==1)
        {
            DFS_Visit(i);
        }
    }

    cout<<"The Results are : "<<endl;
    cout<<"Node  Color  Discovery time   Finished Time"<<endl;
    for(int i=0;i<node;i++)
    {
        cout<<i<<"       "<<col[i]<<"             "<<d[i]<<"              "<<f[i]<<endl;
    }
}



