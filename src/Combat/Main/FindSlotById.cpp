#include <globaldefs.h>

struct Elem8_0209b944 {
    char data[8];
};
struct SlotEntry0209b944 {
    unsigned short id;
    char pad[2];
    struct Elem8_0209b944 arr[9];
};

// USA: func_0209b944
ARM struct Elem8_0209b944* FindSlotById0209b944(struct SlotEntry0209b944* entries, int index, int key, int* outIdx) {
    int i;
    for (i = 0; i < 6; i++) {
        if (key == entries[i].id) {
            *outIdx = i;
            return &entries[i].arr[index];
        }
    }
    return NULL;
}
