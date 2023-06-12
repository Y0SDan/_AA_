import string

class Graph:
    def __init__(self, nodes):
        self.nodes = nodes
        self.graph = [[0 for _ in range(nodes)] for __ in range(nodes)]
        self.letters = string.ascii_uppercase

    def add_edge(self, u, v, weight):
        self.graph[u][v] = weight
        self.graph[v][u] = weight

    def print_graph(self):
        for i in range(self.nodes):
            print(f"{self.letters[i]}: {self.graph[i]}")
            
    def print_node_values(self):
        for i in range(self.nodes):
            print(f"{self.letters[i]}")
            
    def dfs_paths(self, start, goal):
        stack = [(start, [start], 0)]
        while stack:
            (vertex, path, weight) = stack.pop()
            for next in set(range(self.nodes)) - set(path):
                if next == goal:
                    yield (path + [next], weight + self.graph[vertex][next])
                else:
                    stack.append((next, path + [next], weight + self.graph[vertex][next]))

g = Graph(4)
g.add_edge(0, 1, 1)
g.add_edge(0, 2, 2)
g.add_edge(0, 3, 3)
g.add_edge(1, 2, 4)
g.add_edge(1, 3, 5)
g.add_edge(2, 3, 6)

g.print_graph()
print()

start_letter = input("Enter start node letter: ")
goal_letter = input("Enter goal node letter: ")

start = g.letters.index(start_letter.upper())
goal = g.letters.index(goal_letter.upper())

if start == goal:
    print(f"The start and goal nodes are the same: {g.letters[start]}")
else:
    print(f"All paths from {g.letters[start]} to {g.letters[goal]}:")
    min_weight_path = None
    min_weight = float('inf')
    for path in g.dfs_paths(start, goal):
        print(f"{[g.letters[node] for node in path[0]]} with weight {path[1]}")
        if path[1] < min_weight:
            min_weight_path = path
            min_weight = path[1]

    print(f"\nThe shortest path from {g.letters[start]} to {g.letters[goal]} is:")
    print(f"{[g.letters[node] for node in min_weight_path[0]]} with weight {min_weight_path[1]}")
