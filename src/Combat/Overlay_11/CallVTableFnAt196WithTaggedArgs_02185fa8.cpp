#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

// Real virtual call; target method at vtable index 0xc4/4 = 49.
// See CallVTableFnAt172WithTaggedArgs_02187cd8.cpp for why a class w/
// dummy virtuals (rather than a manual fn-ptr struct) matches mwcc's
// single-scratch pointer chase (ldr ip,[r0]; ldr ip,[ip,#0xc4]).
class VObj02185fa8 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48();
    virtual void Method_c4(int a, int b, int c);
};
extern "C" struct VObj02185fa8* func_ov023_021f6880(void*, int);

// USA: func_ov011_02185fa8
ARM int CallVTableFnAt196WithTaggedArgs_02185fa8(struct TaggedNumber02184c30* tagged) {
    int v0 = GetTaggedValueAsInt_02184c30(tagged);
    int v1 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 8));
    int v2 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 0x10));
    int v3 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 0x18));
    struct VObj02185fa8* node = func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), v0);
    if (!node) return 0;
    node->Method_c4(v1, v2, v3);
    return 1;
}
