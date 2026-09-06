#include <globaldefs.h>

extern "C" void* _Z15GetBattleStructv(void);
extern "C" unsigned int _Z19GetBattleScaleCountP12BattleStruct(void*);
extern "C" void func_ov001_02164808(int, int, void*);
extern int data_ov001_02165884;

struct Vec3_02159bbc { int x, y, z; };
extern "C" void Vector3fix_Subtract(Vec3_02159bbc*, Vec3_02159bbc*, Vec3_02159bbc*);
extern "C" void Vector3fix_Add(Vec3_02159bbc*, Vec3_02159bbc*, Vec3_02159bbc*);
extern "C" int fix32_Divide(unsigned int, unsigned int);
extern "C" void func_02030e2c(Vec3_02159bbc*, int, Vec3_02159bbc*);

struct Triple02159b94 { int c, d, e; };
int ForwardTriple_02159b94(int a, int b, struct Triple02159b94 t);

struct A02159bbc { int pad0; Vec3_02159bbc pos; int scale; };
struct B02159bbc { char pad0[0x5c]; int counter; char pad1[0x70 - 0x60]; int fwdVal; char pad2[0x108 - 0x74]; Vec3_02159bbc outVec; };

// USA: func_ov001_02159bbc  (semantic: UpdateOffsetFromScale_02159bbc)
extern "C" ARM int func_ov001_02159bbc(struct A02159bbc* a, struct B02159bbc* b) {
    void* battle = _Z15GetBattleStructv();
    unsigned int scaledCount = _Z19GetBattleScaleCountP12BattleStruct(battle) << 12;
    int counter = b->counter;
    if (counter >= a->scale * 2) {
        b->counter = 0;
        return 0;
    }
    if (counter <= 0) {
        Vec3_02159bbc delta2;
        Vec3_02159bbc delta1;
        func_ov001_02164808(data_ov001_02165884, b->fwdVal, &delta1);
        int scaleShifted = a->scale << 12;
        Vector3fix_Subtract(&a->pos, &delta1, &delta2);
        b->outVec.x = fix32_Divide(delta2.x, scaleShifted);
        b->outVec.y = fix32_Divide(delta2.y, scaleShifted);
        b->outVec.z = fix32_Divide(delta2.z, scaleShifted);
    } else {
        Vec3_02159bbc tmp = b->outVec;
        int divScale = fix32_Divide(scaledCount, 0x2000);
        func_02030e2c(&tmp, divScale, &tmp);
        Vec3_02159bbc sum;
        func_ov001_02164808(data_ov001_02165884, b->fwdVal, &sum);
        Vector3fix_Add(&sum, &tmp, &sum);
        struct Triple02159b94 t = *(struct Triple02159b94*)&sum;
        ForwardTriple_02159b94(data_ov001_02165884, b->fwdVal, t);
    }
    b->counter += _Z19GetBattleScaleCountP12BattleStruct(battle);
    return 1;
}
