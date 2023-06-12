#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 6
#define COLS 6

typedef struct Node {
    int x;
    int y;
    int g;
    int h;
    int f;
    struct Node* parent;
} Node;

int startX, startY, endX, endY;

int calculateManhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int isValidNode(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

int isObstacle(int matrix[ROWS][COLS], int x, int y) {
    return (matrix[x][y] == 0);
}

int isDestination(int x, int y) {
    return (x == endX && y == endY);
}

Node* createNode(int x, int y, int g, int h, struct Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->g = g;
    newNode->h = h;
    newNode->f = g + h;
    newNode->parent = parent;
    return newNode;
}

void buildPath(Node* currentNode, int matrix[ROWS][COLS]) {
    while (currentNode != NULL) {
        matrix[currentNode->x][currentNode->y] = 2;
        currentNode = currentNode->parent;
    }
}

Node* findMinFNode(Node* openList[]) {
    int minF = openList[0]->f;
    int index = 0;
    
    for (int i = 1; i < ROWS * COLS; i++) {
        if (openList[i] != NULL && openList[i]->f < minF) {
            minF = openList[i]->f;
            index = i;
        }
    }
    
    return openList[index];
}

int isInOpenList(Node* openList[], int x, int y) {
    for (int i = 0; i < ROWS * COLS; i++) {
        if (openList[i] != NULL && openList[i]->x == x && openList[i]->y == y) {
            return 1;
        }
    }
    
    return 0;
}

int isInClosedList(Node* closedList[], int x, int y) {
    for (int i = 0; i < ROWS * COLS; i++) {
        if (closedList[i] != NULL && closedList[i]->x == x && closedList[i]->y == y) {
            return 1;
        }
    }
    
    return 0;
}

void AStarAlgorithm(int matrix[ROWS][COLS]) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    Node* openList[ROWS * COLS] = {NULL};
    Node* closedList[ROWS * COLS] = {NULL};
    
    Node* startNode = createNode(startX, startY, 0, 0, NULL);
    openList[0] = startNode;
    
    while (1) {
        Node* currentNode = findMinFNode(openList);
        
        for (int i = 0; i < ROWS * COLS; i++) {
            if (openList[i] != NULL && openList[i]->x == currentNode->x && openList[i]->y == currentNode->y) {
                closedList[i] = currentNode;
                openList[i] = NULL;
                break;
            }
        }
        
        if (isDestination(currentNode->x, currentNode->y)) {
            buildPath(currentNode, matrix);
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int newX = currentNode->x + dx[i];
            int newY = currentNode->y + dy[i];
            
            if (isValidNode(newX, newY) && !isObstacle(matrix, newX, newY)) {
                int newG = currentNode->g + 1;
                int newH = calculateManhattanDistance(newX, newY, endX, endY);
                int newF = newG + newH;
                
                if (isInClosedList(closedList, newX, newY)) {
                    continue;
                }
                
                if (isInOpenList(openList, newX, newY)) {
                    Node* existingNode = NULL;
                    for (int j = 0; j < ROWS * COLS; j++) {
                        if (openList[j] != NULL && openList[j]->x == newX && openList[j]->y == newY) {
                            existingNode = openList[j];
                            break;
                        }
                    }
                    
                    if (newF < existingNode->f) {
                        existingNode->g = newG;
                        existingNode->h = newH;
                        existingNode->f = newF;
                        existingNode->parent = currentNode;
                    }
                } else {
                    Node* newNode = createNode(newX, newY, newG, newH, currentNode);
                    
                    for (int j = 0; j < ROWS * COLS; j++) {
                        if (openList[j] == NULL) {
                            openList[j] = newNode;
                            break;
                        }
                    }
                }
            }
        }
        
        if (openList[0] == NULL) {
            printf("No se pudo encontrar una ruta válida.\n");
            return;
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1}
    };
    
    printf("Ingrese las coordenadas de inicio (x, y): ");
    scanf("%d %d", &startX, &startY);
    
    printf("Ingrese las coordenadas de destino (x, y): ");
    scanf("%d %d", &endX, &endY);
    
    if (!isValidNode(startX, startY) || !isValidNode(endX, endY) || isObstacle(matrix, startX, startY) || isObstacle(matrix, endX, endY)) {
        printf("Las coordenadas ingresadas no son válidas.\n");
        return 0;
    }
    
    AStarAlgorithm(matrix);
    printf("Matriz con la mejor ruta:\n");
    printMatrix(matrix);
    
    return 0;
}
