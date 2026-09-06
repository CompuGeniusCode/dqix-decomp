#include <globaldefs.h>

struct Obj0217f260 { char pad0; unsigned char field1; };

extern "C" void func_ov003_0217f118(void*);

// USA: func_ov003_0217f260
ARM void InitField1_0217f260(struct Obj0217f260* obj) {
    func_ov003_0217f118(obj);
    obj->field1 = 1;
}
