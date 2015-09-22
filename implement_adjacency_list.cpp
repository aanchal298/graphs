#include<bits/stdc++.h>
using namespace std;

struct node{
    int des;
    struct node *next;
};

struct adjlist
{
    struct node *head;
};
struct graph{
    int v;
    struct adjlist *arr;
};

struct node *newnode(int d)
{
    struct node *temp=(node*)malloc(sizeof(node));
    temp->des=d;
    temp->next=NULL;
    return temp;
};

struct graph *creategraph(int y)
{
    struct graph *mygraph=(graph*)malloc(sizeof(graph));
    mygraph->v=y;
    mygraph->arr=(struct adjlist*)malloc(y*sizeof(adjlist));
    int i=0;
    for(i=0;i<y;i++)
    {
        mygraph->arr[i].head=NULL;
    }
    return mygraph;
}
void addEdge(struct graph *mygraph,int s,int d)
{
    struct node *temp=newnode(d);
    temp->next=mygraph->arr[s].head;
    mygraph->arr[s].head=temp;

    struct node *p=newnode(s);
    p->next=mygraph->arr[d].head;
    mygraph->arr[d].head=p;
}

void printgraph(struct graph *mygraph)
{
    int i;
    for(i=0;i<mygraph->v;++i)
    {
        struct node *p=mygraph->arr[i].head;
        while(p!=NULL)
        {
            cout<<p->des<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}
int main()
{
    int V = 5;
    struct graph* mygraph = creategraph(V);
    addEdge(mygraph, 0, 1);
    addEdge(mygraph, 0, 4);
    addEdge(mygraph, 1, 2);
    addEdge(mygraph, 1, 3);
    addEdge(mygraph, 1, 4);
    addEdge(mygraph, 2, 3);
    addEdge(mygraph, 3, 4);

    // print the adjacency list representation of the above graph
    printgraph(mygraph);
}
