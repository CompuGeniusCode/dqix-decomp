#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);
extern "C" void func_020c7898(void* p);

// USA: func_020c7fe0
#pragma optimize_for_size off
ARM int PopQueueEntryOrWait020c7fe0(void* obj, unsigned int* out, int canWait) {
    unsigned int mask = DisableInterrupts();
    if (*(unsigned int*)((char*)obj + 0x1c) == 0) {
        int wait = canWait & 1;
        while (1) {
            if (!wait) {
                RestoreInterrupts(mask);
                return 0;
            }
            func_020c7898((char*)obj + 8);
            if (*(unsigned int*)((char*)obj + 0x1c) != 0) break;
        }
    }
    if (out != NULL) {
        unsigned int* arr = *(unsigned int**)((char*)obj + 0x10);
        unsigned int idx = *(unsigned int*)((char*)obj + 0x18);
        *out = arr[idx];
    }
    RestoreInterrupts(mask);
    return 1;
}
