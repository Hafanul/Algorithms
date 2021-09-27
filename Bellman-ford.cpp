#include<bits/stdc++.h>
using namespace std;

int num_of_vertex, graph[101][101] = { },num_of_edge;
int d[101], p[101], weight_matrix[101][101] = { };

void bellman_ford();

int main() {
    ifstream inf("bellman_ford_input.txt");

    int a, b, i = 1, j=1, m, n, wait;
    inf>>num_of_edge;
    while(inf.good()) {
        if(inf.eof()) {
            break;
        }
        else {
            inf>>a;
            inf>>b;

            if(b>a)
                num_of_vertex = b;
            else
                num_of_vertex = a;

            inf>>wait;
            graph[a][b]=1;
            weight_matrix[a][b]=wait;
        }
    }
    cout << "The Adj Matrix is:" << endl;
    for (m = 1; m <= num_of_vertex; m++) {
        for (n = 1; n <= num_of_vertex; n++) {
            cout << graph[m][n] << "\t";
        }
        cout << endl;
    }
    bellman_ford();
    return 0;

}
void bellman_ford() {
    int i,j,k;
    for (i = 1; i <= 101; i++) {
        d[i] = 100000; //distance INF
        p[i] = 0; //prev NIL
    }
    d[1]=0;
    for(i=1; i<=num_of_vertex-1; i++) {
        for(int u=1; u<=num_of_vertex; u++) {
            for (int v = 1; v <= num_of_vertex; v++) {
                if(graph[u][v]==1) {
                    if(d[v]>d[u]+weight_matrix[u][v]) {
                        d[v]=d[u]+weight_matrix[u][v];
                    }
                }
            }
        }
    }
    bool negative_cycle_flag=false;
    for(int u=1; u<=num_of_vertex; u++) {
        for (int v = 1; v <= num_of_vertex; v++) {
            if(graph[u][v]==1) {
                if(d[v]>d[u]+weight_matrix[u][v]) {
                    negative_cycle_flag=true;
                }
            }
        }
    }
    if(negative_cycle_flag==true) {
        cout<<"Negative cycle detected!"<<endl;
        cout<<"\tSo no shortest path can be obtained." <<endl;
        return;
    }
    ofstream outf("bellman_ford_output.txt");
    outf<<"Bellman Ford Algorithm shortest path:"<<endl;
    cout<<endl<<"Final Distance"<<endl;
    for(i=1; i<=num_of_vertex; i++)
        cout<<i<<"\t";
    cout<<endl;
    for(i=1; i<=num_of_vertex; i++) {
        cout<<d[i]<<"\t";
        outf<<d[i]<<"\t";
    }
}
