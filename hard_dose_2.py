import math

def calculate_distance():
    # Known mission parameters
    # Assuming standard arrow width of 30cm (0.3m)
    REAL_WIDTH = 0.3  
    # Diagonal Field of View (FOV) provided in task specs (e.g., 78 degrees)
    FOV_DEGREES = 78.0  
    # Image width in pixels (standard HD)
    IMAGE_WIDTH_PX = 1920 
    
    # Input from your sensor/image processing
    # Example: The arrow is perceived to be 150 pixels wide
    perceived_width_px = 150 

    # 1. Calculate Focal Length in pixels (f)
    # f = (Image_Width / 2) / tan(FOV / 2)
    fov_rad = math.radians(FOV_DEGREES)
    focal_length_px = (IMAGE_WIDTH_PX / 2) / math.tan(fov_rad / 2)

    # 2. Pinhole Camera Distance Formula
    # Distance (D) = (Real Width * Focal Length) / Perceived Width
    distance = (REAL_WIDTH * focal_length_px) / perceived_width_px

    print(f"--- Hard Dose #2: Vision Report ---")
    print(f"Object: Arrow Objective")
    print(f"Perceived Width: {perceived_width_px} pixels")
    print(f"Calculated Focal Length: {focal_length_px:.2f} px")
    print(f"Estimated Distance to Target: {distance:.2f} meters")

if __name__ == "__main__":
    calculate_distance()