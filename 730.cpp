#include<iostream>

using namespace std;

const int N = 100010;

int q[N];
int n;

bool check(long x)
{
    for(int i = 0;i<n;i++)
    {
        x+=(x-q[i]);
        if(x<0) return false;
        else if(x>=1e5) return true;//如果此时不退出会爆int
    }
    return true;
 
}
int main()
{
    
    cin>>n;
    for(int i = 0;i<n;i++)
    cin>>q[i];
    
    long long l = 0,r = N;
    
    while(l<r)
    {
        long long mid = l+r>>1;
        if(check(mid)) r = mid;
        else l = mid+1;
       // cout<<l<<endl;
    }
    cout<<l;
}