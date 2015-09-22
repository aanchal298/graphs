#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > heap;
void addEdge(list<pair<int,int> > arr[],int u,int v,int w)
{
    arr[u].push_back(make_pair(v,w));
    arr[v].push_back(make_pair(u,w));

}
void insertelem(int num,int v)
{
    int n=heap.size();
    n++;
    int i=n;
    int pos=n;
    while(i!=1)
    {
 //       cout<<i<<endl;

        if(heap[i].first>num)
        {
            pos=i;
        }
        heap[i]=heap[i/2];
        i=i/2;
    }

    //cout<<"Pos"<<pos<<endl;
    heap[pos]=make_pair(num,v);
}
void decreasepr(list<pair<int,int> > arr[],int n)
{

}
void prim(list<pair<int,int> > arr[],int n)
{
    vector<int> s,s1;

    for(int i=0;i<n;i++)
    {
        s.push_back(0);
        s1.push_back(1);
    }
    int e=0;
    vector<pair<int,int> > result;
    s[0]=1;
    s1[0]=0;
    list<pair<int,int> >::iterator it;
    for(it=arr[0].begin();it!=arr[0].end();it++)
    {

        minHeap.push(make_pair((*it).second),(*it).first);
    }
    e=1;
    while(e!=n-1)
    {

        pair<int,int> p=minHeap.top();
        minHeap.pop();
        e++;
        int u=p.first;
        s[u]=1;
        s1[u]=0;
        cout<<p.second<<" ";
        list<pair<int,int> >::iterator it;
        for(it=arr[u].begin();it!=arr[u].end();it++)
        {
            if(s[(*it).first]==0)
            {
                minHeap.push(make_pair((*it).first,(*it).second));
            }

        }
    }

}



int main()
{
    list<pair<int,int> > arr[10];
    addEdge(arr,0,1,10);
    addEdge(arr,2,3,4);
    addEdge(arr,0,3,5);
    addEdge(arr,3,1,15);
    addEdge(arr,0,2,6);
   /* addEdge(arr,4,1,5);
    addEdge(arr,2,4,7);*/
    prim(arr,5);
    return 0;
}
