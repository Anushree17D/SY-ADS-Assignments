#include <stdio.h>
#define V 5

void init(int arr[][V]) {
    int i, j;
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            arr[i][j] = 0;
        }
    }
}

void insertEdge(int arr[][V], int i, int j) {
    arr[i][j] = 1;
    arr[j][i] = 1;  // undirected graph
}

void printAdjMatrix(int arr[][V]) {
    int i, j;
    for(i = 0; i < V; i++) {
        printf("%d: ", i);
        for(j = 0; j < V; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjmatrix[V][V];
    init(adjmatrix);

    insertEdge(adjmatrix, 0, 1);
    insertEdge(adjmatrix, 0, 4);
    insertEdge(adjmatrix, 1, 2);
    insertEdge(adjmatrix, 1, 3);
    insertEdge(adjmatrix, 3, 4);

    printAdjMatrix(adjmatrix);
    return 0;
}
