#include <globaldefs.h>

extern "C" void* func_020d2404(int);
struct MsgNode020d248c;
extern "C" int func_020d248c(MsgNode020d248c*);

struct BattleEventNode020d217c {
    int field0;
    int type;
    int arg1;
    int arg2;
    int arg3;
    int arg4;
};

// Fills a command node - next pointer, type, four arguments - and appends it to the pending list in
// data_02112780 with interrupts masked. That list is what reaches the ARM7: func_020d24c4 loads it
// and calls SendCommandToArm7 twice. The only callers are the twenty typed wrappers between
// 0x020d1de8 and 0x020d2154, each supplying a fixed type byte. Nodes come off a 256-entry free list
// through func_020d2404, which hands one back immediately when the ready list has any and only then
// blocks in func_020d2880 until the ARM7 answers IPC command 7.
extern "C" ARM int QueueArm7Command(int type, int arg1, int arg2, int arg3, int arg4) {
    struct BattleEventNode020d217c* node = (struct BattleEventNode020d217c*)func_020d2404(1);
    if (node == NULL) return (int)node;
    node->type = type;
    node->arg1 = arg1;
    node->arg2 = arg2;
    node->arg3 = arg3;
    node->arg4 = arg4;
    return func_020d248c((MsgNode020d248c*)node);
}
