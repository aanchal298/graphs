#include<bits/stdc++.h>
using namespace std;


void bellman(vector<pair<int,pair<int,int> > > edges,int n,int src)
{
    int dist[10];
    int m=edges.size();
    for(int i=0;i<n;i++)
        dist[i]=INT_MAX;
    dist[src]=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            int v=edges[j].second.second;
            int u=edges[j].second.first;
            int w=edges[j].first;
            if( dist[u]!=INT_MAX)
            {

                if(dist[v]>dist[u]+w)
                    dist[v]=dist[u]+w;
            }
        }
    //    cout<<endl;
    }
    for(i=0;i<n;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
}

int main()
{
    vector<pair<int,pair<int,int> > > edges;
    edges.push_back(make_pair(-1,make_pair(0,1)));
    edges.push_back(make_pair(3,make_pair(1,2)));
    edges.push_back(make_pair(1,make_pair(3,1)));
    edges.push_back(make_pair(2,make_pair(1,3)));
    edges.push_back(make_pair(2,make_pair(1,4)));
    edges.push_back(make_pair(4,make_pair(0,2)));
    edges.push_back(make_pair(5,make_pair(3,2)));
    edges.push_back(make_pair(-3,make_pair(4,3)));
    bellman(edges,5,0);
}
