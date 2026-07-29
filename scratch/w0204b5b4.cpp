#include <globaldefs.h>

typedef void (*PriorityFunc0204b5b4)(int);
extern PriorityFunc0204b5b4 data_020f01d8[][4];

struct Flags0204b5b4 {
    unsigned char lo : 4;
    unsigned char hi : 4;
};

// USA: func_0204b5b4
ARM void DispatchPriorityByFlagsFieldByte(void* obj, int priority) {
    Flags0204b5b4* f = (Flags0204b5b4*)((char*)obj + 0x1c);
    PriorityFunc0204b5b4* row = data_020f01d8[f->lo];
    row[f->hi](priority & 3);
}
