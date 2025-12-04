#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], n;

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 1; i <= n; i++) visited[i] = 0;
    printf("BFS: ");
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
}

void DFS_Util(int u) {
    visited[u] = 1;
    printf("%d ", u);
    for (int v = 1; v <= n; v++)
        if (graph[u][v] && !visited[v])
            DFS_Util(v);
}

void DFS(int start) {
    for (int i = 1; i <= n; i++) visited[i] = 0;
    printf("DFS: ");
    DFS_Util(start);
    printf("\n");
}

int parent[MAX];

int find(int i) {
    while (parent[i] != i) i = parent[i];
    return i;
}

void union_set(int a, int b) {
    int x = find(a);
    int y = find(b);
    parent[x] = y;
}

void Kruskal() {
    int edges = 0, min, a, b, u, v, total = 0;
    for (int i = 1; i <= n; i++) parent[i] = i;
    printf("Kruskal MST:\n");

    while (edges < n - 1) {
        min = INT_MAX;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (graph[i][j] && find(i) != find(j) && graph[i][j] < min) {
                    min = graph[i][j];
                    a = u = i;
                    b = v = j;
                }

        union_set(u, v);
        printf("%d -- %d  weight = %d\n", a, b, min);
        total += min;
        edges++;
    }
    printf("Total cost = %d\n", total);
}

void Prim() {
    int selected[MAX] = {0};
    selected[1] = 1;
    int edges = 0, total = 0;

    printf("Prim MST:\n");

    while (edges < n - 1) {
        int min = INT_MAX, x = 0, y = 0;
        for (int i = 1; i <= n; i++)
            if (selected[i])
                for (int j = 1; j <= n; j++)
                    if (!selected[j] && graph[i][j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }

        printf("%d -- %d  weight = %d\n", x, y, min);
        total += min;
        selected[y] = 1;
        edges++;
    }
    printf("Total cost = %d\n", total);
}

void Dijkstra(int start) {
    int dist[MAX], visitedD[MAX] = {0};
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[start] = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1, min = INT_MAX;

        for (int i = 1; i <= n; i++)
            if (!visitedD[i] && dist[i] < min)
                min = dist[i], u = i;

        visitedD[u] = 1;

        for (int v = 1; v <= n; v++)
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Dijkstra shortest paths from %d:\n", start);
    for (int i = 1; i <= n; i++)
        printf("To %d = %d\n", i, dist[i]);
}

int main() {
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter start vertex: ");
    scanf("%d", &start);

    BFS(start);
    DFS(start);
    Kruskal();
    Prim();
    Dijkstra(start);

    return 0;
}
