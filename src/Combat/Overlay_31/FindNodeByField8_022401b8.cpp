#include <globaldefs.h>

struct Node_022401b8 { unsigned char pad[4]; struct Node_022401b8* next; void* field8; };
extern struct Node_022401b8* data_ov031_02290fdc;

// USA: func_ov031_022401b8  (semantic: FindNodeByField8_022401b8)
extern "C" ARM void* func_ov031_022401b8(void* target) {
    struct Node_022401b8* result = NULL;
    struct Node_022401b8* head = data_ov031_02290fdc;
    if (head != NULL) {
        if (head->field8 == target) {
            result = head;
        } else {
            struct Node_022401b8* cur = head->next;
            if (cur != head) {
                do {
                    if (cur->field8 == target) { result = cur; break; }
                    cur = cur->next;
                } while (cur != head);
            }
        }
    }
    return result;
}
