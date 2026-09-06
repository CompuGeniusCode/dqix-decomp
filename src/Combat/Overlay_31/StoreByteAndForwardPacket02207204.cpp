#include <globaldefs.h>
#pragma optimize_for_size off

struct Packet02207204;
extern int SwapField2AndForward02207204(void* obj, struct Packet02207204* pkt);

// USA: func_ov031_0221e5bc  (semantic: StoreByteAndForwardPacket02207204)
extern "C" THUMB int func_ov031_0221e5bc(void* obj, struct Packet02207204* pkt, unsigned char val) {
    *(unsigned char*)pkt = val;
    return SwapField2AndForward02207204(obj, pkt);
}
