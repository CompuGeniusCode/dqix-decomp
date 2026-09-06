#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
void SetEntryFields02154bcc(int a, int b, void* obj, int idx, unsigned char arg5, unsigned char arg6);

// USA: func_ov002_0215aaa4  (semantic: SetFormationEntries_0215aaa4)
extern "C" ARM void func_ov002_0215aaa4(char* obj) {
    struct Elem_0205d81c* e = FindElementByC40205d81c((struct Struct_0205d81c*)(obj + 0xec8), 0x21);
    if (e) {
        short ex = *(short*)((char*)e + 0xac);
        short x13 = ex * 8;
        short sx = x13 + 6;
        short ey = *(short*)((char*)e + 0xae);
        short y13 = ey * 8;
        short pos[4];
        unsigned char i;
        pos[0] = y13 + 0x1a;
        pos[1] = y13 + 0x32;
        pos[2] = y13 + 0x4a;
        pos[3] = y13 + 0x62;
        for (i = 0; i < 4; i++) {
            void* p = *(void**)(obj + 0x1a68);
            SetEntryFields02154bcc(sx, pos[i], p, (unsigned short)(i + 7), 0xff, 0xff);
        }
    }
}
