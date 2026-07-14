#include <globaldefs.h>

struct SafeAllocator;
void* DecompressLZ77FileIntoScratchSpace(struct SafeAllocator&, const void*, unsigned int&);
void SwapArgsAndCall0201e2b4(int, int, int, int);

// USA: func_020143d8
ARM int ForwardField68Entry(char* obj, int arg1) {
    int f68 = *(int*)(obj + 0x68);
    int out;
    int r = (int)DecompressLZ77FileIntoScratchSpace(*(struct SafeAllocator*)f68, (const void*)arg1, *(unsigned int*)&out);
    int saved = *(int*)(obj + 0x8);
    SwapArgsAndCall0201e2b4((int)(obj + 0x6c), f68, r, out);
    *(int*)(obj + 0x8) = saved;
    return 1;
}
