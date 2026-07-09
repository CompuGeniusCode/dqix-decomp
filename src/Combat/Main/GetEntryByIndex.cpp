#include <globaldefs.h>

struct GetEntry0209a654 {
    char pad[12];
};
struct GetList0209a654 {
    struct GetEntry0209a654* entries;
    int count;
};

// USA: func_0209a654
ARM struct GetEntry0209a654* GetEntryByIndex0209a654(struct GetList0209a654* list, unsigned int index) {
    if (list->count <= index) {
        return NULL;
    }
    return &list->entries[index];
}
