#include <iostream>
#include <algorithm>
using namespace std;
int c=0;
int l[100];
int par=0;
int p[100]={-1};
int path[100];

void LIS(int number, int arr[])
{
    for(int i=1; i<=number; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j] && l[i]<l[j]+1)
            {
                c++;
                p[i]=j;
                par++;
            }
        }
        l[i]=c;
        path[i]=par;
        par=0;
        c=0;
    }
}

int main()
{
    int number,arr[100];

    cout<<"Enter the size of an Array -> ";
    cin>>number;

    cout<<endl<<endl<<"Enter the numbers -> ";
    for(int i=1; i<=number; i++)
        cin>>arr[i];
    arr[0]=0;
    cout<<"Set of numbers are -> ";
    for(int i=0; i<=number; i++)
        cout<<arr[i]<<" ";

    LIS(number,arr);
    cout<<endl<<endl<<"Longest path = "<<*std::max_element(path,path+number);

    cout<<endl<<endl<<"Set of parents are -> ";
    for(int i=0; i<=number; i++)
        cout<<p[i]<<" ";

    cout<<endl<<endl<<"Set of path are -> ";
    for(int i=0; i<=number; i++)
        cout<<path[i]<<" ";

    cout<<endl<<endl<<"Set of length are -> ";
    for(int i=0; i<=number; i++)
        cout<<l[i]<<" ";

    return 0;
}
