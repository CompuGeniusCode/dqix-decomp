#include <globaldefs.h>

struct Vector4fix { int x, y, z, w; };
struct Vector3fix { int x, y, z; };
struct Matrix4x4 { struct Vector4fix r[4]; };
struct Matrix4x3 { struct Vector3fix r[4]; };

// USA: func_020c2208
// from pokediamond/arm9/lib/NitroSDK/src/FX_mtx44.c -- MTX_Copy44To43_. Also asm in
// SonicRushAdventure-Decomp and khdays-decomp; no project has a matching C form.
// C attempted (field-by-field row copy, matching struct layout): mwcc emits one ldr/str
// pair per word, never ldm/stm -- BYTEDIFF, wrong shape. The target's ldm/stm{r2,r3,ip}
// blocks with the src pointer advanced past the dropped 4th word via raw `add r0,#4`
// (not a field access) is the register-block tell: no compiler reaches for that shape
// from a field copy.
extern "C" ARM asm void Mat4x4_ConvertTo4x3(struct Matrix4x4 *src, struct Matrix4x3 *dst) {
    ldmia r0!, {r2, r3, r12}
    add r0, r0, #4
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    add r0, r0, #4
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    add r0, r0, #4
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    add r0, r0, #4
    stmia r1!, {r2, r3, r12}
    bx lr
}
