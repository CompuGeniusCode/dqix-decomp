#include <globaldefs.h>
#include "std_library_functions.h"

struct Node020dfbdc {
    int field0;
    int field4;
};
int UpdateNodeField4(void* a, struct Node020dfbdc* node);

extern "C" void* func_020e0280(void* a, void* b, void* out, void* fn);

struct Container020e0310 {
    unsigned int w[3];
};
extern int LookupFieldByKey020e0440(struct Container020e0310* c, int key);

// USA: func_020e046c  (semantic: LookupAndCopyNodeName_020e046c)
extern "C" ARM char* func_020e046c(char* buf, void* b, void* c, int idx) {
    struct Container020e0310 local;
    int out;
    char* str;
    if (buf == NULL || b == NULL || c == NULL || idx < 0) return NULL;
    memset(&local, 0, sizeof(local));
    func_020e0280(&local, b, &out, (void*)UpdateNodeField4);
    str = (char*)LookupFieldByKey020e0440(&local, idx);
    if (str == NULL) {
        buf[0] = 0;
        return NULL;
    }
    strcpy(buf, str);
    return buf;
}
