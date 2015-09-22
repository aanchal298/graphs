#include<bits/stdc++.h>
using namespace std;



void addEdge(list<int> arr[],int u,int v)
{
    arr[u].push_back(v);
    //arr[v].push_back(u);
}
void printorderutil(list<int> arr[],int visited[],int v,stack<int>& s)
{
    visited[v]=1;
    list<int>::iterator it;
    for(it=arr[v].begin();it!=arr[v].end();it++)
    {
        if(visited[*it]!=1)
            printorderutil(arr,visited,*it,s);
    }
    s.push(v);
}
void printorder(string arr[],int n)
{
    list<int> arra[10];
    int i,j,k;
    for(k=0;k<n-1;k++)
    {
        string a=arr[k];
        string b=arr[k+1];
        for(i=0,j=0;i<a.length(),j<b.length();i++,j++)
        {
            if(a[i]!=b[j])
                break;
        }
        //cout<<a[i]<<" "<<b[j]<<endl;
        int aa=(int)a[i]-(int)'a';
        int bb=(int)b[j]-(int)'a';
        addEdge(arra,aa,bb);
    }
    list<int>::iterator ii;
    ii=arra[0].begin();
    int y=*ii;
    int visited[10]={0};
    stack<int> s;
    for(i=0;i<arr->size();i++)
        if(visited[i]==0)
            printorderutil(arra,visited,i,s);

    while(!s.empty())
    {
        // cout<<s.top()<<endl;
        int o=s.top();
        s.pop();
        o=o+(int)'a';
        char oo=(char)o;
        cout<<oo<<" ";
    }
    cout<<endl;
}
int main()
{
    string arr[5]={"caa", "aaa", "aab"};
    printorder(arr,3);
    return 0;
}

