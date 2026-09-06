#include <globaldefs.h>

void VerifyDMATimingChangePermitted_020c9fd0(int a, unsigned int b);
void VerifyDMASource(int channel, unsigned int source, unsigned int length, unsigned int sourceCtrlFlags);
void ConfigureDMATransferAtomic(int channel, unsigned int src, unsigned int dst, unsigned int ctrl);

// USA: _Z25StartDmaWithFlush020ca8e8jjjj
ARM void StartDmaWithFlush020ca8e8(unsigned int chan, unsigned int addr, unsigned int len, unsigned int size) {
    VerifyDMATimingChangePermitted_020c9fd0(chan, -1);
    VerifyDMASource(chan, addr, size, 0x1000000);
    if (size == 0) return;
    volatile unsigned int* dmaCnt = (volatile unsigned int*)(0x040000b0 + (chan * 3 + 2) * 4);
    while (*dmaCnt & 0x80000000) {}
    ConfigureDMATransferAtomic(chan, addr, len, 0xaf000001);
}
