#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Memory.h"

struct MemRegionEntry_021dd180 {
    unsigned int base;
    unsigned int size;
    void* mapped;
    unsigned int type;
};

struct MemRegionTable_021dd180 {
    int status;
    unsigned char unk4[0x2c];
    MemRegionEntry_021dd180 regions[4];
};

// USA: func_ov027_021dd180  (semantic: ReadFromMappedRegion_021dd180)
extern "C" ARM int func_ov027_021dd180(MemRegionTable_021dd180* table, unsigned int addr, void* dst, unsigned int len) {
    MemRegionEntry_021dd180* end;
    MemRegionEntry_021dd180* region;
    int result = 0;
    int irqState = DisableIRQInterrupts();

    region = table->regions;
    end = table->regions + 4;
    if (region < end) {
        do {
            if (region->type >= 2) {
                int offset = addr - region->base;
                if (offset >= 0 && offset + len <= region->size) {
                    VectorizedInvertedMemcpy((char*)region->mapped + offset, dst, len);
                    table->status = 0;
                    result = 1;
                    break;
                }
            }
            region++;
        } while (region < end);
    }

    SetIRQInterruptState(irqState);
    return result;
}
