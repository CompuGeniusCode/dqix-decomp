#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* obj);
unsigned short GetGlobalHalf0x2(void);
unsigned short GetGlobalU16At0x12(void);

struct BgCntRegs_04000008 {
    volatile unsigned short bg0;
    volatile unsigned short bg1;
    volatile unsigned short bg2;
    volatile unsigned short bg3;
};

struct BgCntSnap_02165cb8 {
    char pad[0x98];
    volatile unsigned short bg0;
    volatile unsigned short bg1;
    volatile unsigned short bg2;
    volatile unsigned short bg3;
    char pad2[8];
    volatile unsigned short bg0Sub;
    volatile unsigned short bg1Sub;
    volatile unsigned short bg2Sub;
    volatile unsigned short bg3Sub;
};
extern struct BgCntSnap_02165cb8 data_ov001_02165cb8;

struct GlobalSnap_021658b8 {
    char pad[0x494];
    int half0x2;
    char pad2[8];
    int dispA;
    int u16At0x12;
    char pad3[8];
    int dispB;
};
extern struct GlobalSnap_021658b8 data_ov001_021658b8;

// USA: func_ov001_0216297c  (semantic: SnapshotBgControlByOv17Result_0216297c)
extern "C" ARM int func_ov001_0216297c(void* obj) {
    int r = func_ov017_021d60f4(obj);
    if (r == 0) {
        data_ov001_021658b8.half0x2 = GetGlobalHalf0x2();
        struct BgCntRegs_04000008* reg = (struct BgCntRegs_04000008*)0x04000008;
        struct BgCntSnap_02165cb8* dst = &data_ov001_02165cb8;
        volatile short v0, v1, v2, v3;
        {
            unsigned short raw = reg->bg0;
            v0 = raw; v0;
            dst->bg0 = raw; v0;
        }
        {
            unsigned short raw = reg->bg1;
            dst->bg1 = raw;
            v1 = raw; v1;
        }
        {
            unsigned short raw = reg->bg2;
            v2 = raw; v2;
            dst->bg2 = raw; v2;
        }
        {
            unsigned short raw = reg->bg3;
            v3 = raw;
            dst->bg3 = raw;
            v3;
        }
        data_ov001_021658b8.dispA = (*(volatile unsigned int*)0x04000000 & 0x1f00) >> 8;
    } else if (r == 1) {
        data_ov001_021658b8.u16At0x12 = GetGlobalU16At0x12();
        struct BgCntRegs_04000008* reg = (struct BgCntRegs_04000008*)0x04001008;
        struct BgCntSnap_02165cb8* dst = &data_ov001_02165cb8;
        volatile short v0, v1, v2, v3;
        {
            unsigned short raw = reg->bg0;
            v0 = raw;
            dst->bg0Sub = raw;
            v0;
        }
        {
            unsigned short raw = reg->bg1;
            dst->bg1Sub = raw;
            v1 = raw; v1;
        }
        {
            unsigned short raw = reg->bg2;
            v2 = raw; v2;
            dst->bg2Sub = raw; v2;
        }
        {
            unsigned short raw = reg->bg3;
            v3 = raw;
            dst->bg3Sub = raw;
            v3;
        }
        data_ov001_021658b8.dispB = (*(volatile unsigned int*)0x04001000 & 0x1f00) >> 8;
    }
    return 1;
}
