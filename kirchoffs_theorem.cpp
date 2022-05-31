//Implementation of Kirchoff's theorem for getting count of no. of spanning trees for
//given graph
//include function to get degree of node, find no. of mst, display, initialization, take input from text file
//step1, step2, step3

#include<iostream>
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

    //initialization of adjacency matrix
    for(i=0; i<n_vertex; i++) for(j=0; j<n_vertex; j++) edge[i][j]=0;

    cout<<"\nFirst enter source then destination\n";
    for(i=0;i<n_edges; i++)
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
            cout<<edge[i][j]<<"  ";
        }
        cout<<"\n";
    }

    //Step-1: main diagonal with 0's will be replaced with degree of node
    cout<<"\n";
    //O(N^2)
    for(i=0; i<n_vertex; i++)
    {
        //if diagonal value is 0
        if(!edge[i][i])
        {
            //calculate degree of node(no. of nodes directly connected with that node)
            int degree=0;
            for(j=0;j<n_vertex;j++)
            {
                if(edge[i][j]) degree++;
            }
            edge[i][i]=degree;
        }
    }

    cout<<"Step-1: main diagonal with 0's will be replaced with degree of node\n";
    for(i=0; i<n_vertex; i++)
    {
        cout<<"V"<<i<<" ";
        for(j=0; j<n_vertex; j++)
        {
            cout<<edge[i][j]<<"  ";
        }
        cout<<"\n";
    }

    //step-2: non-main diagonal 1's should be replaced with -1's
    //O(N^2)
    for(i=0; i<n_vertex; i++)
    {
        for(j=0;j<n_vertex;j++)
        {
            if(i!=j && edge[i][j]==1) edge[i][j]=-1;
        }
    }

    cout<<"\nStep-2: non-main diagonal 1's should be replaced with -1's\n";
    for(i=0; i<n_vertex; i++)
    {
        cout<<"V"<<i<<" ";
        for(j=0; j<n_vertex; j++)
        {
            cout<<edge[i][j]<<"  ";
        }
        cout<<"\n";
    }

    //step-3: find co-factor of any number in matrix
    cout<<"\nstep-3: find co-factor of any number in matrix";
    int co_factor= edge[1][1]*(edge[2][2]*edge[3][3]-edge[2][3]*edge[3][2])
    -edge[1][2]*(edge[2][1]*edge[3][3]-edge[2][3]*edge[3][1])
    + edge[1][3]*(edge[2][1]*edge[3][2]-edge[2][2]*edge[3][1]);

    cout<<"\nCo-factor value is equal to no. of spanning trees possible that is "<<co_factor<<" in our case.\n";

    return 0;
}

