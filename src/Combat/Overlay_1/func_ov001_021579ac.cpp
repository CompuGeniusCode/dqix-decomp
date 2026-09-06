#include <globaldefs.h>

struct Vec3s32_020c3030 { int x; int y; int z; };

extern "C" int Vector3fix_Distance(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

struct SrcVec02157570 {
    unsigned char pad0[0x38c];
    int x;
    int y;
    int z;
};
struct DstVec02157570 {
    int x;
    int y;
    int z;
};
void CopyVector3_02157570(struct SrcVec02157570* src, struct DstVec02157570* dst);

extern "C" ARM int fix32_Divide(unsigned int numerHi, unsigned int denomLo);

extern "C" int func_ov001_021573c0(void* p);
extern "C" void func_ov001_02156c14(void* dst, void* self, int* arr, int count, int extra);

struct Ring021579ac {
    struct Vec3s32_020c3030 slots[16];
    int pad0xc0;
    int count;
};

// USA: func_ov001_021579ac  (semantic: AdvanceRingAndComputePace_021579ac)
extern "C" ARM int func_ov001_021579ac(struct Ring021579ac* self) {
    if (self->count <= 0) {
        return 1;
    }

    int workArr[32];
    struct Vec3s32_020c3030 vecB;
    struct Vec3s32_020c3030 vecA;

    int i;
    int total = 0;
    for (i = 0; i < self->count - 1; i++) {
        workArr[i] = Vector3fix_Distance(&self->slots[i], &self->slots[i + 1]);
        total += workArr[i];
    }

    i = 0;
    int* paceArr = workArr + 16;
    while (i < self->count - 1) {
        paceArr[i] = self->pad0xc0 / (self->count - 1);
        i++;
    }

    func_ov001_02156c14((char*)self + 0xc8, self, workArr + 16, self->count, 0);

    total = 0;
    do {
        CopyVector3_02157570((struct SrcVec02157570*)((char*)self + 0xc8), (struct DstVec02157570*)&vecB);
        if (func_ov001_021573c0((char*)self + 0xc8) != 0) {
            break;
        }
        CopyVector3_02157570((struct SrcVec02157570*)((char*)self + 0xc8), (struct DstVec02157570*)&vecA);
        total += Vector3fix_Distance(&vecB, &vecA);
    } while (1);

    int avg = fix32_Divide(total, self->pad0xc0 << 12);
    func_ov001_02156c14((char*)self + 0xc8, self, workArr + 16, self->count, avg);

    return 0;
}
