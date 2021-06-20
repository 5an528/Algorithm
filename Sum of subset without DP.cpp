#include<iostream>

using namespace std;

int number, snum, arr[100];

bool sub_set_problem(int snum, int arr[], int number)
{
    if(snum==0)
        return true;
    if (number==0 && snum!=0)
        return false;
    else
    {
        if(arr[number-1]>snum)
            return sub_set_problem(snum,arr,number-1);
        else
            return sub_set_problem(snum-arr[number-1],arr,number)||sub_set_problem(snum,arr,number-1);
    }
}
int main()
{
    cout<<"Enter the number of set -> ";
    cin>>number;

    cout<<endl<<endl<<"Enter the Selected number -> ";
    cin>>snum;

    cout<<endl<<endl<<"Enter the set's number -> ";
    for(int i=0;i<number;i++)
        cin>>arr[i];

    bool l=sub_set_problem(snum, arr, number);

    if(l==true)
        cout<<"Possible to make";
    else
        cout<<"Not possible to make";

}

