#include <globaldefs.h>

int GetBoxTestResult(int* out);

struct SubObj0207e97c {
    char pad0[0x2c];
    short f2c;
    short f2e;
    short f30;
    short f32;
    short f34;
    short f36;
    int f38;
};

struct Obj0207e97c {
    char pad0[0x54];
    struct SubObj0207e97c* field54;
};

struct GxRegs0207e97c {
    volatile unsigned int mtxPush;
    char pad0[0x24];
    volatile unsigned int mtxScale;
    char pad1[0x34];
    volatile unsigned int polyFormat;
    char pad2[0x58];
    volatile unsigned int begin;
    volatile unsigned int end;
    char pad3[0xB8];
    volatile unsigned int boxTest;
};

union BoxParams0207e97c {
    short s[6];
    int w[3];
};

// USA: func_0207e97c  (semantic: RunBoxTestAgainstElem_0207e97c)
extern "C" ARM int func_0207e97c(struct Obj0207e97c* obj) {
    struct GxRegs0207e97c* regs = (struct GxRegs0207e97c*)0x4000444;
    int scaleVal;
    union BoxParams0207e97c box;
    int result;

    regs->mtxPush = 0;

    scaleVal = obj->field54->f38;
    regs->mtxScale = scaleVal;
    regs->mtxScale = scaleVal;
    regs->mtxScale = scaleVal;
    regs->polyFormat = 0x30c1;
    regs->begin = 0;
    regs->end = 0;

    box.s[0] = obj->field54->f2c;
    box.s[1] = obj->field54->f2e;
    box.s[2] = obj->field54->f30;
    box.s[3] = obj->field54->f32;
    box.s[4] = obj->field54->f34;
    box.s[5] = obj->field54->f36;
    regs->boxTest = box.w[0];
    regs->boxTest = box.w[1];
    regs->boxTest = box.w[2];

    while (GetBoxTestResult(&result) != 0);

    *(volatile unsigned int*)0x4000448 = 1;
    return result;
}
