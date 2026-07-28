#include <globaldefs.h>
extern "C" int f1(void*,int);
extern "C" void* f2(void);
extern "C" int f3(void*);
extern "C" void* f4(void*,int);
extern "C" void* f5(void*,int);
extern "C" int f6(void*,int);
extern "C" void g(int,int,int,int);
extern "C" void k(void*,int);
struct D1 { char pad[8]; unsigned char* ptr; };
extern D1 dataX;
struct C1 { unsigned int low7:7; unsigned int rest:25; };

extern "C" int ts1(void* obj) {
    int code = f1(obj, 0x5b);
    if (code < 0) return 0;
    void* state = (void*)((int*)obj)[11];
    if (!f3(state)) { k(obj,1); goto end; }
    {
        void* node = f4(obj, 0x5b);
        short field5c = *(short*)((char*)node + 0x5c);
        int mult = field5c * 6;
        void* entry = f5(obj, code & 0xff);
        if (f3(state)) {
            C1* c = (C1*)((char*)entry + 4);
            if (dataX.ptr[0x11] <= c->low7) {
                k(obj,1);
                g(mult + code, dataX.ptr[0x11], 1, 0);
                goto end;
            }
            k(obj, 0x2367);
            goto end;
        }
        if (!f6(state, 0)) {
            char* p = (char*)f2() + 0x26c + 0x5d00;
            unsigned short v = *(unsigned short*)(p + 0xc);
            *(unsigned short*)(p + 0xc) = v & ~0xe000;
            g(mult + code, dataX.ptr[0x11], 3, 0);
            k(obj, 0x5c);
            goto end;
        }
        k(obj, 0x2369);
    }
end:
    return 0;
}
