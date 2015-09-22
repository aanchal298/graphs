#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> arr[],int u,int v)
{
    arr[u].push_back(v);
}
void printarray(int arr[],int m)
{
    int i;
    for(i=0;i<m;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void printpathsutil(list<int> arr[],int path[],int visited[],int s,int d,int pathlen)
{
    visited[s]=1;
    path[pathlen++]=s;
    if(s==d)
    {
        printarray(path,pathlen);
    }
    else
    {
        list<int>::iterator it;
        for(it=arr[s].begin();it!=arr[s].end();it++)
        {
            if(visited[*it]!=1)
                printpathsutil(arr,path,visited,*it,d,pathlen);
        }
    }
    visited[s]=0;
}
void paths(list<int> arr[],int n,int s,int d)
{
    int visited[10]={0};
    int path[10];
    int pathlen=0;
    printpathsutil(arr,path,visited,s,d,pathlen);
}



int main()
{
    list<int> arr[10];
    addEdge(arr,0, 1);
    addEdge(arr,0, 2);
    addEdge(arr,0, 3);
    addEdge(arr,2, 0);
    addEdge(arr,2, 1);
    addEdge(arr,1, 3);
    paths(arr,4,2,3);
    return 0;
}
