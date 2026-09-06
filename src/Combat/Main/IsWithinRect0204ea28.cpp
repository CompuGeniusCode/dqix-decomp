#include <globaldefs.h>

// USA: func_0204ea28
ARM int IsWithinRect0204ea28(int x, int y, int minX, int minY, short maxX, short maxY) {
    int result = 0;
    if (minX <= x && x < maxX && minY <= y && y < maxY) {
        result = 1;
    }
    return result;
}
