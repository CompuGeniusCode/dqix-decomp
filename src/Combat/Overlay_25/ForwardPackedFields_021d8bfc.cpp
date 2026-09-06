#include <globaldefs.h>

struct PackedFields_021d8bfc {
    unsigned int w0;
    unsigned int w1;
    unsigned int w2;
    unsigned int w3;
    unsigned int w4;
    unsigned char b5;
};

extern "C" void func_ov025_021d8c30(void* a, unsigned int w0, unsigned int w1, unsigned int w2,
                                     unsigned int w3, unsigned int w4, unsigned int b5);

// USA: func_ov025_021d8bfc
ARM void ForwardPackedFields_021d8bfc(void* a, struct PackedFields_021d8bfc* b) {
    func_ov025_021d8c30(a, b->w0, b->w1, b->w2, b->w3, b->w4, b->b5);
}
