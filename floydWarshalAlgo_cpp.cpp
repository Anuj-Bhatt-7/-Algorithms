#include <bits/stdc++.h>
using namespace std;
 

#define V 4
 
#define INF 999
 
void display(int dist[][V]);
 

void floydWarshallAlgo(int graph[][V])
{
  
    int dist[V][V], i, j, k;
 

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
 
   
    for (k = 0; k < V; k++) {
       
        for (i = 0; i < V; i++) {
          
            for (j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    display(dist);
}
 
void display(int dist[][V])
{
    cout << "Printing Result"<<endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "Inf"
                     << "   ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}

int main()
{
  
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
 
    floydWarshallAlgo(graph);
    return 0;
}
