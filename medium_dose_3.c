#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[] = "NCUW"; // Example input [cite: 91]
    int len = strlen(input);
    
    printf("Decoded Output: ");
    for (int i = 0; i < len; i++) {
        // Step 1: Convert to uppercase 
        char c = toupper(input[i]);
        
        // Step 2: Determine shift based on 0-based index (shift = index + 1)
        int shift = i + 1;
        
        /* Step 3: Reverse the shift. 
           We add 26 before the modulo to handle negative results 
           (e.g., if 'A' is shifted back). */
        char decoded = ((c - 'A' - (shift % 26) + 26) % 26) + 'A';
        
        printf("%c", decoded);
    }
    printf("\n"); // Result: MARS [cite: 95]
    
    return 0;
}