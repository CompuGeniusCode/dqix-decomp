#include <globaldefs.h>

struct SearchKey02201c84 { unsigned short field0; unsigned short field2; };
struct QueryObj02201c84 { char pad[0xc]; unsigned short fieldC; unsigned short fieldE; };
struct Candidate02201c84 {
	void* field0;
	char pad4[4];
	unsigned char field8;
	char pad9;
	unsigned short fieldA;
	char padC[0xc];
	unsigned short field18;
	char pad1a[2];
	int field1c;
};
struct ListNode02201c84 {
	char pad0[0x68];
	ListNode02201c84* next;
	char pad1[0x38];
	Candidate02201c84* candidate;
};
struct Global02201c84 { char pad[8]; ListNode02201c84* head; };
extern struct Global02201c84 data_02111304;

// USA: func_ov031_02201c84
extern "C" ARM Candidate02201c84* FindMatchingCandidate02201c84(QueryObj02201c84* obj, SearchKey02201c84* key) {
	ListNode02201c84* node = data_02111304.head;
	if (!node) return 0;
	do {
		Candidate02201c84* c = node->candidate;
		if (!c || !c->field0) goto next;
		if (c->field8 != 1) goto next;
		{
			unsigned short v = key->field2;
			int sw = (v >> 8) | (v << 8);
			if (c->fieldA != (unsigned short)sw) goto next;
		}
		if (c->field18 != 0) {
			unsigned short v = key->field0;
			int sw = (v >> 8) | (v << 8);
			if (c->field18 != (unsigned short)sw) goto next;
		}
		if (c->field1c != 0) {
			unsigned short ve = obj->fieldE;
			unsigned short vc = obj->fieldC;
			int swe = (ve >> 8) | (ve << 8);
			int swc = (vc >> 8) | (vc << 8);
			int combined = ((unsigned short)swe << 16) | (unsigned short)swc;
			if (c->field1c != combined) goto next;
		}
		return c;
	next:
		node = node->next;
	} while (node);
	return 0;
}
