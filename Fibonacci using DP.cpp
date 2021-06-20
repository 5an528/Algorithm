#include<iostream>

using namespace std;

int fibi[100];

int fib(int n)
{
    if(n==0)
    {
        fibi[n]=0;
        return 0;
    }

    else if(n==1)
    {
        fibi[n]=1;
        return 1;
    }
    else
    {
        if(fibi[n]!=-1)
            return fibi[n];
        else
            {
                fibi[n] = fib(n-1)+fib(n-2);
                return fibi[n];
            }
    }
}

int main()
{
    int number;

    cout<<"Enter your number -> ";
    cin>>number;
    for(int i=0; i<=number; i++)
        fibi[i]=-1;

    cout<<endl<<endl;


    cout<<"Result is -> "<<fib(number);
    cout<<endl<<endl;
    for(int i=0; i<=number; i++)
    {
        cout<<fibi[i]<<" ";
    }

}
