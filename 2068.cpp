/*这个要用到取模与取余的知识
在c++中%是取余（负数取余还是为负数），而在数学中是取余只能为正数(相当于取模)
对于整型数a，b来说，取模运算或者求余运算的方法都是：
1.求整数商： c = [a/b];
2.计算模或者余数： r = a - c*b.
求模运算和求余运算在第一步不同: 取余运算在取c的值时，向0 方向舍入(fix()函数)；而取模运算在计算c的值时，向负无穷方向舍入(floor()函数)。
为了让-A[i]%k>0,可以用（k-A[i]%k)%k，此时求得的就是数学中的取余的值*/
/*思路为(aj*10^len(ai) * ai)%k = 0 令 t = aj*10^len(ai) 
化简为t%k = -ai%k
用哈希表储存每一个t%k的值，固定ai,然后循环遍历ai，每个循环中算出-ai%k也就是(k-ai%k)%k并与对应哈希表中每个t%k的值对比
如果相等就复合条件 ans++
最后还要去重 是因为i和j可能重复*/


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
       //判断是否重复,通过找出自身在对应哈希表中的值，与-ai%k对比，若相等，说明i==j,答案要-1;
     
       for(int i = 0;i < len;i++)
        r = r*10%k;
       
       if(r == (k-t)%k) ans--;
    }
    cout<<ans;
}