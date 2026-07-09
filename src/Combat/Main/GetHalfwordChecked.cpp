#include <globaldefs.h>

struct List0206f7f4 {
    int field0;
    int count;
    short values[1];
};

// USA: func_0206f7f4
ARM int GetHalfwordChecked(struct List0206f7f4 *list, int index) {
    if (index < 0 || list->count <= index) {
        return -1;
    }
    return list->values[index];
}
