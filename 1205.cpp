//首先猜测一下 打表找规律
#include<iostream>

using namespace std;

bool dfs(int i,int m,int n)
{
    if(i==0)  return true;

    if(i>=m&&dfs(i-m,m,n))  return true;
    if(i>=n&&dfs(i-n,m,n))  return true;

    return false;
}

int main()
{
   int m,n;

   cin>>m>>n;
   
   int res = 0;

   for(int i = 1;i<=1000;i++)
   {
    if(!dfs(i,m,n)) res = i;
   }

   cout<<res;
}