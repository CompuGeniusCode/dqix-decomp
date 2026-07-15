#include <globaldefs.h>

struct Owner02018b34;
struct Param02018b34;
struct Entry_02028bd0;

struct Entry0201874c {
    char pad0[2];
    unsigned short flags2; // +0x2
    signed char field4;    // +0x4
    char pad5[1];
    short field6; // +0x6
    int vec8[3];  // +0x8
    char pad14[0x34 - 0x14];
    unsigned short field34; // +0x34
    unsigned short field36; // +0x36
    char pad38[0x3a - 0x38];
    unsigned short field3a; // +0x3a
    int vec3c[3];           // +0x3c
    int vec48[3];           // +0x48
};

struct Ref0201874c {
    char pad0[2];
    unsigned short flags2; // +0x2
    char pad4[0x28 - 4];
    void* backPtr; // +0x28
};

struct List0201874c {
    unsigned short field0; // +0x0
    char pad2[0x824 - 2];
    Ref0201874c** field824; // +0x824
    char pad828[0x82c - 0x828];
    int field82c;           // +0x82c
    unsigned char field830; // +0x830
};

struct Obj0201874c {
    char pad0[0x2e];
    unsigned short low4 : 4;
    unsigned short upper12 : 12;
    char pad30[0x6c - 0x30];
    int field6c; // +0x6c
};

struct Vec3 {
    int x, y, z;
};
void AddVec3(Vec3* a, Vec3* b, Vec3* out);
void CopyVec3(int* dst, int* src);

struct Vec3Fixed02030e2c {
    int x, y, z;
};
void ScaleVec3Fixed02030e2c(Vec3Fixed02030e2c* in, int scale, Vec3Fixed02030e2c* out);

struct Entry0201874c* FindEntryByNodeIdAndKey(struct Owner02018b34* owner, struct Param02018b34* p);
int FindMatchingElementIndex02018bc4(unsigned char* obj, void* target);
struct Entry_02028bd0* GetEntryTableBase(void);
struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key);

// USA: func_0201874c
ARM void ReleaseEntryFromList0201874c(struct List0201874c* list, struct Obj0201874c* obj) {
    struct Entry0201874c* entry = FindEntryByNodeIdAndKey((struct Owner02018b34*)list, (struct Param02018b34*)obj);
    if (entry == NULL) {
        return;
    }
    entry->flags2 &= ~1;
    entry->flags2 &= ~4;
    for (int i = 0; i < list->field82c; i++) {
        struct Ref0201874c* r = list->field824[i];
        if (r->backPtr == entry) {
            r->flags2 &= ~1;
            break;
        }
    }
    if (obj->upper12 & 0x20) {
        Vec3Fixed02030e2c scaled;
        ScaleVec3Fixed02030e2c((Vec3Fixed02030e2c*)&entry->vec48, obj->field6c, &scaled);
        Vec3 sum;
        AddVec3((Vec3*)&entry->vec8, (Vec3*)&scaled, &sum);
        entry->vec48[0] = -entry->vec48[0];
        entry->vec48[1] = -entry->vec48[1];
        entry->vec48[2] = -entry->vec48[2];
        CopyVec3(entry->vec3c, (int*)&sum);
        entry->field3a = 0x266;
    } else {
        if (obj->upper12 & 2) {
            entry->field34 = (short)(128.67999267578125f + (float)entry->field6);
        } else {
            entry->field34 = (short)((float)entry->field6 - 128.67999267578125f);
        }
        entry->field36 = 0x199;
        entry->field4 = (entry->field4 & ~0x7f) | 0x1f;
        entry->flags2 |= 0x80;
    }
    obj->upper12 &= ~1;
    list->field830 = 0xf;
    if (obj->upper12 & 8) {
        return;
    }
    int idx = FindMatchingElementIndex02018bc4((unsigned char*)list, obj);
    struct Entry_02028bd0* found = FindInlineEntryById(GetEntryTableBase(), list->field0);
    if (found != NULL) {
        *(unsigned short*)((char*)found + 4) &= ~(1 << idx);
    }
}
