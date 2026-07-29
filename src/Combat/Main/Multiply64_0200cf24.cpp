#include <globaldefs.h>

// SKIP attempt func_0200cf24: 64x64->64 multiply (umull + 2x mla), instruction
// shape/order matches target exactly, but target stages the two accumulators in
// CALLEE-SAVED r4/r5 (stmdb sp!,{r4,r5,lr} / separate ldmia+bx lr epilogue, 8
// instrs) while every C form tried here (plain "a*b", explicit lo/hi locals,
// named 64-bit accumulator) allocates them to SCRATCH lr/ip instead (push
// {r3,lr} / pop {r3,pc}, 7 instrs) -- 4 bytes short. No FORM change found that
// forces the callee-saved pair for a leaf (no-bl) computation. NOT a match, no
// // USA: tag.
ARM unsigned long long Multiply64_0200cf24(unsigned long long a, unsigned long long b) {
    return a * b;
}
