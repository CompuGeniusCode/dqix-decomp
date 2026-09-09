#include <globaldefs.h>

struct Entry0205d2bc { unsigned char b[0x20]; };

struct Obj0205d2bc {
    char pad0[0x98];
    struct Entry0205d2bc* field98;   // 0x98
    char pad1[0xb2 - 0x9c];
    unsigned char fieldB2;           // 0xb2
};

extern "C" void func_0204b088(struct Entry0205d2bc*, int);

// Pushes every 0x20-byte entry at +0x98, count at +0xb2, through func_0204b088, which uses the
// nibbles of the entry's +0x1c to pick one of the eight loaders in data_020f0218 (main and sub
// BG0..BG3 screen data) and hands it the buffer at entry+0x14 and a length from data_020e7b98,
// the table of NDS text and extended-affine screen-data sizes. func_0207fd88 is the same loop
// over the second copy of the pair at +0x2c/+0x38, and the same object owns the 0xe0-byte
// elements that FindTextWindowById searches.
extern "C" ARM void UploadAllBGScreenData(struct Obj0205d2bc* obj) {
    unsigned char i;
    if (obj->field98 == 0) return;
    for (i = 0; i < obj->fieldB2; i++) {
        func_0204b088(&obj->field98[i], 0);
    }
}
