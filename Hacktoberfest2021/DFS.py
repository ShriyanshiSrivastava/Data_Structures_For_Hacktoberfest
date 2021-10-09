# DFS traversal in graph using python 
from collections import defaultdict

# graph class
class Graph:

	# Constructor
	def __init__(self):
		# default dictionary to store graph
		self.graph = defaultdict(list)

	# Funtion to add an edge to graph
	def add_edge(self, u, v):
		self.graph[u].append(v)

	# function for dfs traversal of graph
	def helper(self, v, visited):

		# Mark the current node as visited
		visited.add(v)
		print(v, end=' ')

		# Traverse through all the adjacent vertices
		for neighbour in self.graph[v]:
			if neighbour not in visited:
				self.helper(neighbour, visited)

    #DFS function

	def DFS(self, v):

		# set to store visited vertices
		visited = set()
		self.helper(v, visited)

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

print ("Depth First Traversal of the graph with source node as 0")
g.DFS(4)

