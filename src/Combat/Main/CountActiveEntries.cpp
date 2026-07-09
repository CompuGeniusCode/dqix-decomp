#include <globaldefs.h>

struct ActiveEntry02046900 {
    signed char active;
    char pad[0x47];
    int stride;
};

// USA: func_02046900
ARM int CountActiveEntries(struct ActiveEntry02046900* entry) {
    int count = 0;
    while (entry->active ? 1 : 0) {
        count++;
        entry = (struct ActiveEntry02046900*)((char*)entry + entry->stride);
    }
    return count;
}
