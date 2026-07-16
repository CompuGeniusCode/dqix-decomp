#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Struct_0205ba68;
void SetupPointerTable0205ba68(struct Struct_0205ba68* s, int a, int b, int mode);

struct Node0205bacc;
void SetField0AndPropagate0205bacc(struct Node0205bacc* s, int val);

struct Struct_0205bcdc;
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* s, int index);

extern "C" void func_0205bb04(void* s, int n);
extern "C" void func_ov013_02185424(void* obj, void* buf);
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

// USA: func_ov013_02185310
ARM void InitTag02185310(unsigned char* obj) {
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + 0x38), 0, 2);

    *(unsigned short*)(obj + 0xd8) = 0x1e;
    *(unsigned short*)(obj + 0xda) = 0xd;
    *(unsigned short*)(obj + 0xdc) = 1;
    *(unsigned short*)(obj + 0xde) = 0;
    *(unsigned short*)(obj + 0xe0) = 0;
    *(unsigned short*)(obj + 0xe2) = 5;
    *(unsigned short*)(obj + 0xe4) = 0xa;
    *(unsigned short*)(obj + 0xe6) = 0xd;
    obj[0xe9] = 0;

    if (obj[0x640] != 0) obj[0xed] = 0;
    else obj[0xed] = 1;

    memset(*(void**)(obj + 0x658), 0, 0x960);

    func_ov013_02185424(obj, *(void**)(obj + 0x658));

    func_0205d304(obj + 0x38, *(void**)(obj + 0x658), 0, 0, 0, 1, 0, 0);

    obj[0xe9] = 0;
    *(int*)(obj + 0x40) = 1;
    *(int*)(obj + 0x90) = 1;
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(obj + 0x3c), 1, 6, 0);
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(obj + 0x8c), 1, 6, 0);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(obj + 0x3c), 6);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(obj + 0x8c), 6);
    SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)(obj + 0x3c), 1);
    func_0205bb04(obj + 0x8c, 1);
}
