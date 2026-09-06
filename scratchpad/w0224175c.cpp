#include <globaldefs.h>

extern "C" int func_ov031_022413c8(int unused, int id);

struct Obj02241720;
extern "C" void func_ov031_02241720(Obj02241720* obj);

struct RingState0224175c { unsigned int head; unsigned int tail; };
extern RingState0224175c data_ov031_022919bc;

struct RingSlotA0224175c { int value; int pad4; };
extern RingSlotA0224175c data_ov031_022919c4[];

struct RingSlotB0224175c { void* obj; int pad4; };
extern RingSlotB0224175c data_ov031_022919c8[];

// USA: func_ov031_0224175c
extern "C" ARM void PushRingEntryEvictIfFull_0224175c(int value, void** outSlot) {
	unsigned int head = data_ov031_022919bc.head;
	unsigned int tail = data_ov031_022919bc.tail;
	unsigned int newHead = (head + 1) & 7;

	if (newHead == tail) {
		func_ov031_022413c8(0, data_ov031_022919c4[tail].value);
		func_ov031_02241720((Obj02241720*)data_ov031_022919c8[data_ov031_022919bc.tail].obj);
		data_ov031_022919bc.tail = (data_ov031_022919bc.tail + 1) & 7;
	}

	if (*outSlot == 0) {
		return;
	}

	unsigned int idx = data_ov031_022919bc.head;
	data_ov031_022919c4[idx].value = value;
	data_ov031_022919c8[idx].obj = *outSlot;
	*outSlot = 0;
	data_ov031_022919bc.head = newHead;
}
