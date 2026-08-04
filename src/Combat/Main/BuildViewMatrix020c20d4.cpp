#include <globaldefs.h>

struct FixedVec3 { int x; int y; int z; };
struct ViewMatrix020c20d4 { int m[3][3]; int t[3]; };

void CrossProductFixed020c2e34(int* a, int* b, int* out);
extern "C" void func_020c2f18(struct FixedVec3* out, struct FixedVec3* in);
int DotFixedVec3(struct FixedVec3* a, struct FixedVec3* b);

// USA: func_020c20d4  (semantic: BuildViewMatrix020c20d4)
extern "C" ARM void func_020c20d4(struct FixedVec3* eye, struct FixedVec3* up, struct FixedVec3* target, struct ViewMatrix020c20d4* out) {
    struct FixedVec3 forward;
    forward.x = eye->x - target->x;
    forward.y = eye->y - target->y;
    forward.z = eye->z - target->z;
    func_020c2f18(&forward, &forward);

    struct FixedVec3 right;
    CrossProductFixed020c2e34((int*)up, (int*)&forward, (int*)&right);
    func_020c2f18(&right, &right);

    struct FixedVec3 upAxis;
    CrossProductFixed020c2e34((int*)&forward, (int*)&right, (int*)&upAxis);

    out->m[0][0] = right.x;
    out->m[0][1] = upAxis.x;
    out->m[0][2] = forward.x;
    out->m[1][0] = right.y;
    out->m[1][1] = upAxis.y;
    out->m[1][2] = forward.y;
    out->m[2][0] = right.z;
    out->m[2][1] = upAxis.z;
    out->m[2][2] = forward.z;

    out->t[0] = -DotFixedVec3(eye, &right);
    out->t[1] = -DotFixedVec3(eye, &upAxis);
    out->t[2] = -DotFixedVec3(eye, &forward);
}
