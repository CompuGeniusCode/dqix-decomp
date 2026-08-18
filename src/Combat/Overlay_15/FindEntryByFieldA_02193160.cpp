#include <globaldefs.h>

struct ListStruct_0218bae8 { void* base; int pad4; int count; };
void* GetListEntry0218bae8(struct ListStruct_0218bae8* obj, int idx);

struct Obj_02193160 {
    char pad[0x3c];
    struct ListStruct_0218bae8 list;
};

// USA: func_ov015_02193160  (semantic: FindEntryByFieldA_02193160)
extern "C" ARM void* func_ov015_02193160(struct Obj_02193160 *obj, unsigned char cmpVal, int *pIdx) {
    int idx = *pIdx;
    while (idx < obj->list.count) {
        void *entry = GetListEntry0218bae8(&obj->list, idx);
        if (!entry)
            goto notfound;
        if (cmpVal == *((unsigned char *)entry + 0xa)) {
            *pIdx = idx;
            return entry;
        }
        idx++;
    }
notfound:
    return NULL;
}
