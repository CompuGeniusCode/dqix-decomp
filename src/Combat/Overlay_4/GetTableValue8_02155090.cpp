#include <globaldefs.h>

struct Entry6_021550c8 { short id; char pad[4]; };
void* FindEntryByShort2_021550c8(Entry6_021550c8* arr, int key);
extern char* data_ov004_021707c4;

// USA: func_ov004_02155090  (semantic: GetTableValue8_02155090)
extern "C" ARM int func_ov004_02155090(void) {
    Entry6_021550c8* arr = (Entry6_021550c8*)data_ov004_021707c4;
    int val = 0;
    void* entry = FindEntryByShort2_021550c8(arr, 8);
    if (entry) {
        val = val + *((unsigned char*)entry + 5);
        val = (val << 16) >> 16;
    }
    return val;
}
