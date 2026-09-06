#include <globaldefs.h>

struct BlockedContextList;
void UnblockContexts(struct BlockedContextList*);

extern "C" ARM void func_ov031_02206b68(void*);
unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);

struct Node02207108;
struct Node02207168;
ARM void* RemoveFromGlobal0224e22c_02207108(Node02207108* item);
ARM void* RemoveFromList0224e230(Node02207168* item);

struct ListNode02206a68 { ListNode02206a68* next; };
struct VTable022496a4 { char pad[0x1c]; void (*field1c)(ListNode02206a68*); };
extern VTable022496a4* data_ov031_022496a4;

struct SubStruct02206a68 {
	char pad[0x100];
	int field100;
	ListNode02206a68* field104;
	unsigned short field108;
};

struct Ctx02206a68 {
	char pad[0x64];
	SubStruct02206a68* field64;
	void* field68;
	char pad2[4];
	unsigned short field70;
	char pad3;
	signed char field73;
};

// USA: func_ov031_02206a68  (semantic: ShutdownAndUnblock_02206a68)
extern "C" ARM void func_ov031_02206a68(Ctx02206a68* a) {
	if (a == NULL) return;
	a->field70 = 0;
	int isTerminal = 1;
	signed char kind = a->field73;
	if (kind != 0 && kind != 4) isTerminal = 0;
	if (isTerminal) {
		func_ov031_02206b68(a->field68);
		func_ov031_02206b68(a->field64);
	} else if (kind == 1) {
		if (a->field64->field104 != NULL) {
			ListNode02206a68* node = a->field64->field104;
			do {
				ListNode02206a68* next = node->next;
				data_ov031_022496a4->field1c(node);
				node = next;
			} while (node != NULL);
		}
		a->field64->field108 = 0;
		a->field64->field100 = 0;
		a->field64->field104 = NULL;
		UnblockContexts((struct BlockedContextList*)((char*)a->field64 + 0x10c));
		func_ov031_02206b68(a->field64);
	} else if (kind == 2) {
		func_ov031_02206b68(a->field68);
	}

	unsigned int prev = DisableIRQInterrupts();
	RemoveFromGlobal0224e22c_02207108((Node02207108*)a);
	RemoveFromList0224e230((Node02207168*)a);
	data_ov031_022496a4->field1c((ListNode02206a68*)a);
	SetIRQInterruptState(prev);
}
