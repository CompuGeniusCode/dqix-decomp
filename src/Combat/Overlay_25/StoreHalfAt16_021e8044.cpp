#include <globaldefs.h>

struct Sub021e8044 {
    char pad[0x16];
    unsigned short f16;
};

struct Base021e8044;

struct Holder021e8044 {
    char pad[0xc];
    struct Base021e8044* base;
};
extern struct Holder021e8044 data_ov025_021ef988;

inline struct Sub021e8044* GetSub021e8044(struct Base021e8044* b) {
    return (struct Sub021e8044*)((char*)b + 0x540);
}

// USA: func_ov025_021e8044  (semantic: StoreHalfAt16_021e8044)
extern "C" ARM int func_ov025_021e8044(void* obj) {
    GetSub021e8044(data_ov025_021ef988.base)->f16 = *(unsigned short*)((char*)obj + 8);
    return 1;
}
