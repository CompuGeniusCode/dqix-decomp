#include <globaldefs.h>

struct Obj021f645c {
    virtual void R0();
    virtual void R1();
    virtual void R2();
    virtual void R3();
    virtual void R4();
    virtual void R5();
    virtual void R6();
    virtual void R7();
    virtual void R8();
    virtual void R9();
    virtual void R10();
    virtual void R11();
    virtual void R12();
    virtual void R13();
    virtual void R14();
    virtual void R15();
    virtual void R16();
    virtual void R17();
    virtual void R18();
    virtual void R19();
    virtual void R20();
    virtual void R21();
    virtual void R22();
    virtual void R23();
    virtual void R24();
    virtual void R25();
    virtual void R26();
    virtual void R27();
    virtual void R28();
    virtual void R29();
    virtual void R30();
    virtual void R31();
    virtual void R32();
    virtual void R33();
    virtual void R34();
    virtual void R35();
    virtual void R36();
    virtual void R37();
    virtual void R38();
    virtual void R39();
    virtual void R40();
    virtual void R41();
    virtual void R42();
    virtual void R43();
    virtual void R44();
    virtual void R45();
    virtual void R46();
    virtual void R47();
    virtual void R48();
    virtual void R49();
    virtual void R50();
    virtual void R51();
    virtual void R52();
    virtual void R53();
    virtual void MethodD8(void* arg);
    char pad[0x34];
    unsigned short field38;
};

extern "C" void* func_ov011_021849c8(void*);
extern "C" struct Obj021f645c* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void);

// USA: func_ov023_021f645c
extern "C" ARM void func_ov023_021f645c(void* obj, int id, unsigned short field38, void* argD8) {
    void* sub = func_ov011_021849c8(obj);
    struct Obj021f645c* node = func_ov023_021f6880(sub, id);
    if (!node) return;
    int state = func_ov023_021f6f10();
    if (state != 8) return;
    node->field38 = field38;
    node->MethodD8(argD8);
}
