#include <globaldefs.h>

struct FlagHolder021dd3e0 { unsigned int pad0; unsigned int flag : 1; };

// USA: func_ov027_021dd3e0  (semantic: IsFlagBit0Set_021dd3e0)
extern "C" ARM bool func_ov027_021dd3e0(FlagHolder021dd3e0* p) {
    return p->flag;
}
