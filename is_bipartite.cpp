#include<bits/stdc++.h>
using namespace std;
void addEdge(list<int> arr[],int u,int v)
{
    arr[u].push_back(v);
    //arr[v].push_back(u);
}
int isbipartite(list<int> arr[],int src)
{
    queue<int> q;
    int color[5]={0};
    memset(color,-1,5);
    color[src]=1;
    q.push(src);
    while(!q.empty())
    {
        int y=q.front();
        q.pop();
        list<int>::iterator it;
        for(it=arr[y].begin();it!=arr[y].end();it++)
        {
            if(color[*it]==-1)
            {
                color[*it]=1-color[y];
                q.push(*it);
            }

            else if(color[*it]==color[y])
                return 0;
        }
    }
    return 1;

}

int main()
{
    list<int> arr[5];
    addEdge(arr, 0, 1);
    addEdge(arr, 0, 3);
    addEdge(arr, 1, 0);
    addEdge(arr, 1, 2);
    addEdge(arr, 2, 1);
    addEdge(arr, 2, 3);
    addEdge(arr, 3, 0);
    addEdge(arr, 3, 2);
    int y=isbipartite(arr,0);
    cout<<y<<endl;
    return 0;
}
