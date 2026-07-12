#include <globaldefs.h>

struct Elem020b7798 {
    unsigned short count;
    unsigned short unk2;
    short scale;
    unsigned short arrOff;
};

struct Entry020b7798 { unsigned short key; unsigned short pad; };

struct List_b780c;
void* GetListElement(struct List_b780c* list, unsigned int index);

// USA: func_020b7798
ARM void* FindBracketEntry020b7798(struct List_b780c* obj, unsigned int index, unsigned int target) {
    struct Elem020b7798* elem = (struct Elem020b7798*)GetListElement(obj, index);
    short scale = elem->scale;
    unsigned short arrOff = elem->arrOff;
    int prod = scale * (int)target;
    struct Entry020b7798* arr = (struct Entry020b7798*)((char*)obj + arrOff);
    unsigned int i = (unsigned int)prod >> 12;
    while (i != 0 && arr[i].key >= target) {
        i--;
    }
    unsigned short count = elem->count;
    while (i + 1 < count && *(unsigned short*)((char*)(arr + i) + 4) <= target) {
        i++;
    }
    return &arr[i];
}
