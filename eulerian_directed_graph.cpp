#include<bits/stdc++.h>
using namespace std;
void addEdge(list<int> arr[],int u,int v)
{
    arr[u].push_back(v);
    //arr[v].push_back(u);
}

void dfs(list<int> arr[],int v,int visited[])
{
    visited[v]=1;
    list<int>::iterator it;
    for(it=arr[v].begin();it!=arr[v].end();it++)
    {
        if(visited[*it]!=1)
            dfs(arr,*it,visited);
    }
}

int isstrongconn(list<int> arr[],int n)
{
    list<int> rev[10];
    int visited[10];
    int i;
    for(i=0;i<n;i++)
        visited[i]=0;
    dfs(arr,0,visited);
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
            return 0;
    }
    for(i=0;i<n;i++)
    {
        list<int>::iterator it;
        for(it=arr[i].begin();it!=arr[i].end();it++)
        {
            rev[*it].push_back(i);
        }
    }
    int vis[10];
    for(i=0;i<n;i++)
        vis[i]=0;
    dfs(rev,0,vis);
    for(i=0;i<n;i++)
    {
        if(vis[i]==0)
            return 0;
    }
    return 1;
}
int iseularian(list<int> arr[],int n)
{
    int i;
    int indegree[10]={0};
    for(i=0;i<n;i++)
    {
        list<int>::iterator it;
        for(it=arr[i].begin();it!=arr[i].end();it++)
        {
            indegree[*it]++;
        }
    }
    for(i=0;i<n;i++)
    {
        if(arr[i].size()!=indegree[i])
            return 0;
    }
    if(isstrongconn(arr,n)==1)
        return 1;
    else return 0;
}

int main()
{
    list<int> arr[10];
    addEdge(arr,1, 0);
    addEdge(arr,0, 2);
    addEdge(arr,2, 1);
    addEdge(arr,0, 3);
    addEdge(arr,3, 4);
    addEdge(arr,4, 0);
    int y=iseularian(arr,5);
    cout<<y<<endl;
    return 0;
}
