#include <globaldefs.h>

int GetData0224e53c_0220d60c(void);
extern "C" int CompareBytes6_0220f368(unsigned char* a, unsigned char* b);

struct ListNode0220ede4 {
	char pad[0xc];
	ListNode0220ede4* next;
	char pad2[0x14 - 0x10];
	unsigned char key6[6];
};

struct Header0220ede4 {
	char pad[4];
	ListNode0220ede4* field4;
};

struct Table0220ede4 {
	char pad[0x270];
	Header0220ede4* field270;
	unsigned int field274;
};

// USA: func_ov031_0220ede4
ARM ListNode0220ede4* FindNodeMatchingKey6_0220ede4(unsigned char* key) {
	int base = GetData0224e53c_0220d60c();
	Table0220ede4* t = (Table0220ede4*)(base + 0x2000);
	ListNode0220ede4* result = NULL;
	Header0220ede4* p = t->field270;
	if (key == NULL) {
		return NULL;
	}
	if (p == NULL) {
		goto end;
	}
	if (t->field274 <= 0xc) {
		goto end;
	}
	result = p->field4;
	if (result == NULL) {
		goto end;
	}
	do {
		if (CompareBytes6_0220f368(result->key6, key)) {
			goto end;
		}
		result = result->next;
	} while (result != NULL);
end:
	return result;
}
