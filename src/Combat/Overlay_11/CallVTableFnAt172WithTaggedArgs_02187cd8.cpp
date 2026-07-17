#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

// The dispatched object is a C++ polymorphic type; the call site
// (obj->vtable[0xac])(obj, ...) is a real virtual call. Modelling it as a
// class with virtual methods (target method at vtable index 0xac/4 = 43) makes
// mwcc emit the ROM's single-scratch pointer chase (ldr ip,[r0]; ldr ip,[ip,#0xac])
// rather than the two-scratch form a manual function-pointer struct produces.
class VObj02187cd8 {
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
    virtual void v40(); virtual void v41(); virtual void v42();
    virtual void MethodAc(int a, int b, int c);
};
extern "C" struct VObj02187cd8* func_ov023_021f6880(void*, int);

// USA: func_ov011_02187cd8
ARM int CallVTableFnAt172WithTaggedArgs_02187cd8(struct TaggedNumber02184c30* tagged) {
    int v0 = GetTaggedValueAsInt_02184c30(tagged);
    int v1 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 8));
    int v2 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 0x10));
    int v3 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 0x18));
    struct VObj02187cd8* node = func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), v0);
    if (node) {
        node->MethodAc(v1, v2, v3);
    }
    return 1;
}
