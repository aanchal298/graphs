#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> mygraph[],int u,int v)
{
    mygraph[u].push_back(v);
    //mygraph[v].push_back(u);
}

void dfsutil(list<int> mygraph[],int v,int visited[],stack<int> &s)
{
    visited[v]=1;
    //cout<<v<<" ";
    list<int>::iterator it;
    for(it=mygraph[v].begin();it!=mygraph[v].end();it++)
    {
        if(visited[*it]!=1)
            dfsutil(mygraph,*it,visited,s);
    }
    s.push(v);
}
void dfsutil2(list<int> mygraph[],int v,int visited[])
{
    visited[v]=1;
    cout<<v<<" ";
    list<int>::iterator it;
    for(it=mygraph[v].begin();it!=mygraph[v].end();it++)
    {
        if(visited[*it]!=1)
            dfsutil2(mygraph,*it,visited);
    }
    //s.push(v);
}

int dfs(list<int> mygraph[])
{
    stack<int> s;
    int v=mygraph->size();
    int visited[15]={0};
    int i;
    for(i=0;i<v;i++)
        visited[i]=0;
    dfsutil(mygraph,1,visited,s);
    list<int> rev[5];
     list<int>::iterator it;
    for(int i=0;i<5;i++)
    {
        for(it=mygraph[i].begin();it!=mygraph[i].end();it++)
        {
            //cout<<i<<" "<<*it<<endl;
            rev[*it].push_back(i);
        }
    }

     int vis[15]={0};
    while(!s.empty())
    {
        int u=s.top();
        s.pop();
        if(vis[u]==0)
            dfsutil2(rev,u,vis);
        cout<<endl;
    }
}

int main()
{
    list<int> mygraph[5];
    addEdge(mygraph,1, 0);
    addEdge(mygraph,0, 2);
    addEdge(mygraph,2, 1);
    addEdge(mygraph,0, 3);
    addEdge(mygraph,3, 4);;

    int p=dfs(mygraph);
    cout<<p<<endl;
    return 0;
}

