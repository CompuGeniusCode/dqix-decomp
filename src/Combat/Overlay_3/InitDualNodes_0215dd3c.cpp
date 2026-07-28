#include <globaldefs.h>

struct Struct_0205ba68;
void SetupPointerTable0205ba68(struct Struct_0205ba68* s, int a, int b, int mode);
struct Node0205bacc;
void SetField0AndPropagate0205bacc(struct Node0205bacc* s, int val);
struct Struct_0205bcdc;
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* s, int index);
extern "C" void func_0205bb04(void* s, int n);

// USA: func_ov003_0215dd3c  (semantic: InitDualNodes_0215dd3c)
extern "C" ARM void func_ov003_0215dd3c(char* obj) {
    int a, b, c;
    if (*(unsigned char*)(obj + 0x148) == 1) {
        a = *(unsigned char*)(obj + 0x3c0);
        b = 1;
        c = *(signed char*)(obj + 0x3c1);
    }
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(obj + 0x9c), b, a, 0);
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(obj + 0xec), b, a, 0);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(obj + 0x9c), a);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(obj + 0xec), a);
    *(int*)(obj + 0xa0) = b;
    *(int*)(obj + 0xf0) = b;
    SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)(obj + 0x9c), c);
    func_0205bb04((void*)(obj + 0xec), c);
}
