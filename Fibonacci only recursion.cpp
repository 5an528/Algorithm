#include<iostream>

using namespace std;
int f;

int fib(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
         f = fib(n-1)+fib(n-2);

    return f;
}

int main()
{
    int n;

    cin>>n;
    cout<<endl;
    cout<<fib(n);

}
