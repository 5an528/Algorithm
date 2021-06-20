#include<iostream>
#include<vector>
#include<queue>
#define inf 9999
using namespace std;

struct node
{
    int n;
    int weight;
} demo;

struct pq
{
    int dis;
    bool flag;
} Q[100];

int d[100],par[100],n,node,edge,u,v,w,source;
vector<struct node>g[100];

int mypop()
{
    int mini=99;
    int index;
    for(int i=0; i<n; i++)
    {
        if(mini>Q[i].dis && Q[i].flag)
        {
            mini=Q[i].dis;
            index=i;
        }
    }
    Q[index].flag=false;
    return index;
}

int isEmpty()
{
    int t=0;
        for(int i=0; i<n; i++)
        {
            if(Q[i].flag)
                {
                    t=1;
                    break;
                }

        }
        if(t==1)
            return true;
        else
            return false;

}
int main()
{
    cout<<"Input Node and Edge numbers :";
    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        cin>>u>>v>>w;
        demo.n=v;
        demo.weight=w;
        g[u].push_back(demo);
    }
    for(int i=0; i<node; i++)
    {
        Q[i].dis=inf;
        Q[i].flag=true;
        d[i]=inf;
        par[i]=inf;
    }

    cout<<"Enter Your Source Node : ";
    cin>>source;
    Q[source].dis=0;

    while(isEmpty!=false)
    {
        int f=mypop();
        for(int i=0;i<g[f].size();i++)
        {
            int b=g[f][i].n;
            if(d[b]>d[b]+g[f][i].weight)
            {
                Q[b].dis=d[b];
                par[b]=f;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<"Node "<<i<<" -> "<<Q[i].dis<<" -> "<<par[i];
        cout<<endl;
    }
}
