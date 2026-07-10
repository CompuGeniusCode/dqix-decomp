#include <globaldefs.h>

int CountEntriesType1WithId(int);

// USA: func_0209ca2c
ARM int IsAnimationActive0209ca2c(void* obj) {
    short handle = *(short*)((char*)obj + 0xce);
    if (handle < 0) return 0;
    if (*(unsigned char*)((char*)obj + 0xc9) != 0) return 1;
    return CountEntriesType1WithId(handle) > 0;
}
