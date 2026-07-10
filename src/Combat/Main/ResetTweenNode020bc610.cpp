#include <globaldefs.h>

struct Tween020c01ec { int f0; int f4; int f8; int fc; };
struct Tween020c0260 { int f0; int f4; int f8; int fc; };

void ResetTween020c01ec(struct Tween020c01ec* t);
void RetargetTween020c0204(struct Tween020c0260* t, int end, int duration);

struct Obj020bc610 {
    unsigned char pad00[0x1c];   /* 0x00 */
    Tween020c01ec tween;         /* 0x1c */
    unsigned char pad2c;         /* 0x2c */
    unsigned char f2d;           /* 0x2d */
    unsigned char f2e;           /* 0x2e */
    unsigned char f2f;           /* 0x2f */
    unsigned char pad30[4];      /* 0x30 */
    unsigned short f34;          /* 0x34 */
    unsigned char pad36[8];      /* 0x36 */
    unsigned short f3e;          /* 0x3e */
    unsigned char f40;           /* 0x40 */
    unsigned char f41;           /* 0x41 */
};

// USA: func_020bc610
ARM void ResetTweenNode020bc610(struct Obj020bc610* obj) {
    obj->f2e = 0;
    obj->f2d = 0;
    obj->f2f = 0;
    obj->f34 = 0;
    obj->f3e = 0;
    obj->f40 = 0x7f;
    obj->f41 = 0x7f;
    ResetTween020c01ec(&obj->tween);
    RetargetTween020c0204((struct Tween020c0260*)&obj->tween, 0x7f00, 1);
}
