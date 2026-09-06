#include <globaldefs.h>

struct Node02040774;
void SetActiveChildFields02040774(struct Node02040774* obj, int a, int b, int c);

struct Entry_0216427c { int type; char pad[8]; void* field_c; };
struct FieldsC_0216427c { char unk0[0x44]; int field44; int field48; int field4c; };

// USA: func_ov001_0216427c  (semantic: DispatchEntryFieldsOrChild_0216427c)
extern "C" ARM int func_ov001_0216427c(Entry_0216427c* table, int index, int arg2, int arg3, int arg4) {
	Entry_0216427c* entry;
	void* member;
	if (index < 0 || index >= 0x20) return 0;
	entry = &table[index];
	switch (entry->type) {
	case 0:
	case 1:
	case 4:
	case 5:
		member = entry->field_c;
		if (member == 0) return 0;
		((FieldsC_0216427c*)member)->field44 = arg2;
		((FieldsC_0216427c*)member)->field48 = arg3;
		((FieldsC_0216427c*)member)->field4c = arg4;
		return 1;
	case 2:
	case 6:
		member = entry->field_c;
		if (member == 0) return 0;
		SetActiveChildFields02040774((struct Node02040774*)member, arg2, arg3, arg4);
		return 1;
	default:
		return 0;
	}
}
