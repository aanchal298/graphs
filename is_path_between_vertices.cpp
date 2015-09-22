#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> arr[],int u,int v)
{
    arr[u].push_back(v);
   // arr[v].push_back(u);
}

int ispath(list<int> arr[],int u,int v)
{
    queue<int> q;
    int visited[4]={0};
    visited[u]=1;
    q.push(u);
    while(!q.empty())
    {
        int y=q.front();
        q.pop();
        list<int>::iterator it;
        for(it=arr[y].begin();it!=arr[y].end();it++)
        {
            if((*it)==v)
                return 1;
            if(visited[(*it)]!=1)
           {
               visited[(*it)]=1;
               q.push((*it));
           }
        }
    }
    return 0;
}

int main()
{
    int v=4;
    list<int> arr[v];
    addEdge(arr,0, 1);
    addEdge(arr,0, 2);
    addEdge(arr,1, 2);
    addEdge(arr,2, 0);
    addEdge(arr,2, 3);
    addEdge(arr,3, 3);
    int u=ispath(arr,1,3);
    cout<<u<<endl;
    u=ispath(arr,3,1);
    cout<<u<<endl;
    return 0;
}
