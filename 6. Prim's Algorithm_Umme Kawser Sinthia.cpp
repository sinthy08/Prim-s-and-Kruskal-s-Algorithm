///Umme Kawser Sinthia
///Roll: 201136

#include<bits/stdc++.h>
#define size 10
#define MAX 9999
using namespace std;
void Read_Input ();
void Print_All();
int Prim();
int vertex, arr[size][size], span[size][size];
int weight[size][size];

int main()
{
   Read_Input();
   Print_All();

    return 0;
}

int Prim()
{
	int i, j, u, v, min_distance, distance[size], from[size];
	int visited[size], edge_no, min_weight = 0, count = 0;

	//initializing weight[][] and span[][] matrix
	for(i = 0; i < vertex; i++)
		for(j = 0; j < vertex; j++)
		{
			if (arr[i][j] == 0)
				weight[i][j] = MAX;
			else
			{
				weight[i][j] = arr[i][j];
			    span[i][j] = 0;
			}
		}

	//initialise visited[],distance[] and from[]
	distance[0] = 0;
	visited[0] = 1;

	for(i = 1; i < vertex; i++)
	{
		distance[i] = weight[0][i];
		from[i] = 0;
		visited[i] = 0;
	}

	edge_no = vertex-1;		//no. of edges to be added


    cout<< endl << "Total weight of the graph using Prim's Algorithm: " ;

	while(edge_no > 0)
	{
		//find the vertex at minimum distance from the tree
		min_distance = MAX;
		for(i = 1; i < vertex; i++)
			if(visited[i] == 0 && distance[i] < min_distance)
			{
				v = i;
				min_distance = distance[i];
			}

		u = from[v];

		//insert the edge in span tree
		span[u][v] = distance[v];
		span[v][u] = distance[v];
		edge_no--;
		visited[v] = 1;

		//updated the distance[] array
		for(i = 1; i < vertex; i++)
			if(visited[i] == 0 && weight[i][v] < distance[i])
			{
				distance[i] = weight[i][v];
				from[i] = v;
			}

			count++;
			if(count < vertex-1 )
			    cout << weight[u][v] << " + ";
            else
                cout << weight[u][v] << " = " ;


		min_weight += weight[u][v];
	}

	return(min_weight);
}

void Print_All()
{
    int total;

    total = Prim();
     cout << total << endl;
    cout << "Minimun spanning tree adjacency matrix: "<< endl;
    for (int i = 0; i < vertex ; i++ )
    {
        for (int j = 0 ; j < vertex ; j++)
        {
            cout << span[i][j] << " ";
        }
        cout << endl;
    }



}

void Read_Input ()
{
    int i,j;
    cout << "Enter number of vertices: ";
    cin >> vertex;

	cout << "Enter the adjecency matrix of the graph: " << endl;

	for( i = 0 ; i < vertex ; i++ )
        for( j = 0 ; j < vertex ; j++ )
		    cin >> arr[i][j];

}


/*
6
0 3 1 6 0 0
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0
*/

