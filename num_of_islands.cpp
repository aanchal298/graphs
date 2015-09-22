#include<bits/stdc++.h>
using namespace std;
#define c 5
void dfs(int mat[][5],int visited[][5],int p,int q)
{
    int i,j;
    visited[p][q]=1;
    for(int i=-1;i<=1;i++)
    {
        for(j=-1;j<=1;j++)
        {
           if(p+i<5 && p+i >=0 &&q+j<5 && q+j >=0)
            if(visited[p+i][q+j]!=1 && mat[p+i][q+j]==1)
                dfs(mat,visited,p+i,q+j);
        }
    }
}

int count(int mat[][5],int n,int m)
{
    int visited[5][5];
    int i,j,cc=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            visited[i][j]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(visited[i][j]==0 && mat[i][j]==1)
            {
                cc++;
                dfs(mat,visited,i,j);
            }
        }
    }
    return cc;
}

int main()
{
     int M[5][5]= { {1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 0, 0}
    };
    int yy=count(M,5,5);
    cout<<yy<<endl;
}
