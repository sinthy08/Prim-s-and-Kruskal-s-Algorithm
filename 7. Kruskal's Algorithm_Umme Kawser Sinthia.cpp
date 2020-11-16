///Umme Kawser Sinthia
///Roll: 201136

#include <bits/stdc++.h>
#define MAX 9999
#define size 10
using namespace std;

int root[size], vertex, weight[size][size], span[size][size];

void Read_Input();
void Print_All ();
int Find_Vertex(int i);
void Union_Sameset(int i, int j);
void Kruskal();


int main()
{
    Read_Input();
	Kruskal();
	Print_All();

	return 0;
}

int Find_Vertex(int i)
{
	while (root[i] != i)
		i = root[i];
	return i;
}

void Union_Sameset(int i, int j)
{
    int u, v;

	u = Find_Vertex(i);
	v = Find_Vertex(j);
	root[u] = v;
}

void Kruskal()
{
	int min_Weight = 0; // weight of min MST.
    int i, j, edge_no = 0, min, u, v;

	for(i = 0; i < vertex; i++)
	{
	    for(j = 0; j < vertex; j++)
		{
		    if (weight[i][j] == 0)
				weight[i][j] = INT_MAX;
			else
			    span[i][j] = 0;
		}
	}

	for (int i = 0; i < vertex; i++)
		root[i] = i;


	while (edge_no < vertex - 1)
	{
		min = MAX;
		u = -1;
		v = -1;

		for (int i = 0; i < vertex; i++)
		{
			for (int j = 0; j < vertex; j++)
			{
				if (Find_Vertex(i) != Find_Vertex(j) && weight[i][j] < min)
				{
					min = weight[i][j];
					u = i;
					v = j;
			    }
	    	}
	    }

		Union_Sameset(u, v);

		span[u][v] = min;
		span[v][u] = min;


	    cout << "Edge " << edge_no++ << "(" <<u << "," << v <<") weight: " << min <<endl;
		min_Weight += min;

	}
	cout << "Minimum weight of the spanning tree =  " << min_Weight << endl;
}
void Print_All ()
{
   cout << "The Adjecency Matrix of the Minimum Spanning Tree: " << endl;
    for (int i = 0; i < vertex; i++)
	{
	    for (int j = 0; j < vertex; j++)
	        cout << span[i][j] << " ";
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
        for( j = 0 ; j < vertex; j++ )
		    cin >> weight[i][j];

    cout << "Using Kruskal's Algorithm the Minimum Spaning tree Edges: " << endl;

}

/*
5
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/


