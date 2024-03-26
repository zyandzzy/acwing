/*#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;

int a[N],b[N],c[N];
long long sum;

int main()
{
    int n;

    cin>>n;

    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<n;i++) cin>>b[i];
    for(int i = 0;i<n;i++) cin>>c[i];

    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);

    for(int i = 0;i<n;i++)//B在中间，所以遍历每一个B，找到最后一个比B小的A，和第一个比B大的C
    {
        int l = 0,r = n-1;

        while(l<r)
        {
            int mid = l+r+1>>1;
            if(a[mid]<b[i]) l = mid;//找最后一个比B小的A,所以要在小于B的区间去找，是右端点
            else r = mid-1;
        }
        if(a[r]>=b[i]) r=-1;
        int x = r;

        l = 0,r = n-1;

        while(l<r)
        {
            int mid = l+r>>1;
            if(c[mid]>b[i]) r = mid;//找第一个比B大的C，在大于B的区间去找，是左端点
            else l = mid+1;
        }
        if(c[l]<=b[i]) l=n;
        int y = l;

        sum+=(long long)(x+1)*(n-y);
    }

    cout<<sum;
}*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5+10;
int num[3][N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 3; ++i) 
        for(int j = 1; j <= n; ++j) 
            scanf("%d", &num[i][j]);
    for(int i = 0; i < 3; ++i)
        sort(num[i]+1, num[i]+n+1);

    LL ans = 0;
    //枚举B，寻找A满足的个数以及C满足的个数相乘
    for(int i = 1; i <= n; ++i) {
        int key = num[1][i];
        //A中二分查找第一个小于key的数的下标
        int pos1 = lower_bound(num[0]+1, num[0]+n+1, key)-num[0]-1;//返回的是第一个大于等于key的值的地址，减去数组首地址，再减去一就是最后一个小于key的元素的下标
        //C中二分查找第一个大于key的数的下标
        int pos2 = upper_bound(num[2]+1, num[2]+n+1, key)-num[2];//返回的是第一个大于等于key的值的地址，减去数组首地址，就是第一个大于key的元素的下标
        if(pos1 >= 1 && pos2 <= n) {
            ans += (LL)pos1*(n-pos2+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}

//二分查找部分可以用双指针优化
/*
int a = 1,c = 1;
for(int i = 1;i<=n;i++)
{
    while(a<=n&&num[0][a]<num[1][i]) a++;
    while(c<=n&&num[2][c]<=num[1][i]) c++;
    ans+=(LL)(a-1)(n-c+1);
}
*/

/*前缀和
之前的双指针算法时间复杂度的瓶颈为：排序O(nlog2n)


考虑是否可以不排序在O(n)的时间内解决此问题呢？

既然要排序实现快速的查找A中小于B[i]的数的个数，可以将数组A中所有元素出现的次数存入一个哈希表中，因为数组中元素的范围只有n5
, 可以开一个大的数组cnta 作为哈希表。

在枚举B中元素时，我们需要快速查找找小于B[i]的所有元素的总数，只需要在枚举之前先将求出表中各数的前缀和即可。

查找C与查找A同理可得。

C++代码实现*/

//前缀和
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;
const int N = 1e5+10;
int A[N], B[N], C[N];
int cnta[N], cntc[N], sa[N], sc[N];

int main() {
    int n;
    scanf("%d", &n);
    //获取数i在A中有cntc[i]个，并对cnt求前缀和sa
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &A[i]);
        cnta[++A[i]]++;//++A[i],所以cnta[x]，存的是从0到x-1所有的数字出现的次数，即小于x的所有数出现的次数
    }
    sa[0] = cnta[0];
    for(int i = 1; i < N; ++i) sa[i] = sa[i-1]+cnta[i];
    //B只读取即可
    for(int i = 1; i <= n; ++i) scanf("%d", &B[i]), B[i]++;//B[i]++

    //获取数i在C中有cntc[i]个，并对cnt求前缀和sc
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &C[i]);
        cntc[++C[i]]++;
    }
    sc[0] = cntc[0];
    for(int i = 1; i < N; ++i) sc[i] = sc[i-1]+cntc[i]; 

    //遍历B求解
    LL ans = 0;
    for(int i = 1; i <= n; ++i) {
        int b = B[i];//因为B[i]前面自增了，所有b存的其实是B[i]+1的数值
        ans += (LL)sa[b-1] * (sc[N-1] - sc[b]);//要求小于B[i]的所有A[i]，需要b-1得到原来的B[i],sa[b-1]就是所有小于B[i]的A中元素的数量，同理sc[b]就是所有小于等于B[i]的c中元素的数量
    }
    cout<<ans<<endl;
    return 0;
}
