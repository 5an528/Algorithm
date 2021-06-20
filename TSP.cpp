#include<iostream>

using namespace std;

int INF=99999;
int graph[10][10],n,complete[10],cost=0;


void in()
{
    cout<<"Enter the number of village:";
    cin>>n;
    cout<<"Enter the matrix:";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
            complete[i]=0;
        }
    }
    cout<<"the cost is: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" \n";

        for(int j=0;j<n;j++)
        {
            cout<<graph[i][j];
        }
        cout<<endl;
    }
}
int least(int c)
{
    int nc=999,kmin;
    for(int i=0;i<n;i++)
    {
        if(graph[c][i]!=0 && complete[i]==0)
        {
            if(graph[c][i]+graph[i][c]<INF)
            {
                INF=graph[i][0]+graph[c][i];
                kmin=graph[c][i];
                nc=i;
            }
        }
    }
    if(INF!=99999)
    {
        cost+=kmin;
    }
    return nc;

}
void mincost(int source)
{
    int ncity;
    complete[source]=1;
    cout<<source+1<<"--->";
    ncity=least(source);
    if(ncity=99999)
    {
        ncity=0;
        cout<<ncity+1;
        cost+=graph[source][ncity];

    }
    mincost(ncity);


}
int main()
{

    in();
    cout<<"\nThe path is:\n"<<endl;
    mincost(0);
    cout<<"\n\nMinimum cost is:"<<cost;
    return 0;
}
