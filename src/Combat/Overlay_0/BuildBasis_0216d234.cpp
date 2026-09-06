#include <globaldefs.h>

struct Vec3Ints0216d234 { int x; int y; int z; };
struct Basis0216d234 { Vec3Ints0216d234 right; Vec3Ints0216d234 up; Vec3Ints0216d234 forward; Vec3Ints0216d234 pos; };

extern "C" void Vector3fix_CrossProduct(int*, int*, int*);

// USA: func_ov000_0216d234  (semantic: BuildBasis_0216d234)
extern "C" ARM void func_ov000_0216d234(int* forward, int* position, struct Basis0216d234* dest) {
    int up[3];
    up[0] = 0;
    up[1] = 0x1000;
    up[2] = 0;
    int out[3];
    Vector3fix_CrossProduct(forward, up, out);
    dest->right.x = out[0];
    dest->right.y = out[1];
    dest->right.z = out[2];
    dest->up.x = up[0];
    dest->up.y = up[1];
    dest->up.z = up[2];
    dest->forward.x = forward[0];
    dest->forward.y = forward[1];
    dest->forward.z = forward[2];
    dest->pos.x = position[0];
    dest->pos.y = position[1];
    dest->pos.z = position[2];
}
