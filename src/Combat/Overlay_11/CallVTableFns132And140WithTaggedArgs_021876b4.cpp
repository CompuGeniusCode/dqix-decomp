#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);

// Two virtual calls on the same object; target methods at vtable indices
// 0x84/4 = 33 and 0x8c/4 = 35. See CallVTableFnAt172WithTaggedArgs_02187cd8.cpp.
class VObj021876b4 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32();
    virtual void Method84(int a);
    virtual void v34();
    virtual void Method8c(int a);
};
extern "C" struct VObj021876b4* func_ov023_021f6880(void*, int);

// USA: func_ov011_021876b4
ARM int CallVTableFns132And140WithTaggedArgs_021876b4(struct TaggedNumber02184c30* tagged) {
    int v0 = GetTaggedValueAsInt_02184c30(tagged);
    int v1 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 8));
    int v2 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 0x10));
    struct VObj021876b4* node = func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), v0);
    if (node) {
        node->Method84(v1);
        node->Method8c(v2);
    }
    return 1;
}
