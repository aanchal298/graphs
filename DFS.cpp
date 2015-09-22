#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> mygraph[],int u,int v)
{
    mygraph[u].push_back(v);
    mygraph[v].push_back(u);
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
    list<int> mygraph[15];
    addEdge(mygraph,1, 2);
    addEdge(mygraph,1, 8);
    addEdge(mygraph,1, 6);
    addEdge(mygraph,2, 3);
    addEdge(mygraph,8, 3);
    addEdge(mygraph,6, 7);
    addEdge(mygraph,9, 3);
    addEdge(mygraph,4, 3);
    addEdge(mygraph,9, 5);
    addEdge(mygraph,7, 5);
    addEdge(mygraph,4, 5);
    dfs(mygraph);
    return 0;
}
