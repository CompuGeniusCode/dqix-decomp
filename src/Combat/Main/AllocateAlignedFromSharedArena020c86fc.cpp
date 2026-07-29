#include <globaldefs.h>

int GetSharedWordDa0(int index);
int GetSharedWordDc4(int index);
void SetSharedWordDa0(int index, int value);

// USA: func_020c86fc  (semantic: AllocateAlignedFromSharedArena020c86fc)
extern "C" ARM int func_020c86fc(int handle, int size, int align) {
    int cur = GetSharedWordDa0(handle);
    if (cur == 0) return 0;
    int start = (cur + align - 1) & ~(align - 1);
    int sum = start + size;
    int next = (sum + align - 1) & ~(align - 1);
    int limit = GetSharedWordDc4(handle);
    if ((unsigned int)next > (unsigned int)limit) return 0;
    SetSharedWordDa0(handle, next);
    return start;
}
