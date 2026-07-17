#include <globaldefs.h>

extern "C" void func_ov017_021acd7c(void* p);
extern "C" void _Z19InsertNodeAfterHeadP12List02046a3cP12Node02046a3c(void* list, void* node);

// USA: func_ov017_021acd30
ARM void InitAndInsertNode_021acd30(char* self, unsigned char a, unsigned char b, unsigned char c) {
	func_ov017_021acd7c(*(void**)(self + 0x3000 + 0xb20));
	((unsigned char*)(*(void**)(self + 0x3000 + 0xb20)))[0x27c] = a;
	((unsigned char*)(*(void**)(self + 0x3000 + 0xb20)))[0x27d] = b;
	((unsigned char*)(*(void**)(self + 0x3000 + 0xb20)))[0x27e] = c;
	void* list = *(void**)(self + 0x3000 + 0x6fc);
	_Z19InsertNodeAfterHeadP12List02046a3cP12Node02046a3c(list, *(void**)(self + 0x3000 + 0xb20));
}
