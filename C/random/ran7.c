#include <stdio.h>

union Point { 
    int x, y; 
};

int main() {
    union Point points[3] = {{2, 3}, {4, 5}, {6, 7}};
    
    for (int i = 0; i < 3; i++) {
        printf("\nCoords on point [%d] are %d and %d", i, points[i].x, points[i].y);
    }
    return 0;
}