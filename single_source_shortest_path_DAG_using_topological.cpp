#include<bits/stdc++.h>
using namespace std;

void addEdge(list<pair<int,int> > arr[],int u,int v,int weight)
{
   // arr[v].push_back(u);
    arr[u].push_back(make_pair(v,weight));
}
void topologicalutil(list<pair<int,int> > arr[],int v,int visited[],stack<int>& s)
{
    visited[v]=1;
    list<pair<int,int> >::iterator it;
    for(it=arr[v].begin();it!=arr[v].end();it++)
    {
        if(visited[(*it).first]==0)
          topologicalutil(arr,(*it).first,visited,s);
    }
    //cout<<(*it)<<endl;
    s.push(v);
}


void shortest(list<pair<int,int> > arr[],int src)
{
    int visited[10]={0};

    stack<int> s;
    int i;
    for(i=0;i<4;i++)
    {
        if(visited[i]==0)
            topologicalutil(arr,i,visited,s);
    }
    int dist[10];
    for(int y=0;y<10;y++)
    dist[y]=INT_MAX;
    dist[src]=0;
    while(!s.empty())
    {
        int y=s.top();
        s.pop();
       // cout<<dist[y]<<endl;
        list<pair<int,int> > ::iterator it;
        if(dist[y]!=INT_MAX)
        {
            for(it=arr[y].begin();it!=arr[y].end();++it)
            {
                if(dist[(*it).first] > dist[y]+(*it).second)
                   dist[(*it).first]=dist[y]+(*it).second ;
            }

        }
    }
    for(int i=0;i<4;i++)
    {
         if(dist[i]==INT_MAX) cout<<INT_MAX<<endl;
    else
        cout<<dist[i]<<endl;
    }
}

int  main()
{
    list<pair<int,int> > arr[15];

   /* addEdge(arr,0, 1, 5);
    addEdge(arr,0, 2, 3);
    addEdge(arr,1, 3, 6);
    addEdge(arr,1, 2, 2);
    addEdge(arr,2, 4, 4);
    addEdge(arr,2, 5, 2);
    addEdge(arr,2, 3, 7);
    addEdge(arr,3, 4, -1);
    addEdge(arr,4, 5, -2);*/
    addEdge(arr,0, 2, 2);
    addEdge(arr,0, 1, 1);
    addEdge(arr,1, 3, 4);
    addEdge(arr,2, 3, 3);
    addEdge(arr,0, 3, 1);

    shortest(arr,0);
    return 0;
}


