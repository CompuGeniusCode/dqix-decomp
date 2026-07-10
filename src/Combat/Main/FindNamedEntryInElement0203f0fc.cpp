#include <globaldefs.h>

struct List02040468;
struct Element02040468;
struct Table02040184;

ARM struct Element02040468* GetValidElement02040468(struct List02040468* list, int index);
ARM int FindEntryByName02040184(struct Table02040184* table, const char* name);

struct ElementObj0203f0fc {
    struct List02040468* field0;
    char pad[0x24];
    short field28;
};

// USA: func_0203f0fc
ARM int FindNamedEntryInElement0203f0fc(struct ElementObj0203f0fc* obj, const char* name) {
    struct Element02040468* element;
    short index = obj->field28;
    if (index < 0) {
        return -1;
    }
    element = GetValidElement02040468(obj->field0, index);
    if (element == NULL) {
        return -1;
    }
    return FindEntryByName02040184((struct Table02040184*)((char*)element + 0x10), name);
}
