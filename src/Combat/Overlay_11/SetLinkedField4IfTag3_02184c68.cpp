#include <globaldefs.h>

struct Obj02184c68 {
    int tag;
    Obj02184c68* link;
};

// USA: func_ov011_02184c68  (semantic: SetLinkedField4IfTag3_02184c68)
extern "C" ARM void func_ov011_02184c68(Obj02184c68* obj, void* val) {
    if (obj->tag == 3) {
        obj->link->link = (Obj02184c68*)val;
    }
}
