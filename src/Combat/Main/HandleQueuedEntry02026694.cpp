#include <globaldefs.h>

int GetData02104304Field4(void);
void AddEntryOrOverflow(unsigned char* obj);
int CallFunc0202fa38ZeroPad(int a, int b, int c);

extern "C" void func_020301c8(int a, int b);
extern "C" int func_0202fdd0(int a, int b);
extern "C" int func_02026780(void* self, int a, int b);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

extern int data_020ef6d7;

// USA: func_02026694
ARM void HandleQueuedEntry02026694(char* self) {
    int obj;
    int out1;
    int out2;

    if (*(unsigned char*)(self + 0x9b8) == 0) {
        return;
    }

    obj = GetData02104304Field4();

    if (*(unsigned char*)(self + 0x9b9) == 0) {
        func_020301c8(obj, *(int*)(self + 0xa2c));
        AddEntryOrOverflow((unsigned char*)obj);
        *(int*)(self + 0xa2c) = CallFunc0202fa38ZeroPad(obj, (int)&data_020ef6d7, 0);
        *(unsigned char*)(self + 0x9b9) += 1;
        return;
    }

    if (*(unsigned char*)(self + 0x9b9) != 1) {
        return;
    }

    if (func_0202fdd0(obj, *(int*)(self + 0xa2c)) == 0) {
        return;
    }

    out1 = 0;
    out2 = 0;
    GetListEntryValues0202fec8((struct List0202fec8*)obj, *(int*)(self + 0xa2c), &out1, &out2);

    if (func_02026780(self, out1, out2) == 0) {
        *(unsigned char*)(self + 0x9ba) = 1;
    } else {
        *(unsigned char*)(self + 0x779) = 1;
        *(unsigned char*)(self + 0x9ba) = 1;
    }

    func_020301c8(obj, *(int*)(self + 0xa2c));
    *(int*)(self + 0xa2c) = -1;
    *(unsigned char*)(self + 0x9b8) = 0;
    *(unsigned char*)(self + 0x9b9) += 1;
}
