#include <globaldefs.h>

extern "C" void* func_020d2404(int);
struct Arm7CommandNode;
extern "C" int func_020d248c(Arm7CommandNode*);

struct Arm7CommandNode {
    int next;
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
// blocks in func_020d2880 until the ARM7 answers IPC command 7. The link is the word at +0:
// func_020d248c clears it and hangs the node off the old tail, taking the pending list's head and
// tail from data_02112780+0x8 and +0xc; the ready list func_020d2404 pops from is a separate list
// at +0 of the same block. The four arguments mean whatever the type says they mean --
// func_020d1f0c forwards its own four unchanged under type 0xd -- so there is no one meaning to
// name them by.
extern "C" ARM int QueueArm7Command(int type, int arg1, int arg2, int arg3, int arg4) {
    struct Arm7CommandNode* command = (struct Arm7CommandNode*)func_020d2404(1);
    if (command == NULL) return (int)command;
    command->type = type;
    command->arg1 = arg1;
    command->arg2 = arg2;
    command->arg3 = arg3;
    command->arg4 = arg4;
    return func_020d248c((Arm7CommandNode*)command);
}
