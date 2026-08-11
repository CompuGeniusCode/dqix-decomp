#include <globaldefs.h>
#include "System/Interrupts.h"

extern "C" int func_ov027_021d9de8(unsigned int index);
extern "C" void VectorizedInvertedMemcpy(const void* src, void* dst, unsigned int len);

extern char* data_ov027_021e33ec;

// USA: func_ov027_021d8a68  (semantic: PrepareSlotEntry_021d8a68)
extern "C" ARM void* func_ov027_021d8a68(int index) {
    int irq = DisableIRQInterrupts();
    if (data_ov027_021e33ec == 0) goto fail;
    if (!func_ov027_021d9de8(index)) goto fail;
    VectorizedInvertedMemcpy(data_ov027_021e33ec + 0x1340 + (index - 1) * 0x16, data_ov027_021e33ec + 0x1772, 0x16);
    SetIRQInterruptState(irq);
    return data_ov027_021e33ec + 0x1772;
fail:
    SetIRQInterruptState(irq);
    return 0;
}
