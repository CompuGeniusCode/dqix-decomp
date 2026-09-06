#include <globaldefs.h>
void ProcessAndUnregisterActor020bcc7c(struct Obj020bcc7c*);


struct Foo020bcbc4 { char pad[0x24]; signed int bit0 : 1; };

// USA: func_020bcbc4
ARM void CallIfFlag0x24Bit0(struct Foo020bcbc4* obj) {
    if (obj->bit0) {
        ProcessAndUnregisterActor020bcc7c((struct Obj020bcc7c*)(obj));
    }
}
