#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> arr[],int v,int u)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}
int t=0;
void bridgeutil(list<int> arr[],int visited[],int discovery[],int parent[],int low[],int u)
{
    visited[u]=1;
    discovery[u]=low[u]=t++;
    list<int>::iterator it;
    for(it=arr[u].begin();it!=arr[u].end();it++)
    {
        int v=*it;
        if(visited[v]!=1)
        {
            parent[v]=u;
            bridgeutil(arr,visited,discovery,parent,low,v);

            low[u]=min(low[u],low[v]);
            if(low[v] > discovery[u])
                cout<<u<<" "<<v<<endl;
        }
        else if(v!=parent[u])
            low[u]=min(low[u],discovery[v]);
    }
}

void bridge(list<int> arr[],int v)
{
    int visited[10]={0};
    int parent[10]={0};
    int low[10],discovery[10];
    int i;
    for(i=0;i<v;i++)
    {
        if(visited[i]!=1)
            bridgeutil(arr,visited,discovery,parent,low,i);
    }

}

int main()
{
    list<int> arr[5];
    addEdge(arr,1, 0);
    addEdge(arr,0, 2);
    addEdge(arr,2, 1);
    addEdge(arr,0, 3);
    addEdge(arr,3, 4);
    bridge(arr,5);
    return 0;
}
