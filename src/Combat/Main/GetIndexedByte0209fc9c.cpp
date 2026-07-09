#include <globaldefs.h>

struct Context0209fc9c {
    char pad0[4];
    char* data;
};

// USA: func_0209fc9c
ARM int GetIndexedByte0209fc9c(struct Context0209fc9c* ctx, int index) {
    unsigned char* arr = (unsigned char*)(ctx->data + 0x8d5c);
    if (arr == NULL) {
        return 0;
    }
    if (index < 0 && index >= 10) {
        return 0;
    }
    return arr[index];
}
