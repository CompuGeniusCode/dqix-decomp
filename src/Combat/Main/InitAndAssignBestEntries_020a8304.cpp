#include <globaldefs.h>

struct Entry020a8458 { unsigned char byte0; unsigned char byte1; char pad[0x2c - 2]; };
struct Obj020a8458 {
    struct Entry020a8458* arr;
    char pad4[2];
    unsigned short count;
};

extern "C" struct Entry020a8458* func_020a8458(struct Obj020a8458* obj);

struct Obj020a8304 {
    struct Entry020a8458* arr;
    char pad4[2];
    unsigned short count;
    struct Entry020a8458* f8;
    unsigned short fc;
};

// USA: func_020a8304  (semantic: InitAndAssignBestEntries_020a8304)
extern "C" ARM void func_020a8304(struct Obj020a8304* obj) {
    int i;
    for (i = 0; i < obj->count; i++) {
        struct Entry020a8458* e = (struct Entry020a8458*)((char*)obj->arr + i * 0x2c);
        e->byte1 = 0xff;
    }
    obj->f8 = 0;
    obj->fc = 0;
    struct Entry020a8458* cur = func_020a8458((struct Obj020a8458*)obj);
    if (cur == 0) {
        return;
    }
    obj->f8 = cur;
    cur->byte1 = 0;
    obj->fc = obj->fc + 1;
    unsigned char flag = 1;
    while (cur != 0) {
        struct Entry020a8458* next = func_020a8458((struct Obj020a8458*)obj);
        *(int*)((char*)cur + 0x28) = (int)next;
        if (next != 0) {
            next->byte1 = flag;
            flag = (unsigned char)(flag + 1);
            obj->fc = obj->fc + 1;
        }
        cur = next;
    }
}
