#include <globaldefs.h>
// USA: func_020c2e34
ARM asm void CrossProductFixed020c2e34(int* a, int* b, int* out) {
 stmdb sp!, {r4,r5,r6,r7,r8,lr}
 ldmia r0, {r5,lr}
 ldr r6, [r1,#8]
 ldr r0, [r0,#8]
 ldmia r1, {r4,ip}
 smull r8,r7,lr,r6
 smull r3,r1,r0,ip
 subs r3,r8,r3
 sbc r1,r7,r1
 adds r3,r3,#0x800
 smull r8,r7,r0,r4
 smull r6,r0,r5,r6
 adc r1,r1,#0
 subs r6,r8,r6
 mov r3,r3,lsr #12
 orr r3,r3,r1,lsl #20
 sbc r7,r7,r0
 adds r0,r6,#0x800
 smull ip,r6,r5,ip
 adc r5,r7,#0
 smull r4,r1,lr,r4
 mov r7,r0,lsr #12
 subs r4,ip,r4
 sbc r0,r6,r1
 adds r1,r4,#0x800
 str r3,[r2]
 orr r7,r7,r5,lsl #20
 adc r0,r0,#0
 mov r1,r1,lsr #12
 str r7,[r2,#4]
 orr r1,r1,r0,lsl #20
 str r1,[r2,#8]
 ldmia sp!, {r4,r5,r6,r7,r8,pc}
}
