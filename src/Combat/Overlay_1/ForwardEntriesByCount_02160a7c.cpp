#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_ov017_021d6134(void* p, int flag);

struct S734 { char pad[0xcc]; unsigned char f_cc, f_cd, f_ce, f_cf; };

// USA: func_ov001_02160a7c  (semantic: ForwardEntriesByCount_02160a7c)
extern "C" ARM int func_ov001_02160a7c(char* obj, int count) {
    int flag;
    void* ov17 = func_ov017_0218b5b0();
    struct S734* s = *(struct S734**)((char*)ov17 + 0x3734);
    func_ov017_021d6134(obj, s->f_cd);
    obj += 8;
    if (count >= 2) {
        func_ov017_021d6134(obj, s->f_cf);
        obj += 8;
    }
    if (count >= 3) {
        func_ov017_021d6134(obj, s->f_ce);
        obj += 8;
    }
    if (count >= 4) {
        unsigned char v = s->f_cc;
        if (v == 2) {
            flag = 0;
        } else if (v == 1) {
            flag = 1;
        }
        func_ov017_021d6134(obj, flag);
    }
    return 1;
}
