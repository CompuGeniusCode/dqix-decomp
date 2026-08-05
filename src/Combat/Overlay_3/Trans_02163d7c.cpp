#include <globaldefs.h>

extern "C" unsigned int _Z15GetBattleStructv();
extern "C" unsigned int _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" unsigned int _Z18CheckField0NonZeroPi(unsigned int, unsigned int);
extern "C" unsigned int _Z19SetFlag320_02195530Ph(unsigned int);
extern "C" unsigned int _Z21GetCombatantUncheckedP12BattleStructi(unsigned int, unsigned int);
extern "C" unsigned int _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c();
extern "C" unsigned int func_02012fe4();
extern "C" unsigned int func_0202ae18();
extern "C" unsigned int func_0202c508(unsigned int);
extern "C" unsigned int func_ov003_02161480();
extern "C" unsigned int func_ov017_0218b5b0();
extern "C" unsigned int func_ov017_021bbae4(unsigned int, unsigned int, unsigned int);

// USA: func_ov003_02163d7c  (semantic: Trans_02163d7c)
extern "C" ARM unsigned int func_ov003_02163d7c(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    unsigned int r6 = 0;
    unsigned int r7 = 0;
    unsigned int r8 = 0;
    unsigned int r9 = 0;
    r9 = r0;
    r0 = (unsigned int)func_ov003_02161480();
    r0 = (unsigned int)_Z15GetBattleStructv();
    r5 = r0;
    r0 = (unsigned int)func_02012fe4();
    r4 = r0;
    r0 = (unsigned int)func_ov017_0218b5b0();
    r6 = r0;
    r1 = r6 + 0x3000;
    r7 = *(unsigned int*)((char*)r1 + 0x6fc);
    r8 = *(unsigned int*)((char*)r1 + 0x734);
    r1 = r9 + 0x400;
    r1 = *(signed char*)((char*)r1 + 0xa2);
    r0 = r5;
    r0 = (unsigned int)_Z21GetCombatantUncheckedP12BattleStructi(r0, r1);
    r0 = (unsigned int)_Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c();
    r5 = r0;
    r0 = (unsigned int)func_0202ae18();
    r1 = *(unsigned int*)((char*)r4 + 0x8);
    r4 = r0;
    r0 = r8;
    r2 = 0x1;
    r0 = (unsigned int)func_ov017_021bbae4(r0, r1, r2);
    r1 = r9 + 0x400;
    r3 = *(signed char*)((char*)r1 + 0xa2);
    r0 = r7;
    r2 = 0x0;
    *(unsigned char*)((char*)r8 + 0xcd) = (unsigned char)r3;
    r3 = *(unsigned char*)((char*)r5 + 0x14);
    r1 = r8;
    r3 = r3 << 0x1f;
    r3 = r3 >> 0x1f;
    *(unsigned char*)((char*)r8 + 0xce) = (unsigned char)r3;
    *(unsigned char*)((char*)r8 + 0xcf) = (unsigned char)r2;
    r0 = (unsigned int)_Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(r0, r1, r2, r3);
    r0 = 0x10;
    *(unsigned char*)((char*)r9 + 0x4a3) = (unsigned char)r0;
    r1 = *(unsigned int*)((char*)r9 + 0x464);
    r0 = r4;
    r1 = r1 & ~0x8000;
    *(unsigned int*)((char*)r9 + 0x464) = (unsigned int)r1;
    r0 = (unsigned int)_Z18CheckField0NonZeroPi(r0, r1);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { return r0; }
    r0 = r4;
    r0 = (unsigned int)func_0202c508(r0);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { return r0; }
    r0 = r6;
    r0 = (unsigned int)_Z19SetFlag320_02195530Ph(r0);
    return r0;
}
