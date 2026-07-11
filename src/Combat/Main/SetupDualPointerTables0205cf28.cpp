#include <globaldefs.h>

struct Struct_0205ba68;
struct Node0205bacc;
void SetupPointerTable0205ba68(struct Struct_0205ba68* s, int a, int b, int mode);
void SetField0AndPropagate0205bacc(struct Node0205bacc* s, int val);

// USA: func_0205cf28
ARM void SetupDualPointerTables0205cf28(unsigned char* p, int a, int b, int c) {
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(p + 4), a, b, c);
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(p + 0x54), a, b, c);
    int prod = a * b;
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(p + 4), prod);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(p + 0x54), prod);
}
