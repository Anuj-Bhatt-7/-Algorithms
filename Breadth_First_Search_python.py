import collections


def breadthFirstSearch(graph, root):
    isVisited, queue = set(), collections.deque([root])
    isVisited.add(root)

    while queue:
        vertex = queue.popleft()
        print(str(vertex) + " ", end="")

        for adjacent in graph[vertex]:
            if adjacent not in isVisited:
                isVisited.add(adjacent)
                queue.append(adjacent)


if __name__ == '__main__':
    
    graph = {0: [1, 2], 1: [2], 2: [3], 3: [1, 2]}
    print("Breadth First Traversal: ")
    breadthFirstSearch(graph, 0)
