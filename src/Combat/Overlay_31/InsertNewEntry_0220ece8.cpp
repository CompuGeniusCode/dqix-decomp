#include <globaldefs.h>

int GetData0224e53c_0220d60c(void);

struct Entry0220ece8 {
	unsigned char used;
	unsigned char pad0[3];
	int id;
	Entry0220ece8* next;
	Entry0220ece8* prev;
	unsigned char pad1[0xd0 - 0x10];
};

struct Header0220ece8 {
	int count;
	Entry0220ece8* tail;
	Entry0220ece8* head;
};

struct BaseCtx0220ece8 {
	unsigned char pad0[0x270];
	Header0220ece8* header;
	unsigned int rawCapacity;
};

// USA: func_ov031_0220ece8  (semantic: InsertNewEntry_0220ece8)
#pragma optimize_for_size off
extern "C" ARM Entry0220ece8* func_ov031_0220ece8(void) {
	int base = GetData0224e53c_0220d60c();
	BaseCtx0220ece8* ctx = (BaseCtx0220ece8*)(base + 0x2000);
	Header0220ece8* h = ctx->header;
	Entry0220ece8* e = 0;
	if (h == 0) return e;
	if (ctx->rawCapacity <= 0xc) return e;

	unsigned int capacity = (ctx->rawCapacity - 0xc) / 0xd0;
	if (capacity == 0) return e;
	if (capacity <= (unsigned int)h->count) return e;

	unsigned int i = 0;
	if (i < capacity) {
		Entry0220ece8* arr = (Entry0220ece8*)((char*)h + 0xc);
		do {
			e = (Entry0220ece8*)((char*)arr + i * 0xd0);
			if (e->used == 0) break;
			i++;
		} while (i < capacity);
	}
	if (i >= capacity) return e;

	e->used = 1;
	e->id = h->count;
	e->prev = 0;
	e->next = h->head;
	h->head = e;
	if (e->next != 0) {
		e->next->prev = e;
	} else {
		h->tail = e;
	}
	h->count = h->count + 1;
	return e;
}
