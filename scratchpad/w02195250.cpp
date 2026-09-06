#include <globaldefs.h>

struct Mid12_02195250 { unsigned char v[12]; };
struct Entry15_02195250 {
    unsigned char a;
    unsigned char b;
    Mid12_02195250 mid;
    unsigned char e;
};

extern "C" void func_ov017_02195214(Entry15_02195250* dst, Entry15_02195250* src);

// USA: func_ov017_02195250
ARM void InsertOrIgnoreEntry15_02195250(unsigned char* obj, Entry15_02195250* key) {
    unsigned char* cache = *(unsigned char**)(obj + 0x4000 + 0x41c);
    if (cache[0] == 2 && cache[2] == key->a) {
        key->e = 1;
    } else {
        key->e = 0;
    }

    Entry15_02195250* arr = (Entry15_02195250*)(obj + 0x4200 + 0xf1);
    int i;
    for (i = 0; i < obj[0x4000 + 0x2f0]; i++) {
        if (arr[i].a == key->a) {
            func_ov017_02195214(&arr[i], key);
            return;
        }
    }

    cache = *(unsigned char**)(obj + 0x4000 + 0x41c);
    if (cache[0] == 1 && cache[2] == key->a) {
        cache[0] = 0;
        cache[1] = 0;
    }

    if (obj[0x4000 + 0x2f0] >= 3) return;
    int cnt = obj[0x4000 + 0x2f0];
    obj[0x4000 + 0x2f0] = cnt + 1;
    func_ov017_02195214((Entry15_02195250*)(obj + 0xf1 + 0x4200) + cnt, key);
}
