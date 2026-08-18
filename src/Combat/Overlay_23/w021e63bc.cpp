#include <globaldefs.h>

extern unsigned char data_02114e54;

struct Struct_0205d81c;
struct Elem_0205d81c;
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c*, int);

// USA: func_ov023_021e63bc
extern "C" ARM int func_ov023_021e63bc(void* obj) {
    unsigned char flag = *(unsigned char*)((char*)obj + 0x1371);
    Elem_0205d81c* elem = FindElementByC40205d81c((Struct_0205d81c*)((char*)obj + 0xac), flag);

    short ac = *(short*)((char*)elem + 0xac);
    short ae = *(short*)((char*)elem + 0xae);
    int fieldA = *(int*)((char*)&data_02114e54 + 0x38);
    int x = (short)(ac * 8) + 10;
    int y = (short)(ae * 8) + 0x10;
    int fieldB = *(int*)((char*)&data_02114e54 + 0x3c);

    if (x <= fieldA && fieldA <= x + 0x10 && y <= fieldB && fieldB <= y + 8) return 1;
    if (x <= fieldA && fieldA <= x + 0x10 && y + 0xc <= fieldB && fieldB <= y + 0x14) return -1;
    return 0;
}
