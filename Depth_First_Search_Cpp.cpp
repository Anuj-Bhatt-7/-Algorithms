#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
	map<int, bool> isVisited;
	map<int, list<int> > adj;

	void addNewEdge(int v, int w );

	void depthFirstSearch(int v);
};

void Graph::addNewEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::depthFirstSearch(int v){
	isVisited[v] = true;
	cout << v << " ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!isVisited[*i])
			depthFirstSearch(*i);
}

int main(){
	Graph graph;
	graph.addNewEdge(0, 1);
	graph.addNewEdge(0, 2);
	graph.addNewEdge(1, 2);
	graph.addNewEdge(2, 0);
	graph.addNewEdge(2, 3);
	graph.addNewEdge(3, 3);

	cout << "Depth First Traversal(starting from vertex 2)"<<endl;
	graph.depthFirstSearch(2);

	return 0;
}



