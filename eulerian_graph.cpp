#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> arr[],int v,int u)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}
int t=0;
void dfsutil(list<int> arr[],int visited[],int v)
{
    visited[v]=1;
    list<int>::iterator it;
    for(it=arr[v].begin();it!=arr[v].end();it++)
    {
        int u=*it;
        if(visited[u]==0)
            dfsutil(arr,visited,u);
    }
}
int  isconnected(list<int> arr[],int n)
{
    int visited[10]={0};
    dfsutil(arr,visited,0);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
            return 0;
    }
    return 1;
}
int iseularian(list<int> arr[],int n)
{
    //cout<<isconnected(arr,n)<<endl;
    if(isconnected(arr,n)==0)
        return 0;
    int odd=0;
    for(int i=0;i<n;i++)
    {
        int p=arr[i].size();
        if(p%2!=0)
            odd++;
    }
    if(odd>2)
        return 0;
    if(odd==2)
        return 1;
    else if(odd==0)
        return 2;
}
void ifiu(list<int> arr[],int n)
{
    int yy=iseularian(arr,n);
    if(yy==0)
        cout<<"not eulerian"<<endl;
    if(yy==1)
        cout<<"eulerian path"<<endl;
    if(yy==2)
        cout<<"eulerian cycle"<<endl;

}
int main()
{
    list<int> arr[5],arr2[5],arr3[5],arr4[3];
    addEdge(arr,1, 0);
    addEdge(arr,0, 2);
    addEdge(arr,2, 1);
    addEdge(arr,0, 3);
    addEdge(arr,3, 4);
    ifiu(arr,5);
    addEdge(arr2,1, 0);
    addEdge(arr2,0, 2);
    addEdge(arr2,2, 1);
    addEdge(arr2,0, 3);
    addEdge(arr2,3, 4);
    addEdge(arr2,4, 0);
    ifiu(arr2,5);
    addEdge(arr3,1, 0);
    addEdge(arr3,0, 2);
    addEdge(arr3,2, 1);
    addEdge(arr3,0, 3);
    addEdge(arr3,3, 4);
    addEdge(arr3,1, 3);
    ifiu(arr3,5);


    addEdge(arr4,0, 1);
    addEdge(arr4,1, 2);
    addEdge(arr4,2, 0);
    ifiu(arr4,3);
    return 0;
}

