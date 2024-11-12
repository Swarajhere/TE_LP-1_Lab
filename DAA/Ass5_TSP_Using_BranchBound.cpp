#include <iostream>
#include <vector>
#include <limits>
#include <cstring>

using namespace std;

const int INF = numeric_limits<int>::max(); // Represent infinity for unreachable paths

// Function to perform row and column reduction to minimize the cost matrix
void reduceMatrix(int **cost, int N) {
    // Row reduction
    for (int i = 0; i < N; i++) {
        int rowMin = INF;
        for (int j = 0; j < N; j++) {
            if (cost[i][j] < rowMin) rowMin = cost[i][j];
        }
        if (rowMin != INF) {
            for (int j = 0; j < N; j++) {
                if (cost[i][j] != INF) cost[i][j] -= rowMin;
            }
        }
    }

    // Column reduction
    for (int j = 0; j < N; j++) {
        int colMin = INF;
        for (int i = 0; i < N; i++) {
            if (cost[i][j] < colMin) colMin = cost[i][j];
        }
        if (colMin != INF) {
            for (int i = 0; i < N; i++) {
                if (cost[i][j] != INF) cost[i][j] -= colMin;
            }
        }
    }
}

// Recursive Branch and Bound TSP function
void tsp(int **cost, vector<bool> &visited, int currCity, int currCost, int &minCost, vector<int> &path, vector<int> &bestPath, int N, int level) {
    // Base case: all cities visited, add cost to return to start
    if (level == N) {
        int totalCost = currCost + cost[currCity][0]; // Complete cycle
        if (totalCost < minCost) {
            minCost = totalCost;
            bestPath = path;
            bestPath.push_back(0); // Include return to starting city
        }
        return;
    }

    // Try visiting all unvisited cities
    for (int i = 0; i < N; i++) {
        if (!visited[i] && cost[currCity][i] != INF) { // If city is unvisited and reachable
            int newCost = currCost + cost[currCity][i];

            if (newCost < minCost) { // Prune paths with higher cost than minimum found
                visited[i] = true;
                path.push_back(i);

                tsp(cost, visited, i, newCost, minCost, path, bestPath, N, level + 1);

                // Backtrack
                visited[i] = false;
                path.pop_back();
            }
        }
    }
}

int main() {
    int N;
    cout << "Enter the number of cities: ";
    cin >> N;

    // Define cost matrix
    int **cost = new int *[N];
    for (int i = 0; i < N; i++) {
        cost[i] = new int[N];
        for (int j = 0; j < N; j++) {
            cout << "Enter cost between city " << i + 1 << " and " << j + 1 << ": ";
            cin >> cost[i][j];
            if (i == j) cost[i][j] = INF; // No self-loop in TSP
        }
    }

    // Reduce the matrix initially
    reduceMatrix(cost, N);

    vector<bool> visited(N, false);
    visited[0] = true; // Start from city 0

    int minCost = INF;
    vector<int> path = {0}; // Path starting from city 0
    vector<int> bestPath;   // Store the optimal path

    // Start Branch and Bound TSP
    tsp(cost, visited, 0, 0, minCost, path, bestPath, N, 1);

    // Output result
    cout << "Minimum cost of traveling all cities: " << minCost << endl;
    cout << "Optimal Path: ";
    for (int city : bestPath) {
        cout << city + 1 << " ";
    }
    cout << endl;

    // Clean up dynamic memory
    for (int i = 0; i < N; i++) {
        delete[] cost[i];
    }
    delete[] cost;

    return 0;
}
