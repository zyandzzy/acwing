#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[1010],con;

//解法一：暴力枚举
/*int main()
{  

   int m;
   cin>>m;
   for(int i =0;i<m;i++)
   cin>>arr[i];

   int x = arr[0];

   sort(arr,arr+m);

   while(x<=arr[m-1])
   {
      x+=1;
      arr[m-1]-=1;
       int c = arr[m-1];
       int b = m;
      for(int j = m-2;j>=0&&arr[j]>c;j--,b--)
      {
        int tmp = 0;
        tmp = arr[j];
        arr[j] = arr[b-1];
        arr[b-1] = tmp;
      }
      con++;
   }
   cout<<con;

}*/
//解法二：二分查找

bool check(int mi)
{
   int x = arr[0]+ mi;

   int sum = 0;

   for(int i = 0;i<con;i++)
   {
      if(arr[i]>x)
      sum+=arr[i]-x+1;
   }

   if(sum>=mi&&sum!=0) return false;
   else return true;
}
int main()
{
   cin>>con;

   for(int i = 0;i<con;i++)
   {
      cin>>arr[i];
   }


   int l = 0,r = 1000;

   while(l<r)
   {
      int mid = l+r>>1;

      if(check(mid)) r = mid;
      else l = mid+1;
   }
   
   cout<<l;
}
