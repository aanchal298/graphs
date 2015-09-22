#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> arr[],int v,int u)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}
void removeEdge(list<int> arr[],int u,int v)
{
    arr[u].remove(v);
    arr[v].remove(u);
}

void isbridgeutil(list<int> arr[],int visited[],int v)
{
    cout<<v<<endl;
    visited[v]=1;
    list<int>::iterator it;
    for(it=arr[v].begin();it!=arr[v].end();it++)
    {
        if(visited[*it]!=1)
        {
            isbridgeutil(arr,visited,*it);
        }
    }
}
int isbridge(list<int> arr[],int u,int v,int n)
{
    int visited[10]={0};
    removeEdge(arr,u,v);
    isbridgeutil(arr,visited,u);
    addEdge(arr,u,v);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
            return 1;
    }
    return 0;
}
void dfsutil(list<int> mygraph[],int v,int visited[])
{
    visited[v]=1;
    cout<<v<<" ";
    list<int>::iterator it;
    for(it=mygraph[v].begin();it!=mygraph[v].end();it++)
    {
        if(visited[*it]!=1)
            dfsutil(mygraph,*it,visited);
    }
}
void dfs(list<int> mygraph[])
{
    int v=mygraph->size();
    int visited[15]={0};
    int i;
    for(i=0;i<v;i++)
        visited[i]=0;
 //   for(i=0;i<v;i++)
    {
   //     if(visited[i]==0)
            dfsutil(mygraph,1,visited);
    }
}

int main()
{
    list<int> arr[5];
    addEdge(arr,1, 0);
  addEdge(arr,0, 2);
  addEdge(arr,2, 1);
  addEdge(arr,2,3);
    int y=isbridge(arr,1,2,4);
    cout<<y<<endl;
    dfs(arr);
    cout<<endl;
    removeEdge(arr,2,3);
    dfs(arr);
    return 0;
}
