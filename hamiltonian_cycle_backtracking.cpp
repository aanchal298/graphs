#include<bits/stdc++.h>
using namespace std;
#define n 5

int issafe(int graph[][n],int path[],int pos,int v)
{
    cout<<v<<endl;
    if(graph[pos-1][v]==0)
        return 0;
    for(int i=0;i<pos;i++)
    {
        if(path[i]==v)
            return 0;
    }
    return 1;
}
int ishamutil(int graph[][n],int path[],int pos)
{
    if(pos==n-1)
    {
        //cout<<path[pos-1]<<endl;
        if(graph[pos-1][path[0]]==1)
            return 1;
        else return 0;
    }
    for(int i=1;i<n;i++)
    {
        if(issafe(graph,path,pos,i)==1)
        {
            path[pos]=i;
            if(ishamutil(graph,path,pos+1)==1)
                return 1;
            else path[pos]=-1;
        }
    }
    return 0;
}

void isham(int graph[][n])
{
    int path[n];
    for(int i=0;i<n;i++)
        path[i]=-1;
    path[0]=0;
    if(ishamutil(graph,path,1)==0)
    {
        cout<<"NO ham cycle"<<endl;
    }
    else
    {
        cout<<"The cycle is"<<endl;
        for(int i=0;i<n;i++)
            cout<<path[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    int graph[5][5]={{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
    isham(graph);
    return 0;
}
