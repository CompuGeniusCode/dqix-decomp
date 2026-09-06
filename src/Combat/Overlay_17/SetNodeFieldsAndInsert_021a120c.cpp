#include <globaldefs.h>

struct Node02046a3c;
struct List02046a3c;
void InsertNodeAfterHead(struct List02046a3c* list, struct Node02046a3c* node);
extern "C" void func_ov017_021a124c(void* obj);

struct Base021a120c { unsigned char pad[0x6fc]; struct List02046a3c* list; unsigned char pad2[8]; struct Node02046a3c* node; };
struct NodeFields021a120c { unsigned char pad[0x20]; unsigned char f20; unsigned char f21; };

// USA: func_ov017_021a120c
ARM void SetNodeFieldsAndInsert_021a120c(unsigned char* obj, unsigned char v20, unsigned char v21) {
	func_ov017_021a124c(((Base021a120c*)(obj + 0x3000))->node);
	((NodeFields021a120c*)((Base021a120c*)(obj + 0x3000))->node)->f20 = v20;
	((NodeFields021a120c*)((Base021a120c*)(obj + 0x3000))->node)->f21 = v21;
	InsertNodeAfterHead(((Base021a120c*)(obj + 0x3000))->list, ((Base021a120c*)(obj + 0x3000))->node);
}
