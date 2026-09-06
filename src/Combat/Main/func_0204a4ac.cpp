#include <globaldefs.h>

struct Struct0207ea38;

struct KeyNodeOwner {
    char pad0[0x8];
    struct Struct0207ea38* text;
};

struct Item02037af8 {
    unsigned short key;
    char pad2[0x36];
};

extern "C" int _ZN7Model3D12GetBoneIndexEPKc(struct Struct0207ea38* obj, char* str);
extern "C" void _ZN8Object3D18UntrackBoneByIndexEi(struct KeyNodeOwner* owner, int key);
extern "C" void _ZN8Object3D9TrackBoneEPNS_17TrackedBoneMatrixE(void* owner, struct Item02037af8* item);

struct Holder0204a4ac {
    char pad0[0x21c];
    struct KeyNodeOwner* owner;
    char pad1[0x4];
    char nameA[0x10];
    char nameB[0x10];
    char nameC[0x10];
    int keyA;
    int keyB;
    int keyC;
};

extern struct Item02037af8 data_02107870[3];
extern struct Item02037af8 data_021078a8;
extern struct Item02037af8 data_021078e0;

// USA: func_0204a4ac  (semantic: RefreshNameNodes0204a4ac)
extern "C" ARM void func_0204a4ac(struct Holder0204a4ac* self) {
    struct Struct0207ea38* text;

    if (self->owner == NULL || (text = self->owner->text) == NULL) return;

    if (self->keyB >= 0) _ZN8Object3D18UntrackBoneByIndexEi(self->owner, self->keyA);
    if (self->keyB >= 0) _ZN8Object3D18UntrackBoneByIndexEi(self->owner, self->keyB);
    if (self->keyC >= 0) _ZN8Object3D18UntrackBoneByIndexEi(self->owner, self->keyC);

    if (self->keyA == -1) self->keyA = _ZN7Model3D12GetBoneIndexEPKc(text, self->nameA);
    if (self->keyB == -1) self->keyB = _ZN7Model3D12GetBoneIndexEPKc(text, self->nameB);
    if (self->keyC == -1) self->keyC = _ZN7Model3D12GetBoneIndexEPKc(text, self->nameC);

    if (self->keyB >= 0) {
        data_02107870[0].key = self->keyA;
        _ZN8Object3D9TrackBoneEPNS_17TrackedBoneMatrixE(self->owner, &data_02107870[0]);
    }
    if (self->keyB >= 0) {
        data_02107870[1].key = self->keyB;
        _ZN8Object3D9TrackBoneEPNS_17TrackedBoneMatrixE(self->owner, &data_021078a8);
    }
    if (self->keyC >= 0) {
        data_02107870[2].key = self->keyC;
        _ZN8Object3D9TrackBoneEPNS_17TrackedBoneMatrixE(self->owner, &data_021078e0);
    }
}
