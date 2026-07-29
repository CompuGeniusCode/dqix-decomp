#include <globaldefs.h>

extern "C" void func_020c1d60(void* a, void* b, void* c);
extern "C" void func_020c19d4(void* a, void* b);
void ScaleMatrixAndCopyTranslation020c1948(int* src, int* dst, int scaleX, int scaleY, int scaleZ);

extern int data_0210a0cc;
extern int data_0210a05c;
extern int data_0210a140[];
extern int data_0210a010[];
extern int data_0210a170;

// USA: func_020b3994  (semantic: SetupAndScaleMatrix_020b3994)
extern "C" ARM void func_020b3994(void) {
    func_020c1d60(&data_0210a0cc, &data_0210a05c, data_0210a140);
    ScaleMatrixAndCopyTranslation020c1948(data_0210a140, data_0210a140, data_0210a010[0x3b], data_0210a010[0x3c], data_0210a010[0x3d]);
    func_020c19d4(data_0210a140, &data_0210a170);
}
