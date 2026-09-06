#include <globaldefs.h>

extern "C" void* func_ov031_022401b8(void* target);
extern "C" int func_ov031_02240e70(void* obj);
extern "C" void (* volatile data_ov031_02290fc8)(void*);

struct ListNode02240210 {
	ListNode02240210* prev;
	ListNode02240210* next;
	int field8;
	void* fieldC;
	int field10;
};
extern ListNode02240210* data_ov031_02290fdc;

struct FreeableObj02240210 {
	char pad[0x2c];
	int field2c;
	int field30;
	char pad2[8];
	int (*field3c)(int, int, int);
};

// USA: func_ov031_02240210
extern "C" ARM int RemoveNodeAndDispatch_02240210(void* target) {
	int result = 0;
	ListNode02240210* node = (ListNode02240210*)func_ov031_022401b8(target);
	if (node != 0) {
		ListNode02240210* head = data_ov031_02290fdc;
		if (head != head->prev) {
			node->prev->next = node->next;
			node->next->prev = node->prev;
			if (data_ov031_02290fdc == node) {
				data_ov031_02290fdc = node->next;
			}
		} else {
			data_ov031_02290fdc = 0;
		}

		FreeableObj02240210* obj = (FreeableObj02240210*)node->fieldC;
		int (*cb)(int, int, int) = obj->field3c;
		int a30 = obj->field30;
		int a2c = obj->field2c;
		func_ov031_02240e70(obj);
		data_ov031_02290fc8(node);
		cb(8, a30, a2c);
		result = 1;
	}
	return result;
}
