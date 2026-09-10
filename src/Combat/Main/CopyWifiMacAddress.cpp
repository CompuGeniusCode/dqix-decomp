#include <globaldefs.h>
#include "System/Memory.h"

// Copies the six bytes at 0x027FFCF4, the console's Wi-Fi MAC address in the ARM7/ARM9 shared
// block; the enabled-channel halfword sits right behind it at 0x027FFCFA, which
// func_020d4aa8 reads. Nine of the sixteen call sites are in ov031 (wifi), and
// the rest use it as a per-console identity: func_020120f0 packs bytes 2..5 into a seed for a
// Random built with the literal "CreateNativeID", and func_020d4b58 sums all six with
// 0x027FFC3C. Note the argument order -- VectorizedInvertedMemcpy takes source first, so this
// reads from the system block into the caller's buffer. That the six bytes are the MAC comes from
// the DS memory layout, not from anything proven in this tree.
extern "C" ARM void CopyWifiMacAddress(void* dst) {
    VectorizedInvertedMemcpy((const void*)0x27ffcf4, dst, 6);
}
