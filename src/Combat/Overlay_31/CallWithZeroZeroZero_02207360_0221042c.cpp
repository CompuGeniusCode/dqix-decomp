#include <globaldefs.h>

extern void* data_ov031_0224e588;
extern "C" void func_ov031_02210358(int a, int b);
ARM int CallWithZeroZeroZero_02207360(int a, int b, int c);

// USA: func_ov031_0221042c  (semantic: ReceiveIntoBuffer_0221042c)
extern "C" ARM int func_ov031_0221042c(unsigned char* buf) {
    int n = 0;
    unsigned int processed;
    if (data_ov031_0224e588 == NULL) {
        return n - 0x1c;
    }
    unsigned int total = *(unsigned int*)buf;
    if (total > 0x414) {
        func_ov031_02210358(6, -0x32);
        return ~0x22;
    }
    processed = n;
    if (processed < total) {
        do {
            int handle = *(int*)((char*)data_ov031_0224e588 + 0x1b8);
            n = CallWithZeroZeroZero_02207360(handle, (int)buf, total - processed);
            if (n > 0) {
                processed += n;
                buf += n;
                if (processed >= total) {
                    return processed;
                }
            } else if (n < 0) {
                func_ov031_02210358(6, -0x32);
                return n;
            }
        } while (processed < total);
    }
    return n;
}
