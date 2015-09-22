#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int> mygraph[],int u,int v)
{
    mygraph[u].push_back(v);
    mygraph[v].push_back(u);
}
int p=1;
int num[10]={0};
void bfs(list<int> arr[],int v)
{
    queue<int> q;
    num[v]=p;
    q.push(v);
    list<int>::iterator it;
    while(!q.empty())
    {
        int y=q.front();
        q.pop();
        for(it=arr[y].begin();it!=arr[y].end();it++)
        {
            if(num[*it]==0)
            {
              //  cout<<*it<<" ";
                num[*it]=p;
                q.push(*it);
            }
        }
    }
    p++;
}

void number(list<int> arr[],int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(num[i]==0)
        {
            bfs(arr,i);
        }
    }
    int x=0;
    for(i=1;i<=n;i++)
    {
      //  cout<<i<<" "<<num[i]<<" ";

        if(num[i]>x)
        x=num[i];
    }

    cout<<x<<endl;
}
int main()
{
    list<int> mygraph[15];
    addEdge(mygraph,1, 2);
    addEdge(mygraph,2, 3);
    addEdge(mygraph,3, 1);

    addEdge(mygraph,6, 5);
    addEdge(mygraph,6, 7);
    addEdge(mygraph,7, 4);
    addEdge(mygraph,4,5);

    addEdge(mygraph,9, 10);
    addEdge(mygraph,8, 9);
    addEdge(mygraph,11, 9);

    int n=10;

    number(mygraph,11);
    return 0;
}

