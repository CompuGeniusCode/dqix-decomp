#include <globaldefs.h>

#pragma optimize_for_size off

extern "C" void func_020b6acc(unsigned int command, const int* params, unsigned int numParams);

// Geometry-engine matrix commands used below.
#define G3_CMD_MTX_MULT_4x3 0x19
#define G3_CMD_MTX_MULT_3x3 0x1a
#define G3_CMD_MTX_SCALE 0x1b
#define G3_CMD_MTX_TRANS 0x1c

struct SrtNode_020ba264 {
    unsigned int flags;   // 0x00
    int scale[3];         // 0x04
    int invScale[3];      // 0x10
    int pivotScale[3];    // 0x1c
    int rot[9];           // 0x28
    int trans[3];         // 0x4c
};

// USA: func_020ba264
extern "C" ARM void func_020ba264(SrtNode_020ba264* node) {
    int scaledTrans[3];
    int transDeferred = 0;
    unsigned int scaleFlags = node->flags & 0x18;

    if (scaleFlags == 0) {
        func_020b6acc(G3_CMD_MTX_SCALE, node->pivotScale, 3);
    }
    if (!(node->flags & 4)) {
        if (scaleFlags != 0) {
            transDeferred = 1;
        } else {
            scaledTrans[0] = (int)(((long long)node->trans[0] * node->invScale[0]) >> 12);
            scaledTrans[1] = (int)(((long long)node->trans[1] * node->invScale[1]) >> 12);
            scaledTrans[2] = (int)(((long long)node->trans[2] * node->invScale[2]) >> 12);
            func_020b6acc(G3_CMD_MTX_TRANS, scaledTrans, 3);
        }
    }
    if (!(node->flags & 2)) {
        if (transDeferred) {
            func_020b6acc(G3_CMD_MTX_MULT_4x3, node->rot, 12);
        } else {
            func_020b6acc(G3_CMD_MTX_MULT_3x3, node->rot, 9);
        }
    } else if (transDeferred) {
        func_020b6acc(G3_CMD_MTX_TRANS, node->trans, 3);
    }
    if (scaleFlags == 0) {
        func_020b6acc(G3_CMD_MTX_SCALE, node->invScale, 3);
    }
    if (node->flags & 1) {
        return;
    }
    func_020b6acc(G3_CMD_MTX_SCALE, node->scale, 3);
}
