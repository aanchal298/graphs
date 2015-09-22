#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> arr[],int v,int u)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}
int t=0;
void articulationutil(list<int> arr[],int visited[],int discovery[],int parent[],int low[],int u)
{
    int children=0;
    visited[u]=1;
    discovery[u]=low[u]=t++;
    list<int>::iterator it;
    for(it=arr[u].begin();it!=arr[u].end();it++)
    {
        int v=*it;
        if(visited[v]!=1)
        {
            children++;
            parent[v]=u;
            articulationutil(arr,visited,discovery,parent,low,v);

            low[u]=min(low[u],low[v]);
            if(parent[u]==-1 && children>1)
                cout<<u<<endl;
            if(parent[u]!=-1 && low[v] >= discovery[u])
                cout<<u<<endl;
        }
        else if(v!=parent[u])
            low[u]=min(low[u],discovery[v]);
    }
}

void articulation(list<int> arr[],int v)
{
    int visited[10]={0};
    int parent[10];
    memset(parent,-1,8);
    int low[10],discovery[10];
    int i;
    for(i=0;i<v;i++)
    {
        if(visited[i]!=1)
            articulationutil(arr,visited,discovery,parent,low,i);
    }

}

int main()
{
    list<int> arr[5];
    addEdge(arr,1, 0);
   // addEdge(arr,0, 2);
    addEdge(arr,2, 1);
    addEdge(arr,2, 3);
   // addEdge(arr,3, 4);
    articulation(arr,4);
    return 0;
}
