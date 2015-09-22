#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> mygraph[],int u,int v)
{
    mygraph[u].push_back(v);
    //mygraph[v].push_back(u);
}

void dfsutil(list<int> mygraph[],int v,int visited[])
{
    visited[v]=1;
    //cout<<v<<" ";
    list<int>::iterator it;
    for(it=mygraph[v].begin();it!=mygraph[v].end();it++)
    {
        if(visited[*it]!=1)
            dfsutil(mygraph,*it,visited);
    }
}
int reversegraph(list<int> arr[])
{
    int v=arr->size();
    list<int> rev[10];
    int i;
    for(i=0;i<3;i++)
    {
        list<int>::iterator it;
        for(it=arr[i].begin();it!=arr[i].end();it++)
        {
            rev[*it].push_back(i);
          //  cout<<(*it)<<" "<<i<<endl;
        }
    }

    int visited[15]={0};
    for(i=0;i<v;i++)
        visited[i]=0;
    dfsutil(rev,1,visited);
    for(i=0;i<v;i++)
    {
        if(visited[i]==0)
            return 0;
    }
    return 1;
}

int dfs(list<int> mygraph[])
{
    int v=mygraph->size();
    int visited[15]={0};
    int i;
    for(i=0;i<v;i++)
        visited[i]=0;
    dfsutil(mygraph,1,visited);
    for(i=0;i<v;i++)
    {
        if(visited[i]==0)
            return 0;
    }
  //  reversegraph(mygraph);
    if(reversegraph(mygraph))
        return 1;
    else return 0;
}

int main()
{
    list<int> mygraph[15];
    addEdge(mygraph,0, 1);
    addEdge(mygraph,1, 2);
    addEdge(mygraph,2, 3);
  //  addEdge(mygraph,3, 0);
   // addEdge(mygraph,2, 4);
    //addEdge(mygraph,4, 2);
    int p=dfs(mygraph);
    cout<<p<<endl;
    return 0;
}

