class Node:
    def __init__(self, level, assigned_jobs, cost, num_workers):
        self.level = level
        self.assigned_jobs = assigned_jobs
        self.cost = cost
        self.num_workers = num_workers

def min_cost(cost_matrix):
    # inicializar la lista activa
    active_nodes = []
    # crear la raíz del árbol de búsqueda
    root = Node(-1, [], 0, len(cost_matrix))
    # agregar la raíz a la lista activa
    active_nodes.append(root)
    # mientras haya nodos activos
    while active_nodes:
        # encontrar el nodo con el menor costo
        min_cost_node = min(active_nodes, key=lambda x: x.cost)
        # si el nodo es una hoja
        if min_cost_node.level == len(cost_matrix) - 1:
            # imprimir el resultado y salir
            print(min_cost_node.assigned_jobs, min_cost_node.cost)
            return
        # para cada trabajo disponible
        for job in range(len(cost_matrix)):
            # si el trabajo no está asignado a ningún trabajador
            if job not in min_cost_node.assigned_jobs:
                # crear un nuevo nodo
                new_node = Node(min_cost_node.level + 1,
                                min_cost_node.assigned_jobs + [job],
                                min_cost_node.cost + cost_matrix[min_cost_node.level + 1][job],
                                min_cost_node.num_workers)
                # agregar el nuevo nodo a la lista activa
                active_nodes.append(new_node)

cost_matrix = [[9, 3, 4],
               [7, 8, 4],
               [10, 5, 2]]
min_cost(cost_matrix)
