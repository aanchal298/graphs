#include<bits/stdc++.h>
using namespace std;


void addEdge(list<int> mygraph[],int u,int v)
{
    mygraph[u].push_back(v);
   // mygraph[v].push_back(u);
}


int iscyclicutil(list<int> arr[],int visited[],int recstack[],int v)
{
    if(visited[v]==0)
    {
        visited[v]=1;
        recstack[v]=1;
        list<int>::iterator it;
        for(it=arr[v].begin();it!=arr[v].end();it++)
        {
            if(visited[*it]==0 && iscyclicutil(arr,visited,recstack,*it)==1)
                return 1;
            if(recstack[*it]!=0)
                return 1;
        }

    }

    recstack[v]=0;
    return 0;
}
int iscyclic(list<int> arr[])
{
    int visited[10]={0};
    int recstack[10]={0};
    int yy=iscyclicutil(arr,visited,recstack,1);
    cout<<yy<<endl;;
    return yy;
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
    int yy=iscyclic(arr);
    cout<<yy;
    return 0;
}
