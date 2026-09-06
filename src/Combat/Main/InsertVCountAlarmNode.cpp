#include <globaldefs.h>

struct VCountAlarmNode020c92d0 {
    char _pad[0xc];
    unsigned int key;
    short priority;
    short _pad2;
    struct VCountAlarmNode020c92d0* prev;
    struct VCountAlarmNode020c92d0* next;
};

struct VCountAlarmList020c92d0 {
    char _pad[0xc];
    struct VCountAlarmNode020c92d0* head;
    struct VCountAlarmNode020c92d0* tail;
};

extern struct VCountAlarmList020c92d0 data_02111654;

struct QNode020c934c;
ARM void AppendToQueue(struct QNode020c934c* node);
extern "C" void func_020c945c(void);

// USA: func_020c92d0
ARM void InsertVCountAlarmNode(struct VCountAlarmNode020c92d0* node) {
    struct VCountAlarmNode020c92d0* cur = data_02111654.head;
    unsigned int key;
    struct VCountAlarmNode020c92d0* prev;
    if (cur == NULL) goto append;
    key = node->key;
loop:
    if (cur->key < key) goto advance;
    if (cur->key != key) goto insert;
    if (cur->priority <= node->priority) goto advance;
insert:
    prev = cur->prev;
    node->prev = prev;
    node->next = cur;
    cur->prev = node;
    if (prev != NULL) {
        prev->next = node;
        return;
    }
    data_02111654.head = node;
    func_020c945c();
    return;
advance:
    cur = cur->next;
    if (cur != NULL) goto loop;
append:
    AppendToQueue((struct QNode020c934c*)node);
}
