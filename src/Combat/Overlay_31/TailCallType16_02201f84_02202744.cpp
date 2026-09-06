#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void* func_ov031_02201e0c(int a, int b);
ARM int TailCallType16_02201f84(int a, int b);
ARM int TailCallType17_02201f98(int a, int b);
extern "C" int func_ov031_02201fac(int, int, int, int);

struct ContextEntry02202744 {
	ProcessorContext* field0;
	int field4;
	unsigned char field8;
	unsigned char pad[0x24 - 0x9];
	int field24;
};

// USA: func_ov031_02202744
extern "C" ARM void func_ov031_02202744(int a, int b, int c) {
	ContextEntry02202744* node = (ContextEntry02202744*)func_ov031_02201e0c(a, b);
	if (!node) return;
	switch (node->field8) {
	case 7:
		node->field24++;
		TailCallType16_02201f84((int)node, 0);
		node->field8 = 9;
		return;
	case 8:
		node->field24++;
		TailCallType16_02201f84((int)node, 0);
		node->field8 = 0;
		if (node->field4 != 2) return;
		node->field4 = 0;
		MarkContextReadyAndSwitch(node->field0);
		return;
	case 4:
		node->field24++;
		TailCallType17_02201f98((int)node, 0);
		node->field8 = 6;
		return;
	default:
		func_ov031_02201fac(a, b, c, 0);
		return;
	}
}
