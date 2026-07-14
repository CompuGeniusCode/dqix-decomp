#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);
extern "C" void func_020c7764(void);
unsigned int IncrementCounterIfNotMax020c7c40(void);
void DrainNodeList020c8154(void* owner);
void* ResumeThreadIfPresent(void* obj);

struct List020c7268;
struct Node020c7268;
Node020c7268* RemoveFromList020c7268(List020c7268* list, Node020c7268* target);

struct Node020c734c;
void RemoveFromList021112e0(Node020c734c* obj);

struct List020c7234;
void ClearAndFreeAllNodes020c78e8(List020c7234* list);

unsigned int DecrementCounterIfNonzero020c7c74(void);
void RunWithInterruptsDisabled020c79a0(void);

extern char data_021112e0;

// USA: func_020c77c0
ARM void TeardownBattleContext020c77c0(void* obj) {
    unsigned int mask = DisableInterrupts();
    if (*(void**)(&data_021112e0 + 0x28) == obj) {
        func_020c7764();
    }
    IncrementCounterIfNotMax020c7c40();
    DrainNodeList020c8154(obj);
    ResumeThreadIfPresent(obj);
    void* list78 = *(void**)((char*)obj + 0x78);
    if (list78 != NULL) {
        RemoveFromList020c7268((List020c7268*)list78, (Node020c7268*)obj);
    }
    RemoveFromList021112e0((Node020c734c*)obj);
    *(unsigned int*)((char*)obj + 0x64) = 2;
    ClearAndFreeAllNodes020c78e8((List020c7234*)((char*)obj + 0x9c));
    DecrementCounterIfNonzero020c7c74();
    RestoreInterrupts(mask);
    RunWithInterruptsDisabled020c79a0();
}
