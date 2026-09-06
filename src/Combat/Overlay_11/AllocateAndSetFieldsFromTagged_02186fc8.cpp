#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021845f8(unsigned char* node, unsigned int id);

struct S021844a4;
extern int SetAllocFields_021844a4(struct S021844a4* obj, void* p1, unsigned int size);

// USA: func_ov011_02186fc8  (semantic: AllocateAndSetFieldsFromTagged_02186fc8)
extern "C" ARM int func_ov011_02186fc8(struct TaggedNumber02184c30* tagged) {
    int key = GetTaggedValueAsInt_02184c30(tagged);
    void* ctx = func_ov017_021b2164();
    if (func_ov011_021845f8((unsigned char*)ctx, key) == 0) return 0;
    int a = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 8));
    int b = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 0x10));
    return SetAllocFields_021844a4((struct S021844a4*)ctx, (void*)key, (a * b) << 5) == 0;
}
