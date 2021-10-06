# BFS traversal in graph using python 
from collections import defaultdict

# graph class
class Graph:
    
	# Constructor
	def __init__(self):
		# dictionary to store graph
		self.graph = defaultdict(list)

	# Funtion to add an edge to graph

	def add_edge(self,u,v):
		self.graph[u].append(v)

	# function for bfs traversal of graph
	def bfs(self, s):

		#Initially mark all the vertices as not visited
		visited = [False] * (max(self.graph) + 1)
        # initilase a queue
		queue = []

		# Mark the source node as visited and push it in queue
		queue.append(s)
		visited[s] = True

		while queue:
			# Dequeue a node from queue and print it
			s = queue.pop(0)
			print (s, end = " ")

			# Traverse through all the adjacent vertices of the dequeued node.
			for i in self.graph[s]:
                # ifadjacent node is not visited, then mark is as visited and push into queue
				if visited[i] == False:
					queue.append(i)
					visited[i] = True

# Creating a graph 
g = Graph()
g.add_edge(0,1)
g.add_edge(1,2)
g.add_edge(2,0)
g.add_edge(3,3)
g.add_edge(0,4)
g.add_edge(4,3)
g.add_edge(5,1)
g.add_edge(5,2)
g.add_edge(4,4)
g.add_edge(3,5)
g.add_edge(4,5)

print ("Breadth First Traversal of the graph with source node as 0")
g.bfs(0)

