#include <globaldefs.h>
extern "C" int Disp(void*, int);
extern "C" void* g1(void);
extern "C" int g2(int*);
extern "C" int g3(void*);
extern "C" void* g4(void*, int);
extern "C" short* g5(void*, int);
extern "C" void* g6(void*, int);
extern "C" int g7(void*);
extern "C" void e(int,int,int,int);
extern "C" void h1(void*,int);
extern "C" void h2(void*,int);

struct SearchStruct;
int TestFlagBitAt0xe(struct SearchStruct*, int);
struct Combined { unsigned int low7:7; unsigned int rest:25; };
struct D { char pad[8]; unsigned char* ptr; };
extern D dataX;

extern "C" int ftest(void* obj) {
    int code = Disp(obj, 0x5b);
    if (code < 0) return 0;
    void* state = g1();
    if (!g2((int*)state)) { h1(obj, 1); return 0; }
    void* node = g4(obj, 0x5b);
    short field5c = *(short*)((char*)node + 0x5c);
    int mult = field5c * 6;
    void* entry = g6(obj, code & 0xff);
    if (g3(state)) {
        struct Combined* c = (struct Combined*)((char*)entry + 4);
        unsigned char thresh = dataX.ptr[0x11];
        if (thresh <= c->low7) { h1(obj,2); e(mult+code, dataX.ptr[0x11], 1, 0); return 0; }
        h1(obj, 3);
        return 0;
    }
    if (!TestFlagBitAt0xe((struct SearchStruct*)state, 0)) {
        h2(obj, 5);
        e(mult+code, dataX.ptr[0x11], 3, 0);
        return 0;
    }
    h1(obj, 4);
    return 0;
}
