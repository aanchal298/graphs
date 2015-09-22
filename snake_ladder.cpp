#include<bits/stdc++.h>
using namespace std;


int minpath(int moves[],int n)
{
    queue<pair<int,int> > q;

    int visited[25]={0};
    q.push(make_pair(0,0));
    int i;
    visited[0]=1;
    pair<int,int> p;
    while(!q.empty())
    {
        p=q.front();
        if(p.first==n-1)
            break;
         q.pop();
        int u=p.first;
        int d=p.second;
        for(i=u+1;i<=u+6;i++)
        {
            pair<int,int> pp;
            if(visited[i]!=1)
            {
                visited[i]=1;
                pp.second=d+1;
                if(moves[i]==-1)
                    pp.first=i;
                else
                    pp.first=moves[i];
                q.push(pp);
            }
        }
    }
    return p.second;
}



int main()
{
    int N = 30;
    int moves[N];
    for (int i = 0; i<N; i++)
        moves[i] = -1;

    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout << "Min Dice throws required is " << minpath(moves, N);
    return 0;
}
