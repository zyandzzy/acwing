//这个要用到取模与取余的知识
//在c++中%是取余（负数取余还是为负数），而在数学中是取余只能为正数
//为了让-A[i]%k>0,可以用（k-A[i]%k)%k，此时求得的就是数学中的取余的值
#include<iostream>
#include<cstring>

using namespace std;

typedef long long LL;

const int N = 100010;

int q[N],hp[11][N];

int n,k;


int main()
{
    cin>>n>>k;

    for(int i = 0;i<n;i++)
    cin>>q[i];

    for(int i = 0;i<n;i++)
      { 
        LL t = q[i]%k;

        for(int j = 0;j<11;j++)
        {             
           hp[j][t]++;

           t = t*10%k;
        }
      }
    LL ans = 0;
    for(int i = 0;i<n;i++)
    {  
       LL t = q[i]%k;
       int len = to_string(q[i]).size();
       ans+=hp[len][(k-t)%k];
       
       LL r = t;
       //判断是否重复
       while(len--) r = r*10%k;
       if(r == (k-t)%k) ans--;
    }
    cout<<ans;
}