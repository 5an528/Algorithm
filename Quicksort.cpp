#include <iostream>

using namespace std;

int A[100],arrsize;

int Partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p-1;
    int temp;
    for(int j=p;j<=r-1;j++)
    {
        if(A[j]<=x)
        {
            i++;
            temp = A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    temp = A[i+1];
    A[i+1]=A[r];
    A[r]=temp;
    return i+1;
}

void quicksort(int A[], int p, int r)
{
    if( p < r )
    {
        int q = Partition(A,p,r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}


int main()
{
    cout<<"Enter the size of an array -> ";
    cin>>arrsize;

    cout<<endl<<"Enter your values -> ";

    for(int i=0;i<arrsize;i++)
    {
        cin>>A[i];
    }


    quicksort(A,0,arrsize-1);

    for(int i=0;i<arrsize;i++)
        cout<<A[i]<<" ";
}
