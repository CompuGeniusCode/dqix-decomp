#include <globaldefs.h>

struct Variant02030b0c { int tag; union { int i; float f; } u; };
struct Struct02030b7c;
int GetIntFromVariant02030b0c(Variant02030b0c* p);
void* GetField4IfField0Zero(Struct02030b7c* s);

// USA: func_0201f864
ARM int DecodeArgsReturnPtrNonNull0201f864(Variant02030b0c* args) {
    void* p;
    GetIntFromVariant02030b0c(args);
    p = GetField4IfField0Zero((Struct02030b7c*)(args + 1));
    GetIntFromVariant02030b0c(args + 2);
    return p != NULL ? 1 : 0;
}
