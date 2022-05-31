
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    //input no. of vertex
    int n_vertex=0;
    cout<<"Enter no. of vertex: ";
    cin>>n_vertex;

    //input no. of edges
    int n_edges=0;
    cout<<"Enter no. of edges: ";
    cin>>n_edges;

    //input edges
    int edge[n_vertex][n_vertex],i=0,source=0,destiny=0,j=0;
    cout<<"\nFirst enter source then destination\n";
    for(;i<n_edges; i++)
    {
        cin>>source>>destiny;
        edge[source][destiny]= 1;
        edge[destiny][source]= 1;
    }

    cout<<"\nAdjacency Matrix\n";
    cout<<"V  ";
    for(i=0; i<n_vertex; i++) cout<<"V"<<i<<" ";
    cout<<"\n";

    for(i=0; i<n_vertex; i++)
    {
        cout<<"V"<<i<<" ";
        for(j=0; j<n_vertex; j++)
        {
            //if edge does not exist between i and jth vertex
            if(edge[i][j]!=1) edge[i][j]=0;
            cout<<edge[i][j]<<"  ";
        }
        cout<<"\n";
    }

    //check for self loop
    cout<<"\n";
    for(i=0; i<n_vertex; i++)
    {
        if(edge[i][i]==1) cout<<"Self loop on node "<<i<<"\n";
    }

    return 0;
}

/*Sample Output 1
Enter no. of vertex: 5
Enter no. of edges: 6

First enter source then destination
0 1
0 4
1 3
1 2
3 4
2 3

Adjacency Matrix
V  V0 V1 V2 V3 V4
V0 0  1  0  0  1
V1 1  0  1  1  0
V2 0  1  0  1  0
V3 0  1  1  0  1
V4 1  0  0  1  0
*/