#include <globaldefs.h>

struct QNode020c934c {
    unsigned char _pad[0x14];
    QNode020c934c* prev; // +0x14
    QNode020c934c* next; // +0x18
};

struct QHead020c934c {
    unsigned char _pad[0xc];
    QNode020c934c* head; // +0xc
    QNode020c934c* tail; // +0x10
};

extern QHead020c934c data_02111654;
extern "C" void func_020c945c(void);

// USA: func_020c934c
ARM void AppendToQueue(QNode020c934c* node) {
    QNode020c934c* oldTail = data_02111654.tail;
    node->prev = oldTail;
    node->next = NULL;
    data_02111654.tail = node;
    if (oldTail != NULL) {
        oldTail->next = node;
        return;
    }
    data_02111654.head = node;
    func_020c945c();
}
