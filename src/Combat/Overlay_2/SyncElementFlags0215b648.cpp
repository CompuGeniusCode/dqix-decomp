#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;

struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
extern "C" void func_ov002_0215b9a4(unsigned char* obj, int key, int flag);
extern const unsigned char data_ov002_0216c984[6];

// USA: func_ov002_0215b648
ARM void SyncElementFlags0215b648(unsigned char* obj) {
    if (obj[0x1cc4] == 0) {
        return;
    }
    struct Struct_0205d81c* s = (struct Struct_0205d81c*)(obj + 0x2c8 + 0xc00);
    int i;
    for (i = 0; i < 6; i++) {
        unsigned char key = data_ov002_0216c984[i];
        struct Elem_0205d81c* e = FindElementByC40205d81c(s, key);
        if (e == 0) {
            continue;
        }
        unsigned short f = *(unsigned short*)((char*)e + 0xc2);
        int flag = (f != 0) ? 1 : 0;
        func_ov002_0215b9a4(obj, key, flag);
    }
}
