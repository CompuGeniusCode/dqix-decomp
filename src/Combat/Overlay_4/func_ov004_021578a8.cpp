#include <globaldefs.h>

extern "C" void* func_ov004_02156fa0(void* obj, int key);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Struct021707d8_021578a8 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_021578a8 data_ov004_021707d8;

struct Vec3_021578a8 { int x, y, z; };

class VObj021578a8 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void SetPos(int* v);
    virtual Vec3_021578a8 GetPos();
};

// USA: func_ov004_021578a8
extern "C" ARM void func_ov004_021578a8(void* obj) {
    int vec[3];

    VObj021578a8* node = (VObj021578a8*)func_ov004_02156fa0(obj, 0x517);
    if (node) {
        const Vec3_021578a8& pos = node->GetPos();
        _ZN8Vector3iaSERKS_(vec, (int*)&pos);
        int x = (0xd1 - (data_ov004_021707d8.ptr[0x3e] << 3)) << 0xc;
        vec[0] = x;
        vec[1] = 0x26000;
        node->SetPos(vec);
    }

    VObj021578a8* node2 = (VObj021578a8*)func_ov004_02156fa0(obj, 0x518);
    if (node2) {
        const Vec3_021578a8& pos2 = node2->GetPos();
        _ZN8Vector3iaSERKS_(vec, (int*)&pos2);
        int x2 = (0xd1 - (data_ov004_021707d8.ptr[0x3e] << 3)) << 0xc;
        vec[0] = x2;
        vec[1] = 0x34000;
        node2->SetPos(vec);
    }
}
