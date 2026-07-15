#include <globaldefs.h>

struct Combatant020A36A8;
int MatchesActiveIndex020a36a8(struct Combatant020A36A8*);
int PeekInputLogB(void);
extern "C" void func_ov026_021dbf04(void*);

struct Struct0216377c { char pad[0x2a0]; unsigned char* ptr2a0; };

// USA: func_ov000_0216377c
ARM void Foo0216377c(struct Struct0216377c* obj, unsigned char val) {
    unsigned char* p = obj->ptr2a0;
    if (!p) return;
    p[0x2a] = val;
    if (MatchesActiveIndex020a36a8((struct Combatant020A36A8*)obj->ptr2a0)) {
        *(int*)((char*)obj + 0x55f4) |= 0x40000000;
    }
    if (PeekInputLogB() == 3) {
        func_ov026_021dbf04(obj);
    }
}
