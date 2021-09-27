#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int A[20][20]={0}, vrtx, clr[20], dis[20], prev[20];

void BFS (int s)
{
    queue<int> Q;
    int i, u;

    for(i=1; i<= vrtx; i++)
    {
        clr[i] = 0;
        dis[i] = 20000000;
        prev[i] = -1;
    }
    clr[s] = 1;
    dis[s] = 0;
    prev[s] = -1;
    Q.push(s);

    cout<<"\nBFS path: ";
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();

        for(i=1; i<= vrtx; i++)
        {
            if(A[u][i]==1 && clr[i]==0)
            {
                clr[i] = 1;
                dis[i] = dis[u]+1;
                prev[i] = u;
                Q.push(i);
            }
        }
        clr[u] = 2;
        cout<<" "<<u<<" ";
    }
}

int main()
{
    int i, j, a, b, edge = 0, k = 0, source;

    cout<<"\n\n\t\tAdjacency Matrix\n\n";
    cout<<"Enter number of vertex: ";
    cin>>vrtx;

    while(a != 0 || b != 0)
    {
        cout<<"Enter edge "<<++k<<" : ";
        cin>>a;
        cin>>b;

        if(a < 0 || a > vrtx || b < 0 || b > vrtx)
        {
            cout<<"\n\nInvalid edge.....\n";
            --k;
        }
        else
        {
            A[a][b] = 1;
            A[b][a] = 1;
            edge++;
        }
    }

    cout<<"Adjacency Matrix: \n";
    for(i = 1; i <= vrtx; i++)
    {
        for(j = 1; j <= vrtx; j++)
        {
            cout<<A[i][j];
        }
        cout<<endl;
    }

    cout<<"\nEnter source node: ";
    cin>>source;
    BFS(source);
    cout<<endl;
    /// BFS table
    cout<<"\n\nTable for BFS:\n Ver: ";
    for(i =1; i<= vrtx; i++)
        cout<<i<<" ";

    cout<<endl;

    cout<<"\nColor: ";
    for(i=1; i<=vrtx; i++)
        cout<<clr[i]<<" ";

cout<<endl;

    cout<<"\nPrevious: ";
    for(i=1; i<=vrtx; i++)
        cout<<prev[i]<<" ";

cout<<endl;

    cout<<"\nDistance: ";
    for(i=1; i<=vrtx; i++)
       cout<<dis[i]<<" ";

cout<<endl;

    return 0;
}
