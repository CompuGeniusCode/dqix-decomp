#include <globaldefs.h>

struct Vec3020B3B3C { int x, y, z; };

struct CombatBlendState_020b3bac {
    int flags;
    Vec3020B3B3C delta1;
    Vec3020B3B3C delta2;
    Vec3020B3B3C delta3;
    Vec3020B3B3C vecA;
    Vec3020B3B3C vecB;
    Vec3020B3B3C vecC;
    Vec3020B3B3C vecD;
};

struct CombatEffectSource_020b3bac {
    char pad0[4];
    int amount;
    char pad1[4];
    void (*apply)(CombatBlendState_020b3bac*, CombatEffectSource_020b3bac*, unsigned char);
    CombatEffectSource_020b3bac* next;
    char pad2[5];
    unsigned char count;
};

extern "C" void func_020ca458(unsigned int value, void* dest, int count);
extern "C" void func_020ca408(const void* src, void* dst, unsigned int size);
extern "C" ARM int _Z23HwDivideRounded020c2bf4jj(unsigned int numerHi, unsigned int denomLo);
void AccumulateScaledVec3(Vec3020B3B3C* out, Vec3020B3B3C* src, int scalar, int addDirect);
extern "C" void _Z25CrossProductFixed020c2e34PiS_S_(int* a, int* b, int* out);
extern "C" void func_020c2f18(Vec3020B3B3C* v, Vec3020B3B3C* out);

// USA: func_020b3bac
#pragma optimize_for_size off
extern "C" ARM int func_020b3bac(CombatBlendState_020b3bac* out, CombatEffectSource_020b3bac* list, unsigned int index) {
    if (list == 0) return 0;

    if (list->next == 0) {
        if (index < list->count) {
            unsigned short type = *(unsigned short*)((char*)list + index * 2 + 0x1a);
            if ((type & 0x300) == 0x100) {
                if (list->apply == 0) return 0;
                list->apply(out, list, (unsigned char)(type & 0xff));
                return 1;
            }
            return 0;
        }
        return 0;
    }

    int total = 0;
    CombatEffectSource_020b3bac* cursor;
    int matchCount = 0;
    int nodeIndex = 0;
    CombatEffectSource_020b3bac* matched;
    cursor = list;
    do {
        if (index < cursor->count) {
            unsigned short type = *(unsigned short*)((char*)cursor + index * 2 + 0x1a);
            if ((type & 0x300) == 0x100) {
                int amount = cursor->amount;
                if (amount > 0x1000) total += 0x1000;
                else if (amount > 0) total += amount;
                matched = cursor;
                matchCount++;
            }
        }
        cursor = cursor->next;
    } while (cursor != 0);

    if (total == 0) return 0;

    if (matchCount == 1) {
        unsigned short type = *(unsigned short*)((char*)matched + index * 2 + 0x1a);
        if (matched->apply == 0) return 0;
        matched->apply(out, matched, (unsigned char)(type & 0xff));
        return 1;
    }

    func_020ca458(0, out, 0x58);
    out->flags = -1;

    Vec3020B3B3C savedA;
    Vec3020B3B3C savedC;
    CombatBlendState_020b3bac tmp;

    do {
        if (index < list->count) {
            unsigned short type = *(unsigned short*)((char*)list + index * 2 + 0x1a);
            if ((type & 0x300) == 0x100) {
                int amount = list->amount;
                if (amount > 0 && list->apply != 0) {
                    unsigned char subtype = (unsigned char)(type & 0xff);
                    list->apply(&tmp, list, subtype);

                    if (nodeIndex == 0) {
                        func_020ca408(&tmp.vecA, &savedA, 0xc);
                        func_020ca408(&tmp.vecC, &savedC, 0xc);
                    }

                    int weight;
                    if (total == 0x1000) weight = list->amount;
                    else weight = _Z23HwDivideRounded020c2bf4jj(list->amount, total);

                    AccumulateScaledVec3(&out->delta1, &tmp.delta1, weight, tmp.flags & 1);
                    AccumulateScaledVec3(&out->delta2, &tmp.delta2, weight, tmp.flags & 8);
                    AccumulateScaledVec3(&out->delta3, &tmp.delta3, weight, tmp.flags & 0x10);

                    if (!(tmp.flags & 4)) {
                        out->vecD.x = out->vecD.x + (int)(((long long)weight * tmp.vecD.x) >> 12);
                        out->vecD.y = out->vecD.y + (int)(((long long)weight * tmp.vecD.y) >> 12);
                        out->vecD.z = out->vecD.z + (int)(((long long)weight * tmp.vecD.z) >> 12);
                    }

                    if (!(tmp.flags & 2)) {
                        out->vecA.x = out->vecA.x + ((weight * tmp.vecA.x) >> 12);
                        out->vecA.y = out->vecA.y + ((weight * tmp.vecA.y) >> 12);
                        out->vecA.z = out->vecA.z + ((weight * tmp.vecA.z) >> 12);
                        out->vecB.x = out->vecB.x + ((weight * tmp.vecB.x) >> 12);
                        out->vecB.y = out->vecB.y + ((weight * tmp.vecB.y) >> 12);
                        out->vecB.z = out->vecB.z + ((weight * tmp.vecB.z) >> 12);
                    } else {
                        out->vecA.x = out->vecA.x + weight;
                        out->vecB.y = out->vecB.y + weight;
                    }

                    out->flags = out->flags & tmp.flags;
                }
            }
        }
        list = list->next;
        nodeIndex++;
    } while (list != 0);

    _Z25CrossProductFixed020c2e34PiS_S_((int*)&out->vecA, (int*)&out->vecB, (int*)&out->vecC);

    if (out->vecA.x == 0 && out->vecA.y == 0 && out->vecA.z == 0) {
        func_020ca408(&savedA, &out->vecA, 0xc);
    } else {
        func_020c2f18(&out->vecA, &out->vecA);
    }

    if (out->vecC.x == 0 && out->vecC.y == 0 && out->vecC.z == 0) {
        func_020ca408(&savedC, &out->vecC, 0xc);
    } else {
        func_020c2f18(&out->vecC, &out->vecC);
    }

    _Z25CrossProductFixed020c2e34PiS_S_((int*)&out->vecC, (int*)&out->vecA, (int*)&out->vecB);

    return 1;
}
