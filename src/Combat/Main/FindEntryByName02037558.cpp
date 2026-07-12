#include <globaldefs.h>
#include "std_library_functions.h"

struct List_020347b4;
struct Entry_020347b4;
Entry_020347b4* GetEntryFromList020347b4(List_020347b4* list, int index);
struct U16Field0x4_020347e0;
unsigned short GetU16At0x4(U16Field0x4_020347e0* obj);

struct Node02037558 {
    char pad[0x28];
    struct Node02037558* next;
};

struct Holder02037558 {
    char pad[0xc];
    struct Node02037558* head;
};

// USA: func_02037558
ARM void* FindEntryByName02037558(struct Holder02037558* holder, const char* name) {
    struct Node02037558* node;
    node = holder->head;
    while (node != 0) {
        List_020347b4* list = (List_020347b4*)((char*)node + 4);
        if (list != 0) {
            int i;
            for (i = 0; i < GetU16At0x4((U16Field0x4_020347e0*)list); i++) {
                Entry_020347b4* entry = GetEntryFromList020347b4(list, i);
                if (entry != 0 && strcmp((char*)entry, name) == 0) {
                    return entry;
                }
            }
        }
        node = node->next;
    }
    return 0;
}
