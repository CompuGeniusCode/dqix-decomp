#include <globaldefs.h>

extern "C" int func_0205ac40(void*, void*);
extern "C" void func_ov023_021dab5c(void*, int, int, int, int);

// USA: func_ov023_021da770  (semantic: ConfigureEntryPositions_021da770)
extern "C" ARM void func_ov023_021da770(void* obj) {
    char* base = (char*)obj;
    char* ctx = *(char**)(base + 0x7e4);
    int flags = *(int*)(base + 0xd9c);
    char* arr = *(char**)(base + 0x7e8);
    if (!(flags & 0x1000000)) {
        int sb0 = *(signed char*)(base + 0xc00 + 0x58);
        int flagsB = *(int*)(base + 0xd9c);
        if ((sb0 != 9 || *(unsigned char*)(base + 0xc59) < 1) &&
            sb0 != 0xb && !(flagsB & 0x400000)) {
            char* e;
            e = arr + 0x118;
            *(int*)(e + 0x14) = 0xe000;
            *(int*)(e + 0x18) = 0xa9000;
            func_0205ac40(ctx, e);

            e = arr + 0xf0;
            *(int*)(e + 0x14) = 0x15000;
            *(int*)(e + 0x18) = 0xa9000;
            func_0205ac40(ctx, e);

            e = arr + 0x140;
            *(int*)(e + 0x14) = 0x3b000;
            *(int*)(e + 0x18) = 0xa9000;
            func_0205ac40(ctx, e);

            e = arr + 0x168;
            *(int*)(e + 0x14) = 0x8e000;
            *(int*)(e + 0x18) = 0xa9000;
            func_0205ac40(ctx, e);

            e = arr + 0x190;
            *(int*)(e + 0x14) = 0xc8000;
            *(int*)(e + 0x18) = 0xa9000;
            func_0205ac40(ctx, e);
        }
    }

    int i;
    for (i = 0; i < 8; i++) {
        unsigned char idx = *(unsigned char*)(base + 0xda3);
        int limit = *(signed char*)(base + idx + 0xd00 + 0xa0);
        if (i > limit - 1) break;

        int val = (i * 0x10 + 0x78) << 12;
        char* e = arr + (i + 11) * 0x28;
        int sb = *(signed char*)(base + 0xc00 + 0x58);
        int type = 10;
        if (sb == 9) {
            unsigned char b59 = *(unsigned char*)(base + 0xc59);
            if (b59 >= 1 && b59 != 0xff) type = 11;
        } else if (sb == 0xb) {
            type = 11;
        } else if (i == sb - 1) {
            type = 9;
        }
        *(unsigned char*)(e + 0x25) = (unsigned char)type;
        *(int*)(e + 0x14) = val;
        *(int*)(e + 0x18) = 0x8000;
        func_0205ac40(ctx, e);
    }

    if (*(unsigned char*)(base + 0xd94) == 1) return;

    int sb2 = *(signed char*)(base + 0xc00 + 0x58);
    int idx2 = -1;
    int handled = 0;
    switch (sb2) {
    case 2: case 3: case 4: case 5: case 6: case 7:
        idx2 = 0x14;
        if (sb2 == 2) idx2 = 0x13;
    case 1: case 8:
        handled = 1;
        break;
    default:
        break;
    }

    if (idx2 >= 0) {
        char* e = arr + idx2 * 0x28;
        short y0 = *(short*)(base + 0xc00 + 0x54);
        short y1 = *(short*)(base + 0xc00 + 0x56);
        *(int*)(e + 0x14) = y0 << 12;
        *(int*)(e + 0x18) = y1 << 12;
        func_0205ac40(ctx, e);
    }

    if (!handled) return;
    if (*(int*)(base + 0xd9c) & 0x400000) return;

    short s52 = *(short*)(base + 0xc00 + 0x52);
    short s4c = *(short*)(base + 0xc00 + 0x4c);
    short s4e = *(short*)(base + 0xc00 + 0x4e);
    short s50 = *(short*)(base + 0xc00 + 0x50);
    func_ov023_021dab5c(obj, s4c, s4e, s50, s52);
}
