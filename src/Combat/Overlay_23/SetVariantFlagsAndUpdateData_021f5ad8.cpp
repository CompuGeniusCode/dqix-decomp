#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

extern "C" void* func_02012fe4(void);

struct Data021fff08Val_021f5ad8 {
    char pad[0x10c];
    unsigned short val : 13;
    unsigned short flag : 3;
};

struct Data021fff08_021f5ad8 {
    char pad2[0xc];
    struct Data021fff08Val_021f5ad8* ptr;
};

extern struct Data021fff08_021f5ad8 data_ov023_021fff08;

// USA: func_ov023_021f5ad8
extern "C" ARM int func_ov023_021f5ad8(struct Variant02030b0c* arr, int count) {
    char* base = (char*)func_02012fe4();
    char* p840 = base + 0x840;
    unsigned int* flagsA = (unsigned int*)(p840 + 0x348 + 0x1800);
    unsigned int* flagsB = (unsigned int*)(p840 + 0x34c + 0x1800);
    char* rec = p840 + 0x1000;
    int i;
    int bit = 1;

    for (i = 0; i < count; i++) {
        int idx = GetIntFromVariant02030b0c(arr);
        unsigned int cur = *(unsigned int*)(rec + 0xb48);
        arr = (struct Variant02030b0c*)((char*)arr + 8);
        if (!(cur & (bit << idx))) {
            *flagsA |= (bit << idx);
            *flagsB |= (bit << idx);
            *(unsigned char*)(rec + 0xb61) = 1;
            data_ov023_021fff08.ptr->val |= 0x200;
        }
    }
    return 1;
}
