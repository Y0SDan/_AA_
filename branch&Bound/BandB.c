#include <stdio.h>
#include <limits.h>

// Number of workers and jobs
#define N 3

int minCost = INT_MAX;

// Function to allocate jobs to workers using Branch and Bound
void allocateJobs(int costMatrix[N][N], int assigned[N], int cost, int worker)
{
    // Base case: all workers are assigned a job
    if (worker == N) {
        if (cost < minCost) {
            minCost = cost;
        }
        return;
    }

    // Consider assigning each job to the current worker and recur for the remaining workers
    for (int job = 0; job < N; job++) {
        // Proceed only if the job is not assigned to any worker yet
        if (assigned[job] == 0) {
            // Calculate the cost of assigning the current job to the current worker
            int currCost = costMatrix[worker][job];

            // Prune the search space if the current cost + lower bound is greater than the minimum cost so far
            if (cost + currCost + (N - worker - 1) * minCost >= minCost) {
                continue;
            }

            // Assign the current job to the current worker
            assigned[job] = worker + 1;

            // Recur for the next worker
            allocateJobs(costMatrix, assigned, cost + currCost, worker + 1);

            // Backtrack: unassign the current job from the current worker and try the next job
            assigned[job] = 0;
        }
    }
}

int main()
{
    int costMatrix[N][N] = {{9, 3, 4}, {7, 8, 4}, {10, 5, 2}};

    // Create an array to keep track of the jobs assigned to each worker
    int assigned[N] = {0};

    // Allocate jobs to workers using Branch and Bound
    allocateJobs(costMatrix, assigned, 0, 0);

    printf("Minimum cost: %d\n", minCost);

    return 0;
}