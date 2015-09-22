#include<bits/stdc++.h>
using namespace std;


void addEdge(list<int> arr[],int u,int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}

void mcoloring(list<int> arr[],int n)
{
    int i,j;
    int availcolors[10];
    int vercolor[10];
    for(i=0;i<n;i++)
        vercolor[i]=-1;
    for(i=0;i<n;i++)
        availcolors[i]=0;

    for(i=0;i<n;i++)
    {
        list<int>::iterator it;
        for(it=arr[i].begin();it!=arr[i].end();it++)
        {
            if(vercolor[*it]!=-1)
                availcolors[vercolor[*it]]=-1;
        }
        for(j=0;j<n;j++)
        {
            if(availcolors[j]!=-1)
            {
                vercolor[i]=j;
                break;
            }
        }
        for(j=0;j<n;j++)
            availcolors[j]=0;
    }
    for(i=0;i<n;i++)
        cout<<vercolor[i]<<" ";
    cout<<endl;
}

int main()
{
    list<int> arr[10];
    addEdge(arr,0, 1);
    addEdge(arr,0, 2);
    addEdge(arr,1, 2);
    addEdge(arr,1, 4);
    addEdge(arr,2, 4);
    addEdge(arr,3, 4);
    mcoloring(arr,5);
    return 0;
}
