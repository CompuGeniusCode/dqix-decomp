#include <globaldefs.h>

void InitFourWordsAndCallbacksOnce(void);
void ResetQueueAndNotify(void);
void CallFunc020bd08c_020bbe10(void);
void ResetFlagPool(void);
void Reset0210fd74State(void);
void InitAllocatorPools020bc23c(void);

struct NodeCEE54 { char _pad[8]; struct NodeCEE54* next; };
void PrependToGlobalList02111804(struct NodeCEE54* node);

struct NodeCEE68 { char _pad[8]; struct NodeCEE68* next; };
void AppendToGlobalList02111800(struct NodeCEE68* node);

extern struct NodeCEE54 data_0210cfd0;
extern struct NodeCEE68 data_0210cfdc;

struct Struct0210cfc0 {
    char byte0; // +0x0
    char pad1[3];
    int field4; // +0x4
    char pad2[0xc - 8];
    int guard; // +0xc
    void (*field10)(void); // +0x10
    int field14;           // +0x14
    char pad3[0x1c - 0x18];
    void (*field1c)(void); // +0x1c
    int field20;            // +0x20
};
extern struct Struct0210cfc0 data_0210cfc0;

// USA: func_020bbd14
ARM void InitGlobalSystemsOnce020bbd14(void) {
    if (data_0210cfc0.guard != 0) return;
    data_0210cfc0.guard = 1;
    InitFourWordsAndCallbacksOnce();
    data_0210cfc0.field10 = ResetQueueAndNotify;
    data_0210cfc0.field14 = 0;
    data_0210cfc0.field1c = CallFunc020bd08c_020bbe10;
    data_0210cfc0.field20 = 0;
    PrependToGlobalList02111804(&data_0210cfd0);
    AppendToGlobalList02111800(&data_0210cfdc);
    ResetFlagPool();
    Reset0210fd74State();
    InitAllocatorPools020bc23c();
    data_0210cfc0.byte0 = -1;
    data_0210cfc0.field4 = 1;
}
