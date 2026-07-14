#include <globaldefs.h>

struct SortList0207214c;
struct SortList020721f8;
struct Node020722a4;

void BuildSortedNodeChain0207214c(struct SortList0207214c* list);
void BuildSortedNodeChain020721f8(struct SortList020721f8* list);
void PruneUnflaggedGroups020722a4(struct Node020722a4** list, int n);

struct Entry02071ffc {
    unsigned char pad0[0xc];
    unsigned int pad0c_lo : 20;
    unsigned int typeId   : 8;
    unsigned int pad0c_hi : 4;
    unsigned int pad10_lo : 21;
    unsigned int active   : 1;
    unsigned int pad10_mid: 1;
    unsigned int groupId  : 8;
    unsigned int pad10_hi : 1;
    unsigned char pad14[8];
    struct Entry02071ffc* next;
};

struct Container02071ffc {
    struct Entry02071ffc* head;
    struct Entry02071ffc* array;
    unsigned char pad8[2];
    unsigned short count;
};

// USA: func_02071ffc
ARM struct Entry02071ffc* FilterAndSortEntries02071ffc(struct Container02071ffc* obj, int p1, int p2, int p3, short p4, short* pCounter) {
    unsigned short count = obj->count;
    struct Entry02071ffc* arr = obj->array;
    unsigned short i1, i2, i3;
    struct Entry02071ffc* n;

    obj->head = NULL;
    for (i1 = 0; i1 < count; i1++) {
        struct Entry02071ffc* e = (struct Entry02071ffc*)((char*)arr + (i1 << 5));
        e->next = NULL;
        e->active = 1;
    }
    if (p1 >= 0) {
        for (i2 = 0; i2 < count; i2++) {
            struct Entry02071ffc* e = (struct Entry02071ffc*)((char*)arr + (i2 << 5));
            e->active = (e->typeId == (unsigned int)p1);
        }
    }
    if (p2 >= 0) {
        for (i3 = 0; i3 < count; i3++) {
            struct Entry02071ffc* e = (struct Entry02071ffc*)((char*)arr + (i3 << 5));
            e->active = (e->groupId == (unsigned int)p2);
        }
    }
    if (p3 == 0) {
        BuildSortedNodeChain0207214c((struct SortList0207214c*)obj);
    } else {
        BuildSortedNodeChain020721f8((struct SortList020721f8*)obj);
    }

    *pCounter = 0;
    n = obj->head;
    while (n != NULL) {
        (*pCounter)++;
        n = n->next;
    }

    PruneUnflaggedGroups020722a4((struct Node020722a4**)obj, p4);
    return obj->head;
}
