#include <globaldefs.h>

struct Vec3_021536e0 { int x, y, z; };

class Node021536e0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void SetVal0x1c(const Vec3_021536e0& v);
    virtual Vec3_021536e0 GetVal0x20();
};

extern "C" void* func_ov011_021849c8(void* a);
extern "C" Node021536e0* func_ov023_021f6880(void* obj, int key);
int GetField38IfKind8_021f6378(void* a, int key);
void* Lookup4Entry_021f63ac(void* a, int b, int c);

// USA: func_ov004_021536e0  (semantic: SyncVecIfEntryUnset_021536e0)
extern "C" ARM void func_ov004_021536e0(void* a, int b, int c) {
    Node021536e0* node = func_ov023_021f6880(func_ov011_021849c8(a), b);
    if (!node) return;
    char* entry = (char*)Lookup4Entry_021f63ac(a, 4, GetField38IfKind8_021f6378(a, c));
    if (entry != 0 && *entry != 0) return;
    Node021536e0* node2 = func_ov023_021f6880(func_ov011_021849c8(a), c);
    if (!node2) return;
    const Vec3_021536e0& v = node2->GetVal0x20();
    node->SetVal0x1c(v);
}
