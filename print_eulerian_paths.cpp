#include<bits/stdc++.h>
using namespace std;
void addEdge(list<int> arr[],int u,int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}

void removeEdge(list<int> arr[],int u,int v)
{
    replace(arr[u].begin(),arr[u].end(),v,-1);
    replace(arr[v].begin(),arr[v].end(),u,-1);
}

int dfscount(list<int> arr[],int v,int visited[])
{
    int count=0;
    visited[v]=1;
    list<int>::iterator it;
    for(it=arr[v].begin();it!=arr[v].end();it++)
    {
        if (*it != -1 && visited[*it]==0)
          count += dfscount(arr,*it, visited);
    }
    return count;
}
int isbridge(list<int> arr[],int u,int v,int n)
{
    int visited[10]={0};
    int count=0;
    list<int>::iterator it;
    for(it=arr[u].begin();it!=arr[u].end();it++)
    {
        if(*it!=-1)
            count++;
    }
    if(count==1)
        return 1;
    int vis[10]={0};
    int y=dfscount(arr,u,vis);
    cout<<y<<endl;
    removeEdge(arr,u,v);
    int pis[10]={0};
    int z=dfscount(arr,u,pis);
    cout<<z<<endl;
    addEdge(arr,u,v);
    if(y>z)
        return 0;
    else return 1;
}

void printeulerianutil(list<int> arr[],int v,int n)
{

    list<int>::iterator it;
    for(it=arr[v].begin();it!=arr[v].end();it++)
    {
       // cout<<v<<" "<<*it<<endl;
        if(isbridge(arr,v,*it,n)==0 && *it!=-1)
        {
            cout<<v<<" "<<*it<<endl;
            removeEdge(arr,v,*it);
            printeulerianutil(arr,*it,n);
        }
    }

}

int printeulerian(list<int> arr[],int n)
{
    int i;
    int o1=-1,o2=-1,odd=0;
    for(i=0;i<n;i++)
    {
        if(arr[i].size()%2!=0)
        {
            if(odd==0)
                o1=i;
            else if(odd==1)
                o2=i;
            else return 0;
            odd++;
        }
    }
    if(odd==0)
    {
        printeulerianutil(arr,0,n);
    }
    else printeulerianutil(arr,o1,n);


}


int main()
{
    list<int> arr[10];
  addEdge(arr,1, 0);
  addEdge(arr,0, 2);
  addEdge(arr,2, 1);
  addEdge(arr,2,3);
 /* addEdge(arr,0, 3);
  addEdge(arr,3, 4);
  addEdge(arr,3, 2);
  addEdge(arr,3, 1);
  addEdge(arr,2, 4);*/
  printeulerian(arr,4);
  return 0;
}
