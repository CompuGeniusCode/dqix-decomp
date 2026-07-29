#include <globaldefs.h>

// SKIP attempt func_020ca3ec: target loop is a 3-branch diamond (top cmp+blt+b,
// single-word stmia-with-writeback body, bottom blt that reuses the TOP cmp's
// flags rather than re-comparing) -- not the plain 2-block while/do-while
// skeleton mwcc normally emits (recipe #18). Guarded do-while, plain while, and
// volatile-pointer variants all collapse the guard to a single "bxhs lr" and use
// a post-inc "str" instead of "stmia r1!,{r0}". Matches the VectorizedMemset/
// memcpy-family SKIP category (worker_ov_all.md "Do NOT"). NOT a match, no
// // USA: tag.
ARM void FillWordRangeConst020ca3ec(unsigned int value, unsigned int* p, int byteCount) {
    unsigned int* end = (unsigned int*)((char*)p + byteCount);
    if (p < end) {
        do {
            *p++ = value;
        } while (p < end);
    }
}
