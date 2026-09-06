#include <globaldefs.h>

struct TableA68;

void* FindEntryByKey(struct TableA68* table, int key);

struct TableRef02081214 {
    struct TableA68* table;
};

// USA: func_02081214
ARM void* FindEntryInTableRef(struct TableRef02081214* ref, int key) {
    return FindEntryByKey(ref->table, key);
}
