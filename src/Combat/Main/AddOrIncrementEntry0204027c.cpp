#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry0204027c {
    char name[0x38];
    int flag;
};

struct Container0204027c {
    unsigned int count;
    unsigned char counter;
    unsigned char skipFind;
    unsigned char pad6;
    unsigned char pad7;
    struct Entry0204027c* entries;
};

struct Container02040404;
int FindEntryIndexByName02040404(struct Container02040404* container, const char* name);
void CheckSuffixAndLoadResource0203fce0(void* p0, char* p1, int p2);
extern "C" void func_0203fd5c(void* p0, void* buf, int p2, void* p3);

// USA: func_0204027c  (semantic: AddOrIncrementEntry0204027c)
extern "C" ARM int func_0204027c(struct Container0204027c* container, const char* name, int p2, void* p3) {
    int index;
    unsigned int i;
    unsigned char skipFind;
    if (container->entries == NULL) {
        return -1;
    }
    skipFind = container->skipFind;
    index = -1;
    if (skipFind == 0) {
        index = FindEntryIndexByName02040404((struct Container02040404*)container, name);
    }
    if (index > -1) {
        container->entries[index].flag++;
        return index;
    }
    for (i = 0; i < container->count; i++) {
        if (container->entries[i].flag < 0) {
            index = i;
            break;
        }
    }
    if (index < 0) {
        return -1;
    }
    if (p3 != NULL) {
        func_0203fd5c((char*)&container->entries[index] + 0x10, (void*)name, p2, p3);
    } else {
        CheckSuffixAndLoadResource0203fce0((char*)&container->entries[index] + 0x10, (char*)name, p2);
    }
    container->entries[index].flag = 0;
    strcpy((char*)&container->entries[index], name);
    container->counter++;
    return index;
}
