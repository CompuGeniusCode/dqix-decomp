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
extern "C" void func_ov013_02185be0(void* obj, void* buf);
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

extern int data_ov013_02187d98;

// USA: func_ov013_02185aac
ARM void InitTag02185aac(unsigned char* obj) {
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + 0x38), 0, 2);

    *(unsigned short*)(obj + 0xd8) = 7;
    *(unsigned short*)(obj + 0xda) = 5;
    *(unsigned short*)(obj + 0xdc) = 0x19;
    *(unsigned short*)(obj + 0xde) = 0x13;
    *(unsigned short*)(obj + 0xe0) = 0xc;
    *(unsigned short*)(obj + 0xe2) = 7;
    *(unsigned short*)(obj + 0xe4) = 0xa;
    *(unsigned short*)(obj + 0xe6) = 0x10;
    obj[0xe9] = 3;

    if (obj[0x640] != 0) obj[0xed] = 0;
    else obj[0xed] = 1;

    memset(*(void**)(obj + 0x658), 0, 0x960);

    func_ov013_02185be0(obj, *(void**)(obj + 0x658));

    func_0205d304(obj + 0x38, *(void**)(obj + 0x658), 0, 0, 0, 1, (int)&data_ov013_02187d98, 1);

    obj[0xe9] = 3;
    *(int*)(obj + 0x40) = 1;
    *(int*)(obj + 0x90) = 1;
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(obj + 0x3c), 1, 2, 0);
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(obj + 0x8c), 1, 2, 0);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(obj + 0x3c), 2);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(obj + 0x8c), 2);

    int idx = *(int*)(obj + 0x660);
    SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)(obj + 0x3c), idx);
    func_0205bb04(obj + 0x8c, idx);
}
