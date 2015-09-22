#include<bits/stdc++.h>
using namespace std;


void addEdge(list<int> arr[],int u,int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}

int iscycleutil(list<int> arr[],int visited[],int parent[],int v)
{
    visited[v]=1;
    list<int>::iterator it;
    for(it=arr[v].begin();it!=arr[v].end();it++)
    {
        if(visited[*it]!=1)
        {
            parent[*it]=v;
            if(iscycleutil(arr,visited,parent,*it)==1)
                return 1;
        }
        else if(visited[*it]==1 && (*it)!=parent[v])
            return 1;
    }
}
int iscycle(list<int> arr[],int n)
{
   int i;
   list<int>::iterator it;
   int parent[10];
   int visited[10]={0};
   for(i=0;i<n;i++)
    parent[i]=-1;
   for(i=0;i<n;i++)
   {
       if(visited[i]==0)
       {
           if(iscycleutil(arr,visited,parent,i)==1)
            return 1;
       }
   }
   return 0;
}

int main()
{
    list<int> arr[10];
    addEdge(arr,0, 1);
  //  addEdge(arr,0, 2);
    addEdge(arr,1, 2);
    addEdge(arr,0, 3);
    //addEdge(arr,2, 4);
    addEdge(arr,3, 4);
    int yy=iscycle(arr,5);
    cout<<yy<<endl;
    return 0;
}
