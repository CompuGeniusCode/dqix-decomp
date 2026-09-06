#include <globaldefs.h>

struct Struct020dfc40;
void ResetStruct020dfc40(Struct020dfc40* p);
void* ResetAndReturnSelf020dfc2c(void* p);
int ComputeAndApplyWithCounter020e04f4(int p0, void* p1, int p2, int p3, unsigned char p4, int p5);

extern int data_020f2a3c;
extern int data_020f2a24;

struct LocalBuf020dcfc8 { unsigned char pad[0x18]; };

// USA: func_020dcfc8
ARM void NotifyLocalizedResourceLoad020dcfc8(int len, char* buf) {
    if (len > 0 && buf != NULL) {
        LocalBuf020dcfc8 local;
        int v2, v1;
        buf[0] = 0;
        v1 = data_020f2a3c;
        v2 = data_020f2a24;
        ResetAndReturnSelf020dfc2c(&local);
        ResetStruct020dfc40((Struct020dfc40*)&local);
        ComputeAndApplyWithCounter020e04f4((int)buf, (void*)v2, len, 0, 1, v1);
    }
}
