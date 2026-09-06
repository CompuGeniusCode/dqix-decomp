#include <globaldefs.h>
ARM void TestIdx(unsigned char* arr, unsigned short x) {
    arr[x / 8] |= 1;
}
