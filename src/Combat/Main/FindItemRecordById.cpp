#include <globaldefs.h>

struct ItemRecord {
    unsigned int unknown0[8];
};

struct RecordTable {
    unsigned short count;
    unsigned char unknown2[10];
    struct ItemRecord* base;
};

typedef int (*RecordIdFunc)(struct ItemRecord*);

extern "C" int func_020de56c(void*);
extern "C" struct ItemRecord* func_020de650(struct RecordTable* table, int key, RecordIdFunc fn);

struct ItemTable {
    unsigned short count;          // 0x0
    unsigned char unknown2[10];         // 0x2
    struct ItemRecord* base;  // 0xc
    unsigned char unknown10[4];         // 0x10
    unsigned char useBinarySearch; // 0x14
};

// Finds an item's record by id. The tables these containers wrap come from data/prm/itemdt.gp2
// (member itemdt_<LG>.nat) via several builders -- func_0207d6dc, func_02016804, func_0201b53c and
// others -- while ov000 wraps itemdt_w.gp2 instead; the records are 0x20 bytes with the id as the
// halfword at +0x18, which is all the two-instruction key function func_020de56c reads. When
// useBinarySearch at +0x14 is set the shared binary search runs instead of the linear scan, so it
// seems to mark the table as already sorted. ov003 reads +0x1a of the result as a unit price
// against the 9,999,999 gold cap, and ov002 keys the call with an inventory item id.
extern "C" ARM struct ItemRecord* FindItemRecordById(struct ItemTable* table, int key) {
    int recordIndex;
    struct ItemRecord* record;
    unsigned short count;
    if (key < 0) {
        return NULL;
    }
    if (table->useBinarySearch != 0) {
        return func_020de650((struct RecordTable*)table, key, (RecordIdFunc)func_020de56c);
    }
    record = table->base;
    if (record == NULL || (RecordIdFunc)func_020de56c == NULL) {
        record = NULL;
        goto done;
    }
    count = table->count;
    if (count == 0) {
        record = NULL;
        goto done;
    }
    for (recordIndex = 0; recordIndex < count; recordIndex++, record++) {
        if (key == func_020de56c(record)) {
            goto done;
        }
    }
    record = NULL;
done:
    return record;
}
