#include <globaldefs.h>

struct NameTable02048080 {
    int count;
    void* entries;
};

// USA: func_02048080
ARM void ClearNameTable(struct NameTable02048080* table) {
    table->count = 0;
    table->entries = NULL;
}
