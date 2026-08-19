#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Memory.h"

int IsFieldqual1_021dd0ac_021dd0ac(void);
extern "C" int func_ov027_021da808(void* out, void* rawElems);
extern "C" void func_ov027_021dab84(void* obj, void* src, int extra);
void CopyFields_021da61c(void* dst, void* src);
struct ListNode021dadac;
void EnqueueNode_021dadac(ListNode021dadac* node);
extern "C" int func_ov027_021dd3b0(void);
extern "C" void func_ov027_021dd3cc(void* p);
void InitContextIfFree_021dd330(void* ctxRaw, unsigned int size);

extern unsigned char* data_ov027_021e33ec;
extern unsigned char data_ov027_021dd924;

// USA: func_ov027_021da38c  (semantic: RegisterCombatSlot_021da38c)
extern "C" ARM int func_ov027_021da38c(void* desc, void* arg1) {
    unsigned char freeIdx = 0xff;
    int irq = DisableIRQInterrupts();
    if (!IsFieldqual1_021dd0ac_021dd0ac()) {
        SetIRQInterruptState(irq);
        return 0;
    }

    unsigned char cnt0 = data_ov027_021e33ec[0x1524];
    if (cnt0 + 1 > 0x10) {
        SetIRQInterruptState(irq);
        return 0;
    }

    unsigned char i = 0;
    do {
        unsigned char* slot = data_ov027_021e33ec + i * 0x5d4;
        slot = slot + 0x1000;
        if (*(int*)(slot + 0xd40) == (int)desc) {
            SetIRQInterruptState(irq);
            return 0;
        }
        if (slot[0xd52] == 0) {
            freeIdx = i;
            break;
        }
        i++;
    } while (i < 0x10);
    if (i == 0x10) {
        SetIRQInterruptState(irq);
        return 0;
    }

    int off = freeIdx * 0x5d4;
    *(int*)(data_ov027_021e33ec + off + 0x1000 + 0xd40) = (int)desc;

    unsigned char* sub = data_ov027_021e33ec + 0x1788 + off;
    CopyFields_021da61c(sub, arg1);
    VectorizedInvertedMemcpy((char*)desc + 0x1c, sub + 0xc4, 0x20);

    if (!func_ov027_021da808(data_ov027_021e33ec + 0x1d2c + off, sub)) {
        SetIRQInterruptState(irq);
        return 0;
    }

    func_ov027_021dab84(data_ov027_021e33ec + 0x186c + off, desc, (int)(data_ov027_021e33ec + 0x1300));

    (data_ov027_021e33ec + off + 0x1000)[0xd21] = freeIdx;

    EnqueueNode_021dadac((ListNode021dadac*)(data_ov027_021e33ec + 0x186c + off));

    unsigned char cntOld = data_ov027_021dd924;
    unsigned char newCnt = cntOld + 1;
    char* p1e8 = (char*)arg1 + 0x1e8;
    char* p258 = (char*)arg1 + 0x258;
    (data_ov027_021e33ec + off + 0x1000)[0xd1f] = cntOld;
    *(unsigned short*)(data_ov027_021e33ec + off + 0x1d00 + 0x4e) = 1;

    *(void**)(data_ov027_021e33ec + off + 0x1000 + 0xd44) = arg1;
    *(char**)(data_ov027_021e33ec + off + 0x1000 + 0xd54) = p1e8;
    *(char**)(data_ov027_021e33ec + off + 0x1000 + 0xd58) = p258;
    data_ov027_021dd924 = newCnt;

    char* p = *(char**)(data_ov027_021e33ec + off + 0x1000 + 0xd54);
    if (*(int*)(p + 0x6c) != 0) {
        if (!func_ov027_021dd3b0()) {
            func_ov027_021dd3cc(data_ov027_021e33ec + 0x7ce0);
            InitContextIfFree_021dd330(data_ov027_021e33ec + 0x74e0, 0x800);
        }
    }

    (data_ov027_021e33ec + off + 0x1000)[0xd52] = 1;
    data_ov027_021e33ec[0x1524]++;

    SetIRQInterruptState(irq);
    return 1;
}
