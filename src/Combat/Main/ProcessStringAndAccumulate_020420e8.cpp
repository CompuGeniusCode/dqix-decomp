#include <globaldefs.h>

extern int data_020e7a94[];
int FindEntryIndexByKey020424e4(int key, int tableIdx);
void* GetBoundedEntry020425b4(int idx, int tableIdx);
int LookupKeyValue020425e4(int a, int b, int tableIdx);

struct Entry020420e8 {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

// USA: func_020420e8  (semantic: ProcessStringAndAccumulate_020420e8)
extern "C" ARM int func_020420e8(char* str, int id) {
    if (str == 0) return 0;
    int mask = data_020e7a94[id] & 0xff;
    int resetState = 0xff;
    int state = resetState;
    int masked;
    int total = 0;
    for (;;) {
        if (*str == 0) break;
        int delta = mask + 1;
        int idx = FindEntryIndexByKey020424e4((int)str, id);
        if (idx < 0) {
            state = resetState;
            str++;
        } else {
            masked = idx & 0xff;
            struct Entry020420e8* entry = (struct Entry020420e8*)GetBoundedEntry020425b4(idx, id);
            int val = LookupKeyValue020425e4(state, masked, id);
            state = masked;
            delta = (entry->pad4 + 1) + val;
            str = str + entry->field5;
        }
        total += delta;
    }
    return total - 1;
}
