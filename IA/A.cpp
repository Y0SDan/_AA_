#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <math.h>

// This structure represents a node in the graph.
struct Node {
 int x;
 int y;
 int cost;
 std::set<Node*> neighbors;
};

// This function returns the distance between two points.
int distance(int x1, int y1, int x2, int y2) {
 return abs(x1 - x2) + abs(y1 - y2);
}

// This function returns the euclidean distance between two points.
int heuristic(int x1, int y1, int x2, int y2) {
 return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// This function implements the A* algorithm.
int astar(Node *start, Node *goal) {
 // Create a set to store the open nodes.
 // The open nodes are the nodes that have not yet been explored.
 std::set<Node*> open;

 // Add the start node to the open set.
 open.insert(start);

 // Create a set to store the closed nodes.
 // The closed nodes are the nodes that have already been explored.
 std::set<Node*> closed;

 // While the open set is not empty, do the following:
 while (!open.empty()) {
 // Select the node in the open set with the lowest estimated cost.
 Node *current = *open.begin();
 for (Node *node : open) {
 if (node->cost + heuristic(node->x, node->y, goal->x, goal->y) < current->cost + heuristic(current->x, current->y, goal->x, goal->y)) {
 current = node;
 }
 }
 open.erase(current);

 // If the current node is the goal node, then stop.
 if (current == goal) {
 return current->cost;
 }

 // Add the current node to the closed set.
 closed.insert(current);

 // For each neighbor of the current node, do the following:
 for (Node *neighbor : current->neighbors) {
 // If the neighbor is not in the closed set, do the following:
 if (!closed.count(neighbor)) {
 // Calculate the estimated cost of the path from the start node to the neighbor.
 int estimated_cost = current->cost + distance(current->x, current->y, neighbor->x, neighbor->y);

 // If the neighbor is not in the open set, or if the estimated cost of the path from the start node to the neighbor is less than the estimated cost of the path from the start node to the neighbor in the open set, do the following:
 if (!open.count(neighbor) || estimated_cost < neighbor->cost) {
 // Update the cost of the neighbor.
 neighbor->cost = estimated_cost;

 // Add the neighbor to the open set.
 open.insert(neighbor);
 }
 }
 }
 }

 // If the open set is empty, then there is no path from the start node to the goal node.
 return -1;
}

int main() {
 // Create the start node.
 Node start = {0, 0};

 // Create the goal node.
 Node goal = {10, 10};

 // Find the shortest path from the start node to the goal node.
 int cost = astar(&start, &goal);

 // Print the cost of the path.
 printf("The cost of the path is %d\n", cost);

 return 0;
}
