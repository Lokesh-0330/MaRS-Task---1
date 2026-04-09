# MaRS Recruitment 2026 - Software Task 1 Mission Report
**Candidate:** Lokeshwaran K  
**Roll No:** CS25B1087  
**College:** IIITDM Kancheepuram  

---

## 1. Learning Experience

### Overview
This project involved solving a suite of Martian rover-related programming challenges, ranging from robotics coordinate transformations to autonomous pathfinding. Each challenge required integrating different programming paradigms (C and Python) with core mathematical concepts.

### Key Takeaways
* **Coordinate Frame Transformations:** Learned rigid body transformations in 3D space and how to chain transformation matrices.
* **Signal Processing:** Mastered the difference between mean and median filters, specifically how the Sanchiko (Median) filter provides robustness against outliers (salt-and-pepper noise).
* **Optimization:** Developed an understanding of constrained optimization and Dynamic Programming for finding optimal mechanical configurations with minimum wear.
* **Graph Algorithms:** Mastered BFS (Breadth-First Search) for grid-based pathfinding, ensuring energy-efficient navigation through obstacle-heavy terrain.

---

## 2. Implementation Approach and Solutions

### Easy Dose: Environment Verification
Established a stable development environment using Ubuntu 22.04 LTS (WSL2). Verified system integrity through shell utilities to manage mission-critical data directories.

### Medium Doses: Core Rover Logic
* **Med 1 (Coordinate Transform):** Applied 2D rotation matrices to convert local camera data to the rover’s global frame.
* **Med 2 and 3 (Decryption):** Built a Morse interpreter and a reverse-shift cipher where the shift value was a function of the character's 1-indexed position.
* **Med 4 (Signal Filtering):** Implemented a comparison between Muchiko (Mean) and Sanchiko (Median) filters. The Sanchiko filter was prioritized for its edge-preserving qualities and outlier resistance.
* **Med 5 (Arm Optimization):** Developed a Bottom-Up DP approach to minimize the movement cost of a 3-segment telescopic arm across sequential mission targets.

### Hard Doses: Autonomous Systems
* **Hard 1 (Arena Navigation):** Translated raw relative distance scans into a static 11x11 binary grid for path planning.
* **Hard 2 (Vision):** Applied the Pinhole Camera Model to estimate the physical distance of mission objectives based on perceived pixel width.

---

## 3. Equations, Theorems and Mathematical Foundations

### A. Rotation Matrices (Med 1)
To rotate a point (x', y') by an angle theta around the origin:
$$x = x' \cos(\theta) - y' \sin(\theta)$$
$$y = x' \sin(\theta) + y' \cos(\theta)$$

### B. Cipher Decryption (Med 3)
The position-based shift follows a 1-indexed wrap-around logic:
$$Original = Encrypted - (index + 1)$$
If the result falls below 'A', a circular wrap of 26 is added to maintain alphabet integrity.

### C. Signal Processing - Sanchiko Filter (Med 4)
The Median filter is defined by sorting a window of size n and selecting the middle element:
$$Filtered\_Value = sorted\_window[n/2]$$
This is mathematically robust to outliers compared to the Muchiko (Mean) filter.

### D. BFS Pathfinding (Hard 1)
Implemented Breadth-First Search for shortest-path calculation in an unweighted grid:
1. Enqueue start node.
2. While queue is not empty: dequeue current, if goal found return path, else enqueue unvisited neighbors.

### E. Pinhole Camera Model (Hard 2)
The relationship between real object width W, pixel width w, focal length f, and distance D:
$$D = \frac{W \times f}{w}$$

---

## 4. Challenges Faced

* **Relative Input Interpretation:** Sensor data was relative to (0,0). I had to implement boundary-checking to ignore any obstacles (like those with negative coordinates) that existed outside the mission arena.
* **DP State-Space:** Ensuring the |Inner - Outer| <= D constraint was satisfied at every transition step without making the time complexity exponential.
* **Wrapping Logic:** Handling the edge cases in the shift cipher where characters wrapped around the beginning of the alphabet required explicit modulo-style logic.

---

## 5. Terminal Outputs (Mission Logs)

### 
