/*#include<iostream>

using namespace std;

const int N = 40;

int q[N][N];

int main()
{
    int m,n;
    
    cin>>n>>m;
    
    q[1][1] = 1;
    
     for(int i =1;i<=n;i++)
     {
         for(int j=1;j<=m;j++)
         {
             if(i==1&&j==1)
             continue;
             
             if(i%2||j%2)
             q[i][j] = q[i-1][j]+q[i][j-1];
         }
     }
       
       
     cout<<q[n][m];
}*/

#include<iostream>

using namespace std;

int m,n,ans,dx[2] = {0,1},dy[2] = {1,0};

const int N = 40;

int q[N][N];

bool book[N][N];

void dfs(int x,int y)
{
    if(x>m||y>n) return;

    if(x==m&&y==n) ans++;

    for(int i = 0;i<2;i++)
    {
       int xx = x+dx[i];
       int yy = y+dy[i];

       if(xx>m||xx<1||yy>n||yy<1) continue;

       if(book[xx][yy]||xx%2==0&&yy%2==0) continue;

       book[xx][yy] = true;

       dfs(xx,yy);

       book[xx][yy] = false;

    }
}

int main()
{
    cin>>m>>n;

    dfs(1,1);

    cout<<ans;
}