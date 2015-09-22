#include<bits/stdc++.h>
using namespace std;
void printarray(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void printpaths(int mat[][4],int visited[][4],int i,int j,int path[],int pathlen)
{
    int p,q;
    visited[i][j]=1;
    if(i==3&&j==3)
    {
        printarray(path,pathlen);
    }
    for(p=-1;p<=1;p++)
    {
        for(q=-1;q<=1;q++)
        {
            if(i+p>=0 && i+p<4 && j+q>=0 && j+q<4 && mat[i+p][j+q]!=0 && visited[i+p][j+q]==0)
            {
                path[pathlen++]=mat[i+p][j+q];
                printpaths(mat,visited,i+p,j+q,path,pathlen);
            }
        }
    }
    visited[i][j]=0;
}
int main()
{
    int visited[4][4]={{0}};
    int path[10];
    int pathlen=0;
    int mat[4][4]  =  { {1, 0, 0, 0},
        {2, 3, 0, 4},
        {0, 5, 0, 0},
        {6, 7, 8, 10}
    };
 printpaths(mat,visited,0,0,path,pathlen);
 return 0;
}
