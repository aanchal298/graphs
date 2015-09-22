#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> arr[],int u,int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}
void bfs(list<int> arr[],int v)
{
    int visited[15]={0};
    visited[v]=1;
    cout<<"Node"<<v<<" "<<"Level"<<"0"<<endl;;
    queue<pair<int,int> > q;
    q.push(make_pair(v,0));
    list<int>::iterator it;
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        int y=p.first;
        int z=p.second;
        for(it=arr[y].begin();it!=arr[y].end();it++)
        {
            if(visited[*it]!=1)
            {
                cout<<"Node"<<*it<<" "<<"Level"<<z+1<<endl;
                visited[*it]=1;
                q.push(make_pair(*it,z+1));
            }
        }
    }
    cout<<endl;
}
int main()
{
    list<int> arr[15];
    addEdge(arr,1, 2);
    addEdge(arr,1, 8);
    addEdge(arr,1, 6);
    addEdge(arr,2, 3);
    addEdge(arr,8, 3);
    addEdge(arr,6, 7);
    addEdge(arr,9, 3);
    addEdge(arr,4, 3);
    addEdge(arr,9, 5);
    addEdge(arr,7, 5);
    addEdge(arr,4, 5);
    bfs(arr,1);
    return 0;
}

