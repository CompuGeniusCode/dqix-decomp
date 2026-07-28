#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void);
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
struct Obj02046574;
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
struct StoreStruct;
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
extern "C" void func_0204500c(void*, int, int, int);

// USA: func_ov003_0216d8d4  (semantic: SetIndexedNameAndStoreValues_0216d8d4)
extern "C" ARM void func_ov003_0216d8d4(char* obj, int keyA, int p3, int p4, int p5) {
    int g = GetGlobalField0x1c020421a0();
    func_02046380();

    if (p3 >= 0) {
        struct Container020e0310* c = (struct Container020e0310*)(obj + 0x324 + 0x1000);
        int name = GetFieldByKey020e0434(c, (short)p3);
        SetIndexedName02046574((struct Obj02046574*)g, 5, (char*)name);
    }
    if (p4 >= 0) {
        StoreInArray0x8b0((struct StoreStruct*)g, 1, p4);
    }
    if (p5 >= 0) {
        StoreInArray0x8b0((struct StoreStruct*)g, 0, p5);
    }

    struct Container020e0310* c2 = (struct Container020e0310*)(obj + 0x324 + 0x1000);
    int name2 = GetFieldByKey020e0434(c2, (short)keyA);
    func_0204500c((void*)g, name2, 0, 0xe3);

    *(unsigned char*)(g + 0x1000 + 0x9b2) = 1;
    *(int*)(g + 0x99c) = 2;
}
