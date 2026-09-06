#include <globaldefs.h>
struct ProcessorContext;
void MarkContextReadyAndSwitch(struct ProcessorContext*);

// USA: _Z15Forward020d9828Pv
ARM void Forward020d9828(void* p) {
    MarkContextReadyAndSwitch((struct ProcessorContext*)p);
}
