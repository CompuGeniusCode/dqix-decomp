#include <globaldefs.h>

extern void* data_ov031_0224e588;
extern "C" void func_ov031_02210358(int, int);
int CallWithZeroZeroZero_02207360(int a, int b, int c);

// USA: func_ov031_0221042c
extern "C" ARM int ReadIntoBuffer_0221042c(char* buf) {
    int len;
    int result = 0;
    if (data_ov031_0224e588 == 0) return result - 0x1c;
    len = *(int*)buf;
    if ((unsigned int)len > 0x414) {
        func_ov031_02210358(6, -0x32);
        return ~0x22;
    }
    int total = result;
    if (len <= 0) return result;
    do {
        int field = *(int*)((char*)data_ov031_0224e588 + 0x1b8);
        result = CallWithZeroZeroZero_02207360(field, (int)buf, len - total);
        if (result > 0) {
            total += result;
            buf += result;
            if (total >= len) return total;
        } else if (result < 0) {
            func_ov031_02210358(6, -0x32);
            return result;
        }
    } while (total < len);
    return result;
}
