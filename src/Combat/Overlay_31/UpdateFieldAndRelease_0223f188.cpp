#include <globaldefs.h>

extern int data_ov031_02290dc4;
extern int data_ov031_02290dbc;
void* CallField8074_0223fa0c(void);
void ReleaseData02290fa4_0223fa20(void);
struct Obj02240df4;
void CleanupAndNotify_0223edb4(void* p0, struct Obj02240df4* p1);
extern "C" int func_ov031_02240ee8(struct Obj02240df4* p1);

struct Container0223f188 { int field0; };

// USA: func_ov031_0223f188  (semantic: UpdateFieldAndRelease_0223f188)
extern "C" ARM int func_ov031_0223f188(Container0223f188* p0, struct Obj02240df4* p1) {
    CallField8074_0223fa0c();
    int r = func_ov031_02240ee8(p1);
    p0->field0 = r;
    data_ov031_02290dc4 = r;
    ReleaseData02290fa4_0223fa20();
    if (p0->field0 >= 0) {
        return 1;
    }
    CleanupAndNotify_0223edb4(p0, p1);
    data_ov031_02290dbc = 3;
    return 0;
}
