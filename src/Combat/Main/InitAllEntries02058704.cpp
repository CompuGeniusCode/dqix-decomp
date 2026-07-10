#include <globaldefs.h>

struct Foo02057930;
unsigned char* InitAndReturnArg02059cb4(unsigned char* obj);
void InitStruct02057930(struct Foo02057930* p);

struct Entry02058704 { unsigned char b[0xd4]; };
struct Obj02058704 {
    int f0;                       // 0x0
    int f4;                       // 0x4
    struct Entry02058704 arr[16]; // 0x8 .. 0xd48
};

// USA: func_02058704
ARM struct Obj02058704* InitAllEntries02058704(struct Obj02058704* obj) {
    struct Entry02058704* p = obj->arr;
    do {
        InitAndReturnArg02059cb4((unsigned char*)p);
        p++;
    } while (p < &obj->arr[16]);
    InitStruct02057930((struct Foo02057930*)obj);
    return obj;
}
