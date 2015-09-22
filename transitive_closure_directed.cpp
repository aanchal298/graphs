#include<bits/stdc++.h>
using namespace std;


void transitiveclosure(int graph[][4])
{
    int i,j;
    int reach[4][4];
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            reach[i][j]=graph[i][j];
        }
    }
    cout<<reach[0][0]<<endl;
    int k;
    for(k=0;k<4;k++)
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                reach[i][j]=(reach[i][j] || (reach[i][k]&&reach[k][j]));
            }
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<reach[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    int graph[4][4] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };

    // Print the solution
    transitiveclosure(graph);
    return 0;
}
