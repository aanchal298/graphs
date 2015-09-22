#include<bits/stdc++.h>
using namespace std;
string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};

int match(string s)
{
    int i;
    for(i=0;i<4;i++)
    {
        int y=s.compare(dictionary[i]);
        if(y==0)
            return 1;
    }
    return 0;
}

void findwordsutil(char boggle[][3],int visited[][3],int i,int j,string &s)
{
     visited[i][j]=1;
    s+=boggle[i][j];
    int y=match(s);
    if(y==1)
    {
        cout<<s;
        cout<<endl;
    }
    int p,q;
    for(p=-1;p<=1;p++)
    {
        for(q=-1;q<=1;q++)
        {
            if(i+p>=0 && i+p<3 && j+q>=0 && j+q<3 &&visited[i+p][j+q]!=1)
                findwordsutil(boggle,visited,i+p,j+q,s);
        }
    }
    s.erase(s.length()-1);
    visited[i][j]=0;
}
void findwords(char boggle[][3],int n)
{
    int i,j;
    int visited[3][3]={{0}};
    string f;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)

            findwordsutil(boggle,visited,i,j,f);
    }
}


int main()
{
   char boggle[3][3] = {{'G','I','Z'},
                         {'U','E','K'},
                         {'Q','S','E'}};

    cout << "Following words of dictionary are present\n";
    findwords(boggle,3);
    return 0;
}
