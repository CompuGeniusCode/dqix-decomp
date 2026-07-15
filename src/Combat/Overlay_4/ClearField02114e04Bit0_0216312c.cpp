#include <globaldefs.h>

struct FlagWord020466f4 {
    unsigned int flags;
};
void* GetDataPtr02114e04_020d6c00(void);
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);

// USA: func_ov004_0216312c
ARM int ClearField02114e04Bit0_0216312c(void) {
    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 1);
    return 0;
}
