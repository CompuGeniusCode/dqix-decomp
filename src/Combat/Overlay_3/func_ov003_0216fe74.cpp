#include <globaldefs.h>

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

extern "C" void* func_0200f374(void* dst, int count);

int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);

struct Container020e0310;
extern "C" short func_ov003_0216df38(char* dst, struct Container020e0310* c, int flag);

struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

// USA: func_ov003_0216fe74  (semantic: SetupAndDispatchBattleMessage_0216fe74)
extern "C" ARM void func_ov003_0216fe74(char* self, int p1, int p2, int p3) {
    char* field3c = *(char**)(self + 0x3c);
    if (field3c == 0) {
        return;
    }
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)field3c, 0, 1);

    (*(char**)(self + 0x3c))[0xb1] = 0;

    field3c = *(char**)(self + 0x3c);
    *(short*)(field3c + 0xa0) = 0x11;
    *(short*)(field3c + 0xa2) = 9;

    field3c = *(char**)(self + 0x3c);
    *(short*)(field3c + 0xa4) = 6;
    *(short*)(field3c + 0xa6) = 6;

    field3c = *(char**)(self + 0x3c);
    *(short*)(field3c + 0xa8) = 0xc;
    *(short*)(field3c + 0xaa) = 0xe;

    field3c = *(char**)(self + 0x3c);
    *(short*)(field3c + 0xac) = 0xa;
    *(short*)(field3c + 0xae) = 0x10;

    (*(char**)(self + 0x3c))[0xb5] = 1;

    char buf[0x200];
    func_0200f374(buf, 0x200);

    if (p3 != -1) {
        AppendFrameTag02041c08(buf, p3, 8, 5, 5, 5);
    }

    short w = func_ov003_0216df38(buf, (struct Container020e0310*)(self + 0xdc), p1);

    field3c = *(char**)(self + 0x3c);
    *(short*)(field3c + 0xa4) = (short)((0x20 - w) >> 1);
    *(short*)(field3c + 0xa6) = 6;

    field3c = *(char**)(self + 0x3c);
    *(short*)(field3c + 0xa0) = w;
    *(short*)(field3c + 0xa2) = 9;

    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)*(char**)(self + 0x3c), 0, (int)buf, 1, 0);
}
