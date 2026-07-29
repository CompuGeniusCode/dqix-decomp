#include <globaldefs.h>

int PopCount32(unsigned int);
unsigned short GetField0xa(void);
void EmptyStub0202aebc(void);
int IssueBattleCommandSlot24(int, int, int, int, unsigned short, unsigned char);

#pragma optimize_for_size off
// USA: func_0202bc00
ARM int SubmitCommandWithPopcount0202bc00(void* obj, int flag) {
    *(unsigned short*)((char*)obj + 0x102a) = *(unsigned short*)((char*)obj + 0x102a) + 1;
    int popcount = PopCount32(GetField0xa());
    int idx = (popcount - 1) & 0xff;
    int f = flag != 0;
    unsigned char bits = *(unsigned char*)((char*)obj + 0x1029);
    bits = (bits & ~0x7) | (idx & 0x7);
    *(unsigned char*)((char*)obj + 0x1029) = bits;
    unsigned short field4 = *(unsigned short*)((char*)obj + 0x4);
    f = f & 0xff;
    return IssueBattleCommandSlot24((int)(void*)EmptyStub0202aebc, (int)((char*)obj + 0x1014), 0x24, 0x785, field4, (unsigned char)f);
}
