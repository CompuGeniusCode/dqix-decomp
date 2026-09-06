#include <globaldefs.h>

struct Variant02030b0c { int tag; int u; };
struct Struct02030b7c { int field0; void* field4; };
struct Entry0201f8d0 { struct Variant02030b0c key; struct Struct02030b7c value; };
struct Obj02026b0c;
struct Obj02026b3c;

extern int data_020fdc4c;
void ClearRecords02026644(char* obj);
void AllocateNameBuffer02026b0c(struct Obj02026b0c* p, int n);
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
void* GetField4IfField0Zero(struct Struct02030b7c* s);
void SetEntry02026b3c(struct Obj02026b3c* obj, unsigned int index, short id, const char* name);
typedef void (*SetEntry02026b3c_U)(struct Obj02026b3c*, unsigned int, unsigned short, const char*);

// USA: func_0201f8d0
ARM int PopulateEntriesFromVariantPairs0201f8d0(struct Entry0201f8d0* list, int n) {
    int count = n / 2;
    void* obj = *(void**)((char*)&data_020fdc4c + 0x10);
    ClearRecords02026644((char*)obj);
    obj = *(void**)((char*)&data_020fdc4c + 0x10);
    AllocateNameBuffer02026b0c((struct Obj02026b0c*)obj, count & 0xff);
    struct Entry0201f8d0* p = list;
    for (int i = 0; i < count; i++) {
        int id = GetIntFromVariant02030b0c(&p->key);
        struct Struct02030b7c* val = &p->value;
        p++;
        void* name = GetField4IfField0Zero(val);
        obj = *(void**)((char*)&data_020fdc4c + 0x10);
        ((SetEntry02026b3c_U)SetEntry02026b3c)((struct Obj02026b3c*)obj, (unsigned char)i, id, (const char*)name);
    }
    return 1;
}
