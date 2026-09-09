#include <globaldefs.h>

extern "C" void func_0204b04c(void*, int);
extern "C" void func_0204b088(void*, int);

struct List0204b0e8 {
    char pad0[0x14];
    void* field14;
};

// Uploads a written tilemap surface to a BG screen. func_0204b04c cleans and invalidates the cache
// over the buffer at +0x14 for the length data_020e7b98[byte 0x1f][word 0x18] gives -- row 0 is the
// four NDS text-BG screen sizes, row 1 the four affine ones -- and func_0204b088 then copies it out
// through the table at 0x020f0218, whose eight entries are LoadToMain/SubBG0..3ScreenData, picked by
// the two nibbles of byte 0x1c. Passing null for the buffer means "the object's own". ov020 runs it
// as the last step of building the publisher screen.
extern "C" ARM void UploadTilemapToBGScreen(struct List0204b0e8* obj, void* buf) {
    if (buf == NULL) buf = obj->field14;
    if (buf == NULL) return;
    func_0204b04c(obj, (int)buf);
    func_0204b088(obj, (int)buf);
}
