//首先猜测一下 打表找规律
/*#include<iostream>

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
}*/

//通过找规律或者裴蜀定理(p,q最大公约数为d。那么一定存在整数a,b,使a*p+b*q = d)
//如果两个数不互为质数，那么没有最大不能组成的数。（只要这个数不是他们最大公约数的倍数）
//可以得知 互质的两个数p,q存在不能组成的最大数且为p*q-p-q

#include<iostream>

using namespace std;

int main()
{
    int m,n;

    cin>>m>>n;

    cout<<m*n-m-n;
}