#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/ProcessorContext.h"

struct QueueNode021dd3f8 {
	QueueNode021dd3f8* next;
	union {
		unsigned int flags;
		struct {
			unsigned int active : 1;
			unsigned int priority : 31;
		};
	};
	unsigned int f8;
	unsigned int fc;
};

struct RootStruct021dd3f8 { void* field0; };
extern RootStruct021dd3f8 data_ov027_021e3420;

extern "C" int func_ov027_021dd3b0(void);

// USA: func_ov027_021dd3f8
extern "C" ARM void func_ov027_021dd3f8(void* a0, unsigned int a1, unsigned int a2, unsigned int a3) {
	QueueNode021dd3f8* node = (QueueNode021dd3f8*)a0;
	ProcessorContext* ctx = (ProcessorContext*)data_ov027_021e3420.field0;
	if (!func_ov027_021dd3b0()) return;
	if (node->active) return;

	unsigned int pri = a3;
	if (pri > 0x1f) {
		unsigned int activePri = GetContextPriority(ctx);
		if (pri == 0x20) {
			pri = (activePri != 0) ? (activePri - 1) : 0;
		} else if (pri == 0x21) {
			pri = (activePri < 0x1f) ? (activePri + 1) : 0x1f;
		} else if (pri == 0x22) {
			pri = activePri;
		} else {
			pri = 0x1f;
		}
	}

	int state = DisableIRQInterrupts();
	node->active = 1;
	node->priority = pri;
	node->f8 = a1;
	node->fc = a2;

	QueueNode021dd3f8** headSlot = (QueueNode021dd3f8**)((char*)ctx + 0xc0);
	QueueNode021dd3f8* head = *headSlot;
	if (head == 0) {
		if (node == (QueueNode021dd3f8*)((char*)ctx + 0xc4)) {
			data_ov027_021e3420.field0 = 0;
		}
		*headSlot = node;
		MarkContextReadyAndSwitch(ctx);
	} else {
		QueueNode021dd3f8* head2 = *(QueueNode021dd3f8* volatile*)headSlot;
		if (node == (QueueNode021dd3f8*)((char*)ctx + 0xc4)) {
			QueueNode021dd3f8* last = head2;
			QueueNode021dd3f8* nxt = last->next;
			if (nxt != 0) {
				do {
					last = nxt;
					nxt = last->next;
				} while (nxt != 0);
			}
			last->next = node;
			data_ov027_021e3420.field0 = 0;
		} else {
			if (pri < head2->priority) {
				*headSlot = node;
				node->next = head2;
			} else {
				QueueNode021dd3f8* prev = head2;
				QueueNode021dd3f8* cur;
				goto test_cur;
				do {
					prev = cur;
				test_cur:
					cur = prev->next;
				} while (cur != 0 && pri >= cur->priority);
				node->next = cur;
				prev->next = node;
			}
		}
	}
	SetIRQInterruptState(state);
}
