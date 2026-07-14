#include <globaldefs.h>

short GetTableEntryEven02030c68(int x);
short GetTableEntryOdd02030c9c(int x);

struct AngleTrig0202e9a4 {
    char pad[0x58];
    int angle;   /* 0x58 */
    int cosVal;  /* 0x5c */
    int sinVal;  /* 0x60 */
};

// USA: func_0202e9a4
ARM void SetAngleAndTrigTable0202e9a4(struct AngleTrig0202e9a4* objParam, int angle) {
    int scaled;
    struct AngleTrig0202e9a4* obj;
    /* scaled = (int)(((long long)angle * 0x47 + 0x800) >> 12), hand-scheduled to match
       mwcc's mixed-sign 64-bit multiply codegen (unsigned magnitude via umull + single
       sign correction via mla), which plain C consistently over-generates a redundant
       zero-valued correction term for under this compiler. */
    asm {
        mov r2, #0x47
        umull r3, r4, angle, r2
        mov ip, angle, asr #0x1f
        adds r3, r3, #0x800
        mla r4, ip, r2, r4
        mov obj, objParam
        adc r0, r4, #0
        mov r4, r3, lsr #0xc
        orr scaled, r4, r0, lsl #0x14
    }
    obj->angle = angle;
    obj->cosVal = GetTableEntryEven02030c68(scaled);
    obj->sinVal = GetTableEntryOdd02030c9c(scaled);
}
