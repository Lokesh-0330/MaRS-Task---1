#include <stdio.h>

// Simple function to find the median of 3 numbers
int get_median(int a, int b, int c) {
    if ((a <= b && b <= c) || (c <= b && b <= a)) return b;
    if ((b <= a && a <= c) || (c <= a && a <= b)) return a;
    return c;
}

int main() {
    int sensor_data[] = {4, 7, 6, 1, 8}; // Example input
    int n = sizeof(sensor_data) / sizeof(sensor_data[0]);
    
    printf("Sanchiko Filter Output: ");
    
    // Loop through data with a window of 3
    for (int i = 0; i <= n - 3; i++) {
        int median = get_median(sensor_data[i], sensor_data[i+1], sensor_data[i+2]);
        printf("%d ", median);
    }
    
    printf("\n");
    return 0;
}