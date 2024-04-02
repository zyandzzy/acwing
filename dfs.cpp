#include<iostream>
#include<cstring>

using namespace std;

int n;

int a[99];

void dfs(int* arr,int i,int k)
{
   if(i>=n) 
   {
    for(int i = 0;i<k;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    return;
   }
   a[k++] = arr[i];
   dfs(arr,i+1,k);
   k--;
   dfs(arr,i+1,k);  
}

int main()
{
    int x[99];
    cin>>n;
    for(int i = 0;i<n;i++)
    cin>>x[i];
    
    dfs(x,0,0);
}