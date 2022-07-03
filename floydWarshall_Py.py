V = 4
INF = 9999

def floydWarshallAlgo(graph):
   
    dist = list(map(lambda i: list(map(lambda j: j, i)), graph))
 
    for k in range(V):

        for i in range(V):

            for j in range(V):
                dist[i][j] = min(dist[i][j],
                                 dist[i][k] + dist[k][j]
                                 )
    display(dist)
 
 

def display(dist):
    print ("Printing result\n")
    for i in range(V):
        for j in range(V):
            if(dist[i][j] == INF):
                print ("%3s" % ("INF"),end=" ")
            else:
                print ("%3d\t" % (dist[i][j]),end=' ')
            if j == V-1:
                print ()
 
graph = [[0, 5, INF, 10],
         [INF, 0, 3, INF],
         [INF, INF, 0,   1],
         [INF, INF, INF, 0]
         ]
floydWarshallAlgo(graph)