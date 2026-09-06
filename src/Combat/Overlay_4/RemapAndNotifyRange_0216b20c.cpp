#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);

class VObj0216b20c {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual void Method44(int arg);
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30();
    virtual void Method7c(int arg);
};
extern "C" VObj0216b20c* func_ov023_021f6880(void*, int);

// USA: func_ov004_0216b20c  (semantic: RemapAndNotifyRange_0216b20c)
extern "C" ARM void func_ov004_0216b20c(void* a0, int key, int b, int c) {
    VObj0216b20c* obj = func_ov023_021f6880(func_ov011_021849c8(a0), key);
    if (!obj) return;
    if (c != 0) goto merge;
    if (b > 0xc8) goto big;
    if (b >= 0xc8) goto is200;
    if (b > 0x64) goto mid;
    if (b == 0x64) b = 0x15;
    goto merge;
mid:
    if (b > 0x97) goto merge;
    if (b < 0x96) goto merge;
    if (b == 0x96) goto is150;
    if (b == 0x97) b = 0x17;
    goto merge;
big:
    if (b > 0xc9) goto is300;
    if (b == 0xc9) b = 0x19;
    goto merge;
is300:
    if (b == 0x12c) b = 0x1a;
    goto merge;
is150:
    b = 0x16;
    goto merge;
is200:
    b = 0x18;
merge:
    obj->Method44(b);
    obj->Method7c(b);
}
