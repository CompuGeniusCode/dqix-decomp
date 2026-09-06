#include <globaldefs.h>

void* GetData02108e10(void);
void* SearchBothTables02079e2c(char* p, int key);
struct List021600f8;
void* GetNodeAtIndex021600f8(struct List021600f8* list, int index);
extern "C" int func_ov000_0215ffa0(void* node);
extern "C" void func_ov025_021ecc54(void* a, void* obj);
int ClassifyField0x81fe(char* base);

extern int data_ov025_021ef988[];

struct Obj021e2f54 {
    char pad0[0x26];
    unsigned short field26;
};

struct Entry021e2f54 {
    char pad0[0x14];
    unsigned int field14;
};

struct ListWithKey021e2f54 {
    short key;
};

// USA: func_ov025_021e2f54
ARM void UpdateEntryFlags_021e2f54(void* obj, struct ListWithKey021e2f54* list, char* p) {
    struct Obj021e2f54* self = (struct Obj021e2f54*)obj;
    void* base = *(void**)((char*)data_ov025_021ef988 + 0xc);
    void* target = (char*)base + 0x22c;
    struct Entry021e2f54* entry;
    struct List021600f8* node;

    void* table = GetData02108e10();
    entry = (struct Entry021e2f54*)SearchBothTables02079e2c((char*)table, list->key);
    node = (struct List021600f8*)GetNodeAtIndex021600f8((struct List021600f8*)list, 0);

    if (entry != NULL && node != NULL) {
        int v1 = func_ov000_0215ffa0(node);
        int ok;
        if (v1 >= 0xc0) {
            int v2 = func_ov000_0215ffa0(node);
            if (v2 <= 0xc7) {
                ok = 1;
                goto ok_check;
            }
        }
        ok = 0;
    ok_check:
        if (ok) {
            unsigned int kind = entry->field14 >> 0x1c;
            if (kind == 4) {
                self->field26 |= 0x8;
                func_ov025_021ecc54(target, obj);
                self->field26 = 7;
                func_ov025_021ecc54(target, obj);
            } else {
                func_ov025_021ecc54(target, obj);
            }
        } else {
            func_ov025_021ecc54(target, obj);
        }
    } else {
        func_ov025_021ecc54(target, obj);
    }

    if (ClassifyField0x81fe(p) != 0) {
        int* flags = (int*)((char*)*(void**)((char*)data_ov025_021ef988 + 0xc) + 0x1c4);
        *flags |= 0x10;
    }
}
