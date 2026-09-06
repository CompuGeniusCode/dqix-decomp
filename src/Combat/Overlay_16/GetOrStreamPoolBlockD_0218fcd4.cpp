#include <globaldefs.h>

extern "C" int func_020ca4b4(void*, void*, int);

struct PoolState_0218fcd4 {
    unsigned char pad0[0x8];
    void* cachedPtr;   // 0x8
    unsigned char pad1[0x8];
    unsigned int remaining; // 0x14
    void* cur;         // 0x18
};

extern struct PoolState_0218fcd4 data_ov016_0219d1c0;
extern unsigned char data_ov016_02195f78[1];

// USA: func_ov016_0218fcd4
ARM void* GetOrStreamPoolBlockD_0218fcd4(void) {
    if (data_ov016_0219d1c0.cachedPtr != NULL)
        goto done;
    if (data_ov016_0219d1c0.remaining < 0x659c)
        goto fallback;
    data_ov016_0219d1c0.cachedPtr = data_ov016_0219d1c0.cur;
    func_020ca4b4(data_ov016_02195f78, data_ov016_0219d1c0.cur, 0x659c);
    data_ov016_0219d1c0.cur = (unsigned char*)data_ov016_0219d1c0.cur + 0x659c;
    data_ov016_0219d1c0.remaining -= 0x659c;
    goto done;
fallback:
    return data_ov016_02195f78;
done:
    return data_ov016_0219d1c0.cachedPtr;
}
