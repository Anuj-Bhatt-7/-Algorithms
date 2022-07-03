class Graph:

	def __init__(self, vertices):
		self.V = vertices
		self.graph = []
	def createEdge(self, u, v, w):
		self.graph.append([u, v, w])
		
	def display(self, dist):
		print("Vertex \t\t Distance from Source")
		for i in range(self.V):
			print("{0}\t\t{1}".format(i, dist[i]))


	def bellmanFordAlgo(self, src):
		dist = [float("Inf")] * self.V
		dist[src] = 0
		for _ in range(self.V - 1):
			for u, v, w in self.graph:
				if dist[u] != float("Inf") and dist[u] + w < dist[v]:
						dist[v] = dist[u] + w

		for u, v, w in self.graph:
				if dist[u] != float("Inf") and dist[u] + w < dist[v]:
						print("Graph contains negative weight cycle")
						return
		self.display(dist)

graph = Graph(5)
graph.createEdge(0, 1, -1)
graph.createEdge(0, 2, 4)
graph.createEdge(1, 2, 3)
graph.createEdge(1, 3, 2)
graph.createEdge(1, 4, 2)
graph.createEdge(3, 2, 5)
graph.createEdge(3, 1, 1)
graph.createEdge(4, 3, -3)
graph.bellmanFordAlgo(0)
