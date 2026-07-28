#include <globaldefs.h>

void* AcquireData022918a4_02240310(void);
ARM int TailCallWith2_02241518(int a, int b);
ARM void ProcessAllNodesField8_022402b0(void);
ARM void ReleaseAllocatorRef_02240324(void);

struct Inner02240f74 { unsigned char pad[4]; int field4; };
struct Struct02240f74 { unsigned char pad[0xc]; Inner02240f74* volatile fieldC; int field10; };
extern Struct02240f74* data_ov031_02290fcc;

// USA: func_ov031_02240f74
ARM void AcquireAndProcessAllocatorState_02240f74(void) {
    AcquireData022918a4_02240310();
    if (data_ov031_02290fcc != 0) {
        if (data_ov031_02290fcc->fieldC->field4 == 0) {
            *(int*)((char*)data_ov031_02290fcc->fieldC + 4) = 1;
            TailCallWith2_02241518((int)data_ov031_02290fcc->fieldC, data_ov031_02290fcc->field10);
        }
    }
    ProcessAllNodesField8_022402b0();
    ReleaseAllocatorRef_02240324();
}
