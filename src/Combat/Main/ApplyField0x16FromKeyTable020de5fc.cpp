#include <globaldefs.h>

struct Element020de650;
struct Container020de650;
typedef int (*KeyFunc020de650)(struct Element020de650*);
struct Element020de650* BinarySearchByComparator020de650(struct Container020de650* c, int key, KeyFunc020de650 fn);
extern "C" int func_020de56c(struct Element020de650*);
extern short data_020ee794[];

// USA: func_020de5fc
ARM int ApplyField0x16FromKeyTable020de5fc(struct Container020de650* container) {
    short* keys = data_020ee794;
    int i;
    for (i = 0; i < 2; i++, keys++) {
        struct Element020de650* elem = BinarySearchByComparator020de650(container, *keys, func_020de56c);
        if (elem != NULL) {
            *(short*)((char*)elem + 0x16) = 0xfc;
        }
    }
    return 1;
}
