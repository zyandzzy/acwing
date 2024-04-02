#include<iostream>

using namespace std;

const int N = 1010;

int q[N][N],arr[N][N];

int main()
{
  int n;

  cin>>n;

  while(n--)
  {
    int x,y;

    for(int i = 1;i<=x;i++)
    {
      for(int j = 1;j<=y;j++)
      {
        cin>>q[i][j];
      }
    }

    for(int i =1;i<=x;i++)
    {
      for(int j = 1;j<=y;j++)
      arr[i][j] = max(arr[i-1][j],arr[i][j-1])+q[i][j];
    }
    cout<<arr[x][y]<<endl;
  }
}