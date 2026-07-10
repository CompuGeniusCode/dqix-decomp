#include <globaldefs.h>

struct Variant02030b0c { int tag; int val; };
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct EntryTable0209bd94;
void SetEntryField0209be28(struct EntryTable0209bd94* table, int key, int* value);

struct Recorder0209bb0 {
    struct EntryTable0209bd94* table;   // 0x0
    unsigned char pad[0x10];            // 0x4
    int active;                         // 0x14
    int key;                            // 0x18
};
extern struct Recorder0209bb0* data_02109bb0;

// USA: func_0209ba2c
ARM int SetEntryFieldFromVariant0209ba2c(struct Variant02030b0c* variant) {
    if (data_02109bb0->active != 0) {
        int value = GetIntFromVariant02030b0c(variant);
        SetEntryField0209be28(data_02109bb0->table, data_02109bb0->key, &value);
    }
    return 1;
}
