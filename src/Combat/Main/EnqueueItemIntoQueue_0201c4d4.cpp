#include <globaldefs.h>

struct ItemChunk1_0201c4d4 { unsigned char b[8]; };
struct ItemChunk2_0201c4d4 { unsigned char b[0x1c]; };
struct BitField0x29_0201c4d4 { unsigned char low : 3; unsigned char high : 5; };

struct Item_0201c4d4 {
    unsigned short f0;
    unsigned short f2;
    unsigned char f4;
    struct ItemChunk1_0201c4d4 f5;
    struct ItemChunk2_0201c4d4 fd;
    struct BitField0x29_0201c4d4 f29;
    unsigned char f2a;
};

struct Queue_0201c4d4 {
    unsigned char* historyBuf;
    int f4;
    int count;
    struct Item_0201c4d4* entries;
    int writeIndex;
    int capacity;
    int f18;
    int f1c;
};

// USA: func_0201c4d4  (semantic: EnqueueItemIntoQueue_0201c4d4)
extern "C" ARM void func_0201c4d4(struct Queue_0201c4d4* q, struct Item_0201c4d4* item) {
    struct Item_0201c4d4* dst;

    if (q->historyBuf) {
        if (q->count < q->f4) {
            (q->historyBuf + 0x1f)[(q->count - 1) * 0x20]++;
        }
    }

    if (q->f18 >= 0) {
        if (q->f18 != q->count - 1) {
            return;
        }
    }

    if (q->f1c >= 0) {
        if (q->f1c != item->f29.low) {
            return;
        }
    }

    if (!q->entries) {
        return;
    }
    if (q->writeIndex >= q->capacity) {
        return;
    }

    dst = &q->entries[q->writeIndex];
    dst->f0 = item->f0;
    dst->f2 = item->f2;
    dst->f4 = item->f4;
    dst->f5 = item->f5;
    dst->fd = item->fd;
    dst->f29 = item->f29;
    dst->f2a = item->f2a;

    if (q->count > 0) {
        q->entries[q->writeIndex].f4 = q->count - 1;
    }

    q->writeIndex = q->writeIndex + 1;
}
