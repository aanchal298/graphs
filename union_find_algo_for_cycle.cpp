#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> arr[],int u,int v)
{
    arr[u].push_back(v);
    //arr[v].push_back(u);
}

int find(int parent[],int u)
{
    if(parent[u]==-1)
        return u;
    return find(parent,parent[u]);
}

void unions(int parent[],int u,int v)
{
    int xset=find(parent,u);
    int yset=find(parent,v);
    parent[xset]=yset;
}

int iscycle(list<int> arr[],int n)
{
    int parent[5];
    for(int i=0;i<5;i++)
        parent[i]=-1;
    for(int i=0;i<n;i++)
    {
        list<int>::iterator it;
        for(it=arr[i].begin();it!=arr[i].end();it++)
        {
            int x=find(parent,i);
            int y=find(parent,*it);


            if(x==y)
                return 1;
            unions(parent,x,y);
        }
    }
    return 0;
}
int main()
{
    list<int> arr[5];
    addEdge(arr,1, 0);
    addEdge(arr,0, 2);
    addEdge(arr,2, 1);
    int yy=iscycle(arr,3);
    cout<<yy<<endl;
    return 0;

}
