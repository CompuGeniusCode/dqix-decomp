#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021f6f10(void*);

// virtual call at vtable idx 0xd8/4 = 54; class w/ virtuals mirrors the
// ROM's single-scratch vtable pointer-chase (ldr r2,[r0]; ldr r2,[r2,#0xd8]).
class VObj63f8 {
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
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53();
    virtual void MethodD8(int arg);
    char pad4[0x1c];
    void* field20;
};
extern "C" VObj63f8* func_ov023_021f6880(void*, int);

// USA: func_ov023_021f63f8  (semantic: DispatchVTableFnAtD8_021f63f8)
extern "C" ARM void func_ov023_021f63f8(void* ctx, int key, void* field20val, int arg) {
    VObj63f8* node = func_ov023_021f6880(func_ov011_021849c8(ctx), key);
    if (node == 0) return;
    if (func_ov023_021f6f10(node) != 8) return;
    node->field20 = field20val;
    node->MethodD8(arg);
}
