#include <globaldefs.h>
#include "std_library_functions.h"

struct Header020e544c;
unsigned int GetField0Low12Times16020e544c(Header020e544c* header);

struct ElementList020e545c;
struct Element020e545c;
typedef void (*ElementCallback020e545c)(ElementList020e545c*, Element020e545c*);
int InvokeCallbackPerElement020e545c(ElementList020e545c* list, ElementCallback020e545c callback);

struct List020e53bc {
    unsigned int field0;
    void* field4;
    void* field8;
};

// USA: func_020e53bc  (semantic: InitContainerFromSource_020e53bc)
extern "C" ARM int func_020e53bc(struct List020e53bc* self, struct List020e53bc* src, unsigned char* outFlag, ElementCallback020e545c callback) {
    *outFlag = 0;
    if (src == 0) return 0;
    memcpy(self, src, 4);
    self->field4 = (char*)src + 4;
    self->field8 = (char*)src + (GetField0Low12Times16020e544c((Header020e544c*)self) + 4);
    if ((unsigned int)self->field0 >> 31) {
        *outFlag = 1;
        return 1;
    }
    InvokeCallbackPerElement020e545c((ElementList020e545c*)self, callback);
    self->field0 = (self->field0 & ~0x80000000) | 0x80000000;
    src->field0 = (src->field0 & ~0x80000000) | 0x80000000;
    return 1;
}
