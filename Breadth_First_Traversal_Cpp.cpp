#include <iostream>
#include <list>

using namespace std;

class createGraph {
  int totalVertices;
  list<int>* adj;
  bool* isVisited;
   public:
  createGraph(int vertices);
  void addEdge(int src, int dest);
  void breadthFirstSearch(int startVertex);
};


createGraph::createGraph(int vertices) {
  totalVertices = vertices;
  adj = new list<int>[vertices];
}

void createGraph::addEdge(int src, int dest) {
  adj[src].push_back(dest);
  adj[dest].push_back(src);
}

void createGraph::breadthFirstSearch(int startVertex) {
  isVisited = new bool[totalVertices];
  for (int i = 0; i < totalVertices; i++)
    isVisited[i] = false;

  list<int> queue;

  isVisited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout << "isVisited " << currVertex << " ";
    queue.pop_front();

    for (i = adj[currVertex].begin(); i != adj[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!isVisited[adjVertex]) {
        isVisited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

int main() {
  createGraph graph(6);

  graph.addEdge('P', 'Q');
  graph.addEdge('P', 'S');
  graph.addEdge('P', 'T');
  graph.addEdge('Q', 'R');
  graph.addEdge('Q', 'R');
  graph.addEdge('T', 'U');
  graph.addEdge('T', 'R');
  graph.addEdge('R', 'U');

  graph.breadthFirstSearch(2);

  return 0;
}
