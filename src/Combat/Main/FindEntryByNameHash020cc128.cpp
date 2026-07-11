#include <globaldefs.h>

unsigned int PackLowercaseCharsToWord(unsigned char* str, int count);
unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);

struct HashListNode020cc128 {
    unsigned int hash;
    struct HashListNode020cc128* next;
};
extern struct HashListNode020cc128* data_02111728;

// USA: func_020cc128
ARM struct HashListNode020cc128* FindEntryByNameHash020cc128(unsigned char* str, int count) {
    unsigned int hash = PackLowercaseCharsToWord(str, count);
    unsigned int mask = DisableInterrupts();
    struct HashListNode020cc128* node = data_02111728;
    while (node != NULL && node->hash != hash) {
        node = node->next;
    }
    RestoreInterrupts(mask);
    return node;
}
