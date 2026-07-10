#include <globaldefs.h>

extern "C" unsigned short* func_02012fe4(void);
extern "C" int func_020375f8(unsigned char* obj);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0*, int, int);
extern int data_02108760;

// USA: func_02034044
ARM void SetField0xc4Low15Bits(unsigned char* obj, int val) {
    unsigned short cur = *func_02012fe4();
    if (cur == func_020375f8(obj)) {
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0x60, 0);
    }
    *(unsigned short*)(obj + 0xc4) = (*(unsigned short*)(obj + 0xc4) & 0xFFFF8000) | (val & 0x7FFF);
}
