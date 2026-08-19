#include <globaldefs.h>

struct Struct_0205bef8;
extern "C" void _Z12Init0205bef8P15Struct_0205bef8(struct Struct_0205bef8* s);
struct Struct_0205ba68;
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(struct Struct_0205ba68* s, int a, int b, int mode);
struct Node0205bacc;
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(struct Node0205bacc* s, int val);
struct SelfBB04;
extern "C" void func_0205bb04(struct SelfBB04* self, int value);

// USA: func_ov009_02188c2c  (semantic: DispatchTypeAndInitPair_02188c2c)
extern "C" ARM void func_ov009_02188c2c(void* objRaw) {
    char* obj = (char*)objRaw;
    int a, b, c, d, e;
    signed char id = *(signed char*)(obj + 0xc58);

    switch (id) {
    case 1:
        a = 1;
        b = 2;
        c = b;
        d = a;
        e = *(unsigned char*)(obj + 0xda3);
        break;
    case 2: {
        unsigned char sel = *(unsigned char*)(obj + 0xda3);
        a = 5;
        b = 1;
        c = a;
        d = b;
        e = *(unsigned char*)(obj + sel + 0xda4);
        break;
    }
    case 3: {
        unsigned char sel = *(unsigned char*)(obj + 0xda3);
        a = 5;
        b = 2;
        e = *(unsigned char*)(obj + sel + 0xdac);
        c = 0xa;
        d = 1;
        break;
    }
    case 4: {
        unsigned char sel = *(unsigned char*)(obj + 0xda3);
        a = 5;
        b = 2;
        e = *(unsigned char*)(obj + sel + 0xdae);
        c = 0xa;
        d = 1;
        break;
    }
    case 5: {
        unsigned char sel = *(unsigned char*)(obj + 0xda3);
        a = 5;
        b = 2;
        e = *(unsigned char*)(obj + sel + 0xda6);
        c = 0xa;
        d = 1;
        break;
    }
    case 6: {
        unsigned char sel = *(unsigned char*)(obj + 0xda3);
        a = 4;
        b = 2;
        e = *(unsigned char*)(obj + sel + 0xdaa);
        c = 8;
        d = 1;
        break;
    }
    case 7: {
        unsigned char sel = *(unsigned char*)(obj + 0xda3);
        a = 4;
        b = 2;
        e = *(unsigned char*)(obj + sel + 0xda8);
        c = 8;
        d = 1;
        break;
    }
    case 8:
        a = 0xb;
        b = 6;
        c = 0x42;
        d = 1;
        e = 0;
        break;
    default:
        break;
    }

    char* sb = obj + 0x3ec;
    _Z12Init0205bef8P15Struct_0205bef8((struct Struct_0205bef8*)(sb + 0x800));
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((struct Struct_0205ba68*)(sb + 0x800), a, b, 1);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc*)(sb + 0x800), c);
    *(int*)(sb + 0x804) = d;
    func_0205bb04((struct SelfBB04*)(sb + 0x800), e);
    *(unsigned char*)(sb + 0x83d) = 0;
}
