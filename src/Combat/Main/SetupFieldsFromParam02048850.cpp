#include <globaldefs.h>

extern "C" void func_020377c4(void* obj, int v);
extern "C" void func_020377b4(void* obj, int v);

struct Param02048850 {
    char pad0[0xc];
    short fieldC;
    short fieldE;
};

struct Obj02048850 {
    char pad0[0x144];
    struct Param02048850* field144;
};

// USA: func_02048850
ARM void SetupFieldsFromParam02048850(struct Obj02048850* obj, struct Param02048850* p) {
    obj->field144 = p;
    func_020377c4(obj, p->fieldC << 2);
    func_020377b4(obj, obj->field144->fieldE);
}
