#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,pair<int,int> > > &edgearray,int u,int v,int w)
{
    edgearray.push_back(make_pair(w,make_pair(u,v)));
}
int finds(vector<pair<int,int> > &parent,int v)
{
    if(parent[v].first!=v)
        parent[v].first=finds(parent,parent[v].first);
    return parent[v].first;
}
void unions(vector<pair<int,int> > &parent,int u,int v)
{
    int x=finds(parent,u);
    int y=finds(parent,v);

    if(parent[x].second > parent[y].second)
    {
        parent[y].first=x;
    }
    else if(parent[x].second < parent[y].second)
    {
        parent[x].first=y;
    }
    else if(parent[x].second = parent[y].second)
    {
        parent[y].first=x;
        parent[x].second++;
    }

}

void kruskal(vector<pair<int,pair<int,int> > > &edgearray,int n)
{
    vector<pair<int,int> > result;
    vector<pair<int,int> > parent;
    for(int i=0;i<n;i++)
    {
        parent.push_back(make_pair(i,0));
    }
    sort(edgearray.begin(),edgearray.end());
    int e=0,i=0;
    while(e!=n-1)
    {
        pair<int,pair<int,int> > p=edgearray[i++];
        int ww=p.first;
        int u=p.second.first;
        int v=p.second.second;
        int xset=finds(parent,u);
        int yset=finds(parent,v);

        if(xset!=yset)
        {
             //cout<<xset<<" "<<yset<<endl;
            e++;
            result.push_back(make_pair(u,v));
            unions(parent,xset,yset);
        }

    }
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i].first<<" "<<result[i].second<<endl;
    }


}

int main()
{
    vector<pair <int,pair<int,int> > > edgearray;
    addEdge(edgearray,0,1,10);
    addEdge(edgearray,0,2,6);
    addEdge(edgearray,2,3,4);
    addEdge(edgearray,1,3,15);
    addEdge(edgearray,0,3,5);
    kruskal(edgearray,4);

}
