import random
from queue import PriorityQueue

def generate_random_graph(n):
    graph = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            graph[i][j] = graph[j][i] = random.randint(1, 100)
    return graph

def beam_search(graph, start, beam_width):
    n = len(graph)
    queue = PriorityQueue()
    queue.put((0, [start]))
    while not queue.empty():
        cost, path = queue.get()
        last = path[-1]
        if len(path) == n:
            return path
        next_nodes = []
        for i in range(n):
            if i not in path:
                next_cost = cost + graph[last][i]
                next_nodes.append((next_cost, i))
        next_nodes.sort(key=lambda x: x[0])
        for i in range(min(beam_width, len(next_nodes))):
            next_cost, next_node = next_nodes[i]
            new_path = path + [next_node]
            queue.put((next_cost, new_path))

n = 4
graph = generate_random_graph(n)
print(f'Graph: {graph}')
start = 0
beam_width = 2
path = beam_search(graph, start, beam_width)
print(f'Path: {path}')
