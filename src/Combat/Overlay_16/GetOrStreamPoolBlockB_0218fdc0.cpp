#include <globaldefs.h>

extern "C" int func_020ca4b4(void*, void*, int);

struct PoolState_0218fdc0 {
    void* cachedPtr;   // 0x0
    unsigned char pad0[0x8];
    unsigned int remaining; // 0xc
    void* cur;         // 0x10
};

extern struct PoolState_0218fdc0 data_ov016_0219d1c0;
extern unsigned char data_ov016_0219cbe0[1];

// USA: func_ov016_0218fdc0
ARM void* GetOrStreamPoolBlockB_0218fdc0(void) {
    if (data_ov016_0219d1c0.cachedPtr != NULL)
        goto done;
    if (data_ov016_0219d1c0.remaining < 0x300)
        goto fallback;
    data_ov016_0219d1c0.cachedPtr = data_ov016_0219d1c0.cur;
    func_020ca4b4(data_ov016_0219cbe0, data_ov016_0219d1c0.cur, 0x300);
    data_ov016_0219d1c0.cur = (unsigned char*)data_ov016_0219d1c0.cur + 0x300;
    data_ov016_0219d1c0.remaining -= 0x300;
    goto done;
fallback:
    return data_ov016_0219cbe0;
done:
    return data_ov016_0219d1c0.cachedPtr;
}
