#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,pair<int,int> > > &arr,int u,int v,int w)
{
    arr.push_back(make_pair(w,make_pair(u,v)));
}
int finds(vector<pair<int,int> > &parentrank,int v)
{
    if(parentrank[v].first!=v)
        finds(parentrank,parentrank[v].first);

    return parentrank[v].first;
}
void unions(vector<pair<int,int> > &parentrank,int u,int v)
{
    int x=finds(parentrank,u);
    int y=finds(parentrank,v);
    if(parentrank[x].second>parentrank[y].second)
    {
        parentrank[y].first=x;
       // cout<<"one"<<endl;
    }
    else if(parentrank[x].second<parentrank[y].second)
    {
        parentrank[x].first=y;
     //   cout<<"two"<<endl;
    }
    else if(parentrank[x].second==parentrank[y].second)
    {
        parentrank[y].first=x;
        parentrank[x].second++;
    }
}

void kruskals(vector<pair<int,pair<int,int> > > arr,int n)
{
    //cout<<arr[0].first<<endl;
    vector<pair<int,int> > result,parentrank;
    int i;
    for(i=0;i<n;i++)
    {
        parentrank.push_back(make_pair(i,0));
    }
    sort(arr.begin(),arr.end());

    int e=0;
    i=0;
    while(e<n-1)
    {
        pair<int,pair<int,int> > p=arr[i++];
        int u=p.second.first;
        int v=p.second.second;
        int w=p.first;
        int xset=finds(parentrank,u);
        int yset=finds(parentrank,v);
      //  cout<<xset<<endl;
        if(xset!=yset)
        {
            e++;
            result.push_back(make_pair(u,v));
            unions(parentrank,xset,yset);
        }
        //cout<<finds(parentrank,u)<<" "<<finds(parentrank,v)<<endl;;

    }
    for(i=0;i<result.size();i++)
    {
        cout<<result[i].first<<" "<<result[i].second<<endl;
    }
}

int main()
{
    vector<pair<int,pair<int,int> > > arr;
    addEdge(arr,0,1,10);
    addEdge(arr,0,2,6);
    addEdge(arr,2,3,4);
    addEdge(arr,1,3,15);
    addEdge(arr,0,3,5);
   // cout<<arr[0].first<<endl;
    kruskals(arr,4);
    return 0;

}
