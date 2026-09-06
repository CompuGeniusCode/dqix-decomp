#include <globaldefs.h>

struct EventMsg_0220d9c8 {
	short a;
	short b;
	int c;
	int d;
	int e;
};
typedef void (*EventHandler_0220d9c8)(EventMsg_0220d9c8*);

extern void* data_ov031_0224e53c;

// USA: func_ov031_0220d9c8
#pragma optimize_for_size off
ARM void DispatchEvent_0220d9c8(short a, short b, int c, int d, int e) {
	char* base = (char*)data_ov031_0224e53c;
	if (*(EventHandler_0220d9c8*)(base + 0x227c) == 0) return;
	EventMsg_0220d9c8 msg;
	msg.a = a;
	msg.b = b;
	msg.c = c;
	msg.d = d;
	msg.e = e;
	(*(EventHandler_0220d9c8*)(base + 0x227c))(&msg);
}
