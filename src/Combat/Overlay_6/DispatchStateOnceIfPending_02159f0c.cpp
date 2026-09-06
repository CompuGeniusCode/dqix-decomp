#include <globaldefs.h>

struct Obj0205eaa0;

void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern int data_02108760;

// USA: func_ov006_02159f0c  (semantic: DispatchStateOnceIfPending_02159f0c)
extern "C" ARM int func_ov006_02159f0c(char* self) {
    int flag = *(int*)(self + 0x3ac);
    if (flag != 0) {
        return flag;
    }
    int gate = *(int*)(self + 0x3a4);
    if (gate == 0) {
        return gate;
    }
    switch (*(int*)(self + 0x39c)) {
    case 0:
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0xa, 0);
        break;
    case 1:
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0xc, 0);
        break;
    case 2:
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0xb, 0);
        break;
    default:
        break;
    }
    *(int*)(self + 0x3ac) = 1;
    return 1;
}
