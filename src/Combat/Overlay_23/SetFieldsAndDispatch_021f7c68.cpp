#include <globaldefs.h>

struct Obj0204b988;
void DispatchIndexedEntry0204b988(struct Obj0204b988* obj, unsigned int index, int a3, int a4, unsigned short a5);

struct Obj021f7c68 { char pad[0x48]; int f48; unsigned char f4c, f4d, f4e; };

// USA: func_ov023_021f7c68
ARM void SetFieldsAndDispatch_021f7c68(Obj021f7c68* obj, unsigned char a, unsigned char b, unsigned char c) {
    obj->f4c = a;
    obj->f4d = b;
    obj->f4e = c;
    obj->f48 = 1;
    DispatchIndexedEntry0204b988((struct Obj0204b988*)((char*)obj + 0x28), obj->f4c, obj->f4d, obj->f4e, 0xffff);
}
