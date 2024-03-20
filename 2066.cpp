#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    string arr;

    cin>>arr;

    for(int i = 0;i<arr.size();i++)
    {
        if(arr[i]<='0'||arr[i]>'9') 
        cout<<arr[i];
        else
        {
            while(arr[i]--&&arr[i]>='1')
            cout<<arr[i-1];
        }
    }
}