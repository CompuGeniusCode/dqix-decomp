#include <globaldefs.h>

extern "C" void SuspendVCountMatchIrq(void);
extern "C" void func_020d84e4(void);
extern "C" void func_020d84e8(void);
extern "C" void* GetMultiplayerState(void);
extern "C" void PopVCountInterruptState(void);
extern "C" void FatalHalt(void);
extern "C" int IsMultiplayerActive(int* state);

struct FreeEventNode {
    char unknown0[0x18];
    struct FreeEventNode* next;
};
struct FreeEventList {
    struct FreeEventNode* head;
    struct FreeEventNode* tail;
    int count;
};
extern "C" struct FreeEventNode* func_0205e1e4(struct FreeEventList* list);

struct PostedEventNode {
    char unknown0[0x18];
    struct PostedEventNode* next;
};
struct PostedEventList {
    struct PostedEventNode* head;
    struct PostedEventNode* tail;
    int count;
};
extern "C" void func_0205e18c(struct PostedEventList* list, struct PostedEventNode* record);

struct GamemainEventPayload { unsigned int words[4]; };
struct GamemainEvent { unsigned char tag; unsigned char unknown1; unsigned char unknown2[2]; struct GamemainEventPayload payload; };
extern "C" struct GamemainEvent* func_0205e3ec(struct GamemainEvent* destEvent, struct GamemainEvent* sourceEvent);

struct QueuedEventRecord {
    char unknown0[0x16];
    short flags;
};

struct GamemainEventQueueCounts {
    char unknown0[0x508];
    volatile int freeCount;
    char unknown50c[0x514 - 0x508 - 4];
    volatile int postedCount;
    char unknown518[0x520 - 0x514 - 4];
    volatile int readyCount;
};

// Posts one record to the global event queue at data_02100044: 192 records of 0x1c bytes with its
// free list at +0x1500, pending at +0x150c and finished at +0x1518. Byte 0 is the event tag, and
// func_ov017_021d48f0 calls data_ov017_021d7f98[tag] only when tag < 0xbc and the bit for it is set
// in the array at +0x1524. The short at +0x16 is the flag word the pump func_0205e57c reads; bit 0
// makes it wait for all five slots to be idle, and it re-emits the record once per channel with
// the channel index at +0x14, so one post fans out. Running out of free records is fatal, and the
// three empty loops before the halt spin on the three lists' own count words, at +0x1508, +0x1514
// and +0x1520. No ov017 poster writes the byte at +0x1, so the copy carries whatever the poster
// left on its stack there, and the two bytes after it func_0205e3ec does not copy at all.
extern "C" ARM void EnqueueGamemainEvent(unsigned char* queue, struct GamemainEvent* event, short flags) {
    struct FreeEventNode* record;

    SuspendVCountMatchIrq();
    func_020d84e4();

    if (IsMultiplayerActive((int*)GetMultiplayerState())) {
        record = func_0205e1e4((struct FreeEventList*)(queue + 0x1500));
        if (record != NULL) {
            func_0205e3ec((struct GamemainEvent*)record, event);
            ((struct QueuedEventRecord*)record)->flags = flags;
            func_0205e18c((struct PostedEventList*)(queue + 0x150c), (struct PostedEventNode*)record);
        } else {
            for (int i = 0; i < ((struct GamemainEventQueueCounts*)(queue + 0x1000))->freeCount; i++);

            for (int i = 0; i < ((struct GamemainEventQueueCounts*)(queue + 0x1000))->postedCount; i++);

            for (int i = 0; i < ((struct GamemainEventQueueCounts*)(queue + 0x1000))->readyCount; i++);

            FatalHalt();
        }
    }

    func_020d84e8();
    PopVCountInterruptState();
}
