#include <globaldefs.h>

struct ClearNode02046968 {
    char unk0;
    unsigned char flag1;
    unsigned char byte2;
    unsigned char byte3;
    struct ClearNode02046968* next;
};

struct ClearList02046968 {
    struct ClearNode02046968* head;
};

// USA: func_02046968
ARM void ClearListUntilFlagZero(struct ClearList02046968* list) {
    struct ClearNode02046968* node;
    while ((node = list->head) != NULL) {
        if (node->flag1 != 0) {
            node->byte2 = 0;
            list->head->byte3 = 0;
            list->head = list->head->next;
        } else {
            node->byte3 = 1;
            return;
        }
    }
}
