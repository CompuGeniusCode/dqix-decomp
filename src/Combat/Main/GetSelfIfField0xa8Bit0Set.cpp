#include <globaldefs.h>

struct S_37760 {
    char pad[0xa8];
    signed int flag : 1;
};

// USA: func_02037760
ARM struct S_37760* GetSelfIfField0xa8Bit0Set(struct S_37760* obj) {
    if (obj->flag == 0) {
        return 0;
    }
    return obj;
}
