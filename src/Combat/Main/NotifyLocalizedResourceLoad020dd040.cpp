#include <globaldefs.h>

struct Struct020dfc40 {
    unsigned char pad[0x14];
    int field_14;
};

void* ResetAndReturnSelf020dfc2c(void* p);
void ResetStruct020dfc40(struct Struct020dfc40* p);

int ComputeAndApplyWithCounter020e04f4(int p0, void* p1, int p2, int p3, unsigned char p4, int p5);

extern const char data_020f2994[];
extern const char data_020f29a8[];

// USA: func_020dd040
#pragma opt_propagation off
ARM void NotifyLocalizedResourceLoad020dd040(int len, char* buf) {
    if (len > 0 && buf != NULL) {
        struct Struct020dfc40 s;
        void* p1;
        int p5;
        p5 = (int)data_020f2994;
        p1 = (void*)data_020f29a8;
        buf[0] = 0;
        ResetAndReturnSelf020dfc2c(&s);
        ResetStruct020dfc40(&s);
        ComputeAndApplyWithCounter020e04f4((int)buf, p1, len, 0, 1, p5);
    }
}
