#include <globaldefs.h>

ARM int TestBitAt0x34(unsigned char* obj, unsigned int index);

// USA: func_020a3634
ARM int CollectSetBitIndicesAt0x34(unsigned char* obj, short* outArray) {
    int i;
    int outCount = 0;
    for (i = 0; i < 4; i++) {
        if (TestBitAt0x34(obj, (unsigned char)i)) {
            outArray[outCount] = i;
            outCount++;
        }
    }
    return outCount;
}
