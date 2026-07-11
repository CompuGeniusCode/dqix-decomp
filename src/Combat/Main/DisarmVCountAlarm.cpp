#include <globaldefs.h>

ARM unsigned int DisableInterrupts();
ARM unsigned int RestoreInterrupts(unsigned int mask);
struct VCountAlarmNode;
ARM void UnlinkVCountAlarmNode(struct VCountAlarmNode* node);

struct AlarmCtx020c949c {
    unsigned int linked;
    char _pad[0x20];
    unsigned int flag24;
};

// USA: func_020c949c
ARM void DisarmVCountAlarm(struct AlarmCtx020c949c* node) {
    unsigned int oldIntr = DisableInterrupts();
    node->flag24 = 1;
    if (node->linked == 0) {
        RestoreInterrupts(oldIntr);
        return;
    }
    UnlinkVCountAlarmNode((struct VCountAlarmNode*)node);
    node->linked = 0;
    RestoreInterrupts(oldIntr);
}
