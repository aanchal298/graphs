#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> arr[],int u,int v)
{
   // arr[v].push_back(u);
    arr[u].push_back(v);
}
void topologicalutil(list<int> arr[],int v,int visited[],stack<int>& s)
{
    visited[v]=1;
    list<int>::iterator it;
    for(it=arr[v].begin();it!=arr[v].end();it++)
    {
        if(visited[(*it)]==0)
          topologicalutil(arr,*it,visited,s);
    }
    //cout<<(*it)<<endl;
    s.push(v);
}
void topological(list<int> arr[])
{
    int visited[10]={0};
    int i;
    stack<int> s;
    for(i=1;i<7;i++)
    {
        if(visited[i]==0)
            topologicalutil(arr,i,visited,s);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}



int  main()
{
    list<int> arr[15];
    int n=6;
    addEdge(arr,6, 3);
    addEdge(arr,6, 1);
    addEdge(arr,5, 1);
    addEdge(arr,5, 2);
    addEdge(arr,3, 4);
    addEdge(arr,4, 2);
//    dfs(arr);
    topological(arr);
    return 0;
}

