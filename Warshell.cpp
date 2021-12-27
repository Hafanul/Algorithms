#include<bits/stdc++.h>

using namespace std;

int num_of_vertex, graph[101][101] = { };
int weight_matrix[101][101] = { },d[101][101]= { };

void warshall();

int main()
{
    ifstream inf("warshall_input.txt");

    int a, b, i = 1, j=1, m, n, wait;

    inf>>num_of_vertex;

    for(i=1; i<=num_of_vertex; i++) {
        for(j=1; j<=num_of_vertex; j++) {
            inf>>wait;
            weight_matrix[i][j]=wait;
        }
    }
    inf.close();

    cout << "The Weight Matrix is:" << endl;
    for (m = 1; m <= num_of_vertex; m++) {
        for (n = 1; n <= num_of_vertex; n++) {
            cout << setw(10) << weight_matrix[m][n] ;
        }
        cout << endl;
    }

    warshall();

    return 0;

}
void warshall()
{
    int i,j,k;

    for(i=1; i<=num_of_vertex; i++)
    {
        for(j=1; j<=num_of_vertex; j++)
        {
            d[i][j]=weight_matrix[i][j];
        }
    }

    for(k=1; k<=num_of_vertex; k++)
    {
        bool change_flag = false;

        for(i=1; i<=num_of_vertex; i++)
        {
            for(j=1; j<=num_of_vertex; j++)
            {
                if(d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    change_flag = true;
                }
            }
        }

        cout<<"L("<<k<<"):"<<endl;
        for(i=1; i<=num_of_vertex; i++) {
            for(j=1; j<=num_of_vertex; j++) {
                cout<<setw(10)<<d[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
        if(change_flag==false) {
            break;
        }
    }
    ofstream outf("warshall_output.txt");
    outf<<"Warshall Algorithm all pair shortest path:"<<endl;
    cout<<endl<<"Final weight matrix:"<<endl;
    for(i=1; i<=num_of_vertex; i++) {
        for(j=1; j<=num_of_vertex; j++) {
            cout<<setw(10)<<d[i][j]<<"\t";
            outf<<setw(10)<<d[i][j]<<"\t";
        }
        cout<<endl;
        outf<<endl;
    }
    outf.close();
}
