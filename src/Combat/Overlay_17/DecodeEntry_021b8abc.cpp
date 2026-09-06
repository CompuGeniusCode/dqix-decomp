#include <globaldefs.h>

int TryDecodeGlobalBitstreamEntry(void* buf, int id);

struct DecodeBuf021b8abc {
    unsigned char pad0[2];
    unsigned short vals[3];
    unsigned short bytesSrc[3];
    unsigned char pad1[6];
};

struct Out021b8abc {
    short vals[3];
    unsigned char pad[2];
    unsigned char bytes[3];
};

// USA: func_ov017_021b8abc
ARM int DecodeEntry_021b8abc(int id, Out021b8abc* out) {
    DecodeBuf021b8abc buf;
    if (id <= -1) {
        goto fail;
    }
    if (!TryDecodeGlobalBitstreamEntry(&buf, id)) {
        goto fail;
    }
    for (int i = 0; i < 3; i++) {
        out->vals[i] = buf.vals[i];
        out->bytes[i] = (unsigned char)buf.bytesSrc[i];
    }
    return 1;
fail:
    return 0;
}
