#include <globaldefs.h>

struct CopyPayload {
    char data[0x30];
};

struct CopyableRecord {
    struct CopyPayload payload;
    short f30;
    signed char f32;
    unsigned char f33;
};

void ClearRegion02093980(char* obj);
void CopyRecord(struct CopyableRecord* dst, struct CopyableRecord* src);

// USA: func_02093ad8  (semantic: ResetAndCopyRecords02093ad8)
extern "C" ARM void func_02093ad8(void* unused, struct CopyableRecord* b, struct CopyableRecord* c, int count) {
    int i;
    for (i = 0; i < 8; i++) {
        ClearRegion02093980((char*)(c + i));
    }
    int j;
    for (j = 0; j < count; j++) {
        CopyRecord(c + j, b + j);
    }
    int k;
    for (k = 0; k < 8; k++) {
        ClearRegion02093980((char*)(b + k));
    }
}
