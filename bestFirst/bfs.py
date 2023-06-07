import string
import random
import numpy as np
from queue import PriorityQueue

def generate_weighted_tree(num_nodes):
    # Crear una matriz de adyacencia vacía
    adjacency_matrix = np.zeros((num_nodes, num_nodes))
    
    # Asignar letras al azar a los nodos
    node_labels = random.sample(list(string.ascii_uppercase), num_nodes)
    
    # Llenar la matriz de adyacencia con pesos aleatorios para formar un árbol
    for i in range(1, num_nodes):
        j = random.randint(0, i-1)
        weight = random.randint(1, 10)
        adjacency_matrix[i][j] = weight
        adjacency_matrix[j][i] = weight
    
    # Imprimir los valores de los nodos
    print("Valores de los nodos:")
    for i in range(num_nodes):
        print(f"Nodo {i}: {node_labels[i]}")
    
    # Imprimir la matriz de adyacencia
    print("Matriz de adyacencia:")
    print(adjacency_matrix)
    
    return adjacency_matrix, node_labels

def best_first_search(graph, node_labels, start_node, target_value):
    visited = []
    queue = PriorityQueue()
    queue.put((0, start_node))
    
    while not queue.empty():
        current_node = queue.get()[1]
        if current_node not in visited:
            visited.append(current_node)
            if node_labels[current_node] == target_value:
                return visited
            neighbors = np.where(graph[current_node] > 0)[0]
            for neighbor in neighbors:
                if neighbor not in visited:
                    weight = graph[current_node][neighbor]
                    queue.put((weight, neighbor))
    
    return None

# Ejemplo de uso
graph, node_labels = generate_weighted_tree(5)

target_value = input("Ingrese una letra a buscar: ")
start_node = 0

path = best_first_search(graph, node_labels, start_node, target_value)

if path is None:
    print(f"El valor {target_value} no se encuentra en el árbol.")
else:
    print(f"El valor {target_value} se encuentra en el árbol.")
    print("Camino recorrido:")
    for node in path:
        print(node_labels[node])
