#include <globaldefs.h>

void* GetData02108e10(void);
void* SearchBothTables02079e2c(char* p, int key);
void* GetData02153637(void);
void StoreInFirstEmptySlot(unsigned char* base, unsigned char val);

struct Field18_0215b720 {
    unsigned int field0 : 5;
    unsigned int field1 : 7;
    unsigned int rest : 20;
};

// USA: func_ov002_0215b720  (semantic: RegisterOrCheckEntry0215b720)
extern "C" ARM int func_ov002_0215b720(unsigned char* obj, int key) {
    int result = 0;

    if (*(int*)(obj + 0x1000 + 0xbb8) == 6 || *(int*)(obj + 0x1000 + 0xbb8) == 0x11) {
        if (key == 0x198 || key == 0x22 || key == 0x310) {
            result = 1;
        }
    } else {
        void* table = GetData02108e10();
        void* entry = SearchBothTables02079e2c((char*)table, key);
        if (entry != 0) {
            volatile struct Field18_0215b720* f = (volatile struct Field18_0215b720*)((char*)entry + 0x18);
            unsigned int f1 = f->field1;
            unsigned int f0 = f->field0;
            if (f1 == 2 || f1 == 7 || f1 == 0x4f || f1 == 0x50 || f1 == 0x12 || f1 == 0x1a) {
                result = 1;
            }
            if (f0 == 5 && *(int*)(obj + 0x1000 + 0xbb8) == 7) {
                result = 1;
            }
        }
    }

    if (result != 0) {
        void* ctx = GetData02153637();
        StoreInFirstEmptySlot((unsigned char*)ctx, 1);
    }

    return result;
}
