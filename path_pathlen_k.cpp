#include<bits/stdc++.h>
using namespace std;


void addEdge(list<int> arr[],int u,int v)
{
    arr[u].push_back(v);
    //arr[v].push_back(u);
}
void printarray(int path[],int pathlen)
{
    int i;
    for(i=0;i<pathlen;i++)
        cout<<path[i]<<" ";
    cout<<endl;
}
void printpath(list<int> arr[],int path[],int pathlen,int u,int v,int k)
{
    path[pathlen++]=u;
    if(k<0)
        return;
    if(u==v&&k==0)
    {
        printarray(path,pathlen);
        return;
    }
    list<int>::iterator it;
    for(it=arr[u].begin();it!=arr[u].end();it++)
    {
        printpath(arr,path,pathlen,*it,v,k-1);
    }
}

int main()
{
    list<int> arr[10];
    int path[10];
    addEdge(arr,0, 1);
    addEdge(arr,0, 2);
    addEdge(arr,0, 3);
     addEdge(arr,1, 3);
    //addEdge(arr,2, 4);
    addEdge(arr,2, 3);
    printpath(arr,path,0,0,3,2);
    //cout<<yy<<endl;
    return 0;
}

