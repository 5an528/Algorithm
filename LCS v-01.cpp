#include<iostream>
#include<string>

using namespace std;

int trace[100][100],c[100][100];
string x,y;

int print(int i,int j)
{
    if(i==0 || j==0)
        return 0;
    if(trace[i][j]==1)
    {
        print(i-1,j-1);
        cout<<" "<<x[i-1];
    }
    else if(trace[i][j]==2)
        print(i-1,j);
    else
        print(i,j-1);

}

int main()
{
    int lx,ly;

    cout<<"Enter Two Strings: "<<endl<<endl;
    cin>>x>>y;

    lx=x.length();
    ly=y.length();

    for(int i=0; i<=lx; i++)
    {
        c[i][0]=0;
    }
    for(int j=0; j<=ly; j++)
    {
        c[0][j]=0;
    }
    for(int i=1; i<=lx; i++)
    {
        for(int j=1; j<=ly; j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                trace[i][j]=1;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                trace[i][j]=2;
            }
            else
            {
                c[i][j]=c[i][j-1];
                trace[i][j]=3;
            }
        }
    }

    cout<<endl<<lx<<" "<<ly<<endl<<endl;

    cout<<"Length of common subsequence: "<< c[lx][ly]<<"\n\n";

    cout<<"The Sequence is: ";
    print(lx,ly);
    cout<<endl;


}
