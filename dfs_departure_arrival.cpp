#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> arr[],int u,int v)
{
    arr[v].push_back(u);
    arr[u].push_back(v);
}
int t=0;
void dfsutil(list<int> arr[],int v,int a[],int b[],int visited[])
{
    cout<<v<<" ";
    visited[v]=1;
    a[v]=t++;
    list<int>::iterator it;
    for(it=arr[v].begin();it!=arr[v].end();it++)
    {
        if(visited[*it]!=1)
        {
            //cout<<*it<<" ";
            visited[*it]=1;
            dfsutil(arr,*it,a,b,visited);
        }
    }
    b[v]=t++;
}
void dfs(list<int> arr[])
{
    int visited[10]={0};
    int a[10]={0},b[10]={0};
    dfsutil(arr,1,a,b,visited);
    cout<<endl;
    int i;
    for(i=0;i<10;i++)
    {
        cout<<i<<" "<<a[i]<<" "<<b[i]<<endl;
    }
}


int  main()
{
    list<int> arr[15];
    addEdge(arr,1, 2);
    addEdge(arr,1, 8);
    addEdge(arr,1, 6);
    addEdge(arr,2, 3);
    addEdge(arr,8, 3);
    addEdge(arr,6, 7);
    addEdge(arr,9, 3);
    addEdge(arr,4, 3);
    addEdge(arr,9, 5);
    addEdge(arr,7, 5);
    addEdge(arr,4, 5);
    dfs(arr);
    return 0;
}
