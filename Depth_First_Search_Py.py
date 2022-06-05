from collections import defaultdict

class Graph:


	def __init__(self):
		self.graph = defaultdict(list)

	def addNewEdge(self, u, v):
		self.graph[u].append(v)

	def DFSUtil(self, v, isVisited):
		isVisited.add(v)
		print(v, end=' ')
		for adjacent in self.graph[v]:
			if adjacent not in isVisited:
				self.DFSUtil(adjacent, isVisited)

	def depthFirstSearch(self, v):
		isVisited = set()
		self.DFSUtil(v, isVisited)


graph = Graph()
graph.addNewEdge(0, 1)
graph.addNewEdge(0, 2)
graph.addNewEdge(1, 2)
graph.addNewEdge(2, 0)
graph.addNewEdge(2, 3)
graph.addNewEdge(3, 3)

print("Depth First Search(starting from vertex 2)")
graph.depthFirstSearch(2)

