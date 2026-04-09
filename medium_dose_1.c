#include <stdio.h>
#include <math.h>

// Standard PI value for degree to radian conversion
#define PI 3.14159265358979323846

int main() {
    /* 1. INPUT DATA FROM TASK  */
    // Object in Camera Frame
    double x_cam = 2.0, y_cam = 1.0, z_cam = 3.0; 
    
    // Rover position in World Frame
    double x_rov = 10.0, y_rov = 5.0, z_rov = 0.0; 
    
    // Rover rotation (degrees) - focusing on Z-axis for 2D terrain navigation
    double z_angle = 45.0; 

    /* 2. CORE LOGIC */
    // Convert degrees to radians for math.h functions
    double rad = z_angle * (PI / 180.0);

    // Apply 2D Rotation Matrix for the Z-axis:
    // x_rotated = x*cos(θ) - y*sin(θ)
    // y_rotated = x*sin(θ) + y*cos(θ)
    double x_rot = x_cam * cos(rad) - y_cam * sin(rad);
    double y_rot = x_cam * sin(rad) + y_cam * cos(rad);
    double z_rot = z_cam; // Assuming Z is height and remains constant in this transform

    // Translate rotated coordinates by adding Rover's world position [cite: 66, 73]
    double x_world = x_rot + x_rov;
    double y_world = y_rot + y_rov;
    double z_world = z_rot + z_rov;

    /* 3. OUTPUT [cite: 75-77] */
    printf("--- Coordinate Transformation Result ---\n");
    printf("Object Position in World Frame:\n");
    printf("X_world: %.2f\n", x_world);
    printf("Y_world: %.2f\n", y_world);
    printf("Z_world: %.2f\n", z_world);

    return 0;
}