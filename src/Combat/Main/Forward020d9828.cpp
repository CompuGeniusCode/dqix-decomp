#include <globaldefs.h>
struct ProcessorContext;
void MarkContextReadyAndSwitch(struct ProcessorContext*);

// USA: func_020d9828
ARM void Forward020d9828(void* p) {
    MarkContextReadyAndSwitch((struct ProcessorContext*)p);
}
