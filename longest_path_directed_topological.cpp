#include<bits/stdc++.h>
using namespace std;


void addEdge(list<pair<int,int> > arr[],int u,int v,int p)
{
    arr[u].push_back(make_pair(v,p));
}
void topologicalutil(list<pair<int,int> > arr[],int visited[],int v,stack<int> &s)
{
    visited[v]=1;
    list<pair<int,int> >::iterator it;
    for(it=arr[v].begin();it!=arr[v].end();it++)
    {
        int u=(*it).first;
        if(visited[u]!=1)
            topologicalutil(arr,visited,u,s);
    }
    s.push(v);
}

void finlongest(list<pair<int,int> > arr[],int n,int src)
{
    int visited[10]={0};
    stack<int> s;
    int dist[10];
   for(int i=0;i<10;i++)
    dist[i]=-50;
    dist[src]=0;
    cout<<dist[7]<<endl;
    list<pair<int,int> >::iterator it,itt;
    for(int i=0;i<n;i++)
    {
        if(visited[i]!=1)
            topologicalutil(arr,visited,i,s);
    }
    while(!s.empty())
    {
        int y=s.top();
        //cout<<y<<endl;
        s.pop();
        if(dist[y]!=-50)
        {
           for(it=arr[y].begin();it!=arr[y].end();it++)
            {
                cout<<(*it).first<<" "<<(*it).second<<endl;
                if(dist[(*it).first] < dist[y] + (*it).second)
                    dist[(*it).first] = dist[y] + (*it).second;
            }
        }

    }
    for(int i=0;i<n;i++)
    {
        if(dist[i]==-50)
            cout<<INT_MAX<<" ";
        else
            cout<<dist[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    list<pair<int,int> > arr[10];
    addEdge(arr,0, 1, 5);
    addEdge(arr,0, 2, 3);
    addEdge(arr,1, 3, 6);
    addEdge(arr,1, 2, 2);
    addEdge(arr,2, 4, 4);
    addEdge(arr,2, 5, 2);
    addEdge(arr,2, 3, 7);
    addEdge(arr,3, 5, 1);
    addEdge(arr,3, 4, -1);
    addEdge(arr,4, 5, -2);
    finlongest(arr,6,1);
    return 0;
}
