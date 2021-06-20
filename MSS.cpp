#include <iostream>

using namespace std;
int arr[100];

int sumarr[100];

void sumdata(int n)
{
    for(int i=1;i<=n;i++)
    {
        sumarr[i]=max(sumarr[i-1]+arr[i],arr[i]);
    }
}

int main()
{
    int n;
    cout<<"Enter how many number -> ";
    cin>>n;
    cout<<endl<<endl<<"Enter those numbers -> ";
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sumarr[i]=0;
    }
    sumarr[0]=0;
    sumdata(n);

    cout<<endl<<endl;

    int maxno=sumarr[1];
    for(int i=1;i<=n;i++)
    {
        if(maxno<sumarr[i])
        {
            maxno=sumarr[i];
        }
    }

    cout<<"Max sum is -> "<<maxno;
    cin>>n;



}

