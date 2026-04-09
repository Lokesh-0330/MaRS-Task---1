#include <stdio.h>
#include <stdlib.h>

int main() {
    int targets[] = {5, 12, 8}; // Example target positions
    int current_pos = 0;
    int total_cost = 0;

    printf("--- Manipulator Arm Path ---\n");
    for (int i = 0; i < 3; i++) {
        int distance = abs(targets[i] - current_pos);
        
        // Strategy: Use the outer joint (cheapest) for the movement 
        // if it's within its reach, otherwise use middle/inner.
        // For this task, we assume we just calculate the cost to get there.
        int cost = distance * 2; // Using the most efficient joint (Outer)
        
        total_cost += cost;
        printf("Target %d: Moved %d units. Cost: %d\n", i+1, distance, cost);
        current_pos = targets[i];
    }

    printf("Total Mission Cost: %d\n", total_cost);
    return 0;
}
