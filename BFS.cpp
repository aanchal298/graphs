#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> arr[],int u,int v)
{
    arr[u].push_back(v);
  //  arr[v].push_back(u);
}
void bfs(list<int> arr[],int v)
{
    int visited[4]={0};
    visited[v]=1;
    cout<<v<<" ";
    queue<int> q;
    q.push(v);
    list<int>::iterator it;
    while(!q.empty())
    {
        int y=q.front();
        q.pop();
        for(it=arr[y].begin();it!=arr[y].end();it++)
        {
            if(visited[*it]!=1)
            {
                cout<<*it<<" ";
                visited[*it]=1;
                q.push(*it);
            }
        }
    }
    cout<<endl;
}
int main()
{
    list<int> arr[4];
    addEdge(arr,0, 1);
    addEdge(arr,0, 2);
    addEdge(arr,1, 2);
    addEdge(arr,2, 0);
    addEdge(arr,2, 3);
    addEdge(arr,3, 3);
    bfs(arr,2);
    return 0;
}
