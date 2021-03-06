
class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def createEdge(self, u, v, w):
        self.graph.append([u, v, w])

    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])

    def apply_union(self, parent, rank, x, y):
        xroot = self.find(parent, x)
        yroot = self.find(parent, y)
        if rank[xroot] < rank[yroot]:
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot
        else:
            parent[yroot] = xroot
            rank[xroot] += 1

    
    def kruskalAlgorithm(self):
        result = []
        i, e = 0, 0
        self.graph = sorted(self.graph, key=lambda item: item[2])
        parent = []
        rank = []
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        while e < self.V - 1:
            u, v, w = self.graph[i]
            i = i + 1
            x = self.find(parent, u)
            y = self.find(parent, v)
            if x != y:
                e = e + 1
                result.append([u, v, w])
                self.apply_union(parent, rank, x, y)
        for u, v, weight in result:
            print("%d - %d: %d" % (u, v, weight))


graph = Graph(6)
graph.createEdge(0, 1, 4)
graph.createEdge(0, 2, 4)
graph.createEdge(1, 2, 2)
graph.createEdge(1, 0, 4)
graph.createEdge(2, 0, 4)
graph.createEdge(2, 1, 2)
graph.createEdge(2, 3, 3)
graph.createEdge(2, 5, 2)
graph.createEdge(2, 4, 4)
graph.createEdge(3, 2, 3)
graph.createEdge(3, 4, 3)
graph.createEdge(4, 2, 4)
graph.createEdge(4, 3, 3)
graph.createEdge(5, 2, 2)
graph.createEdge(5, 4, 3)
graph.kruskalAlgorithm()