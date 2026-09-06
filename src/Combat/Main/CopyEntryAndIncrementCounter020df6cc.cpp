#include <globaldefs.h>
#include "std_library_functions.h"

struct EntryDf6cc {
    void *name;
    void *desc;
    unsigned char data[0x20 - 8];
};

struct BitFieldDf6cc {
    unsigned short counter : 15;
    unsigned short flag : 1;
};

// USA: func_020df6cc
ARM int CopyEntryAndIncrementCounter020df6cc(void *a, EntryDf6cc *b, int unused, EntryDf6cc *d)
{
    void *savedDesc = b->desc;
    void *savedName = b->name;
    memcpy(b, d, sizeof(EntryDf6cc));
    b->desc = savedDesc;
    b->name = savedName;

    {
        void *bDesc = b->desc;
        void *dDesc = d->desc;
        if (bDesc != NULL) {
            if (dDesc == NULL) {
                *(char*)bDesc = 0;
            } else {
                strcpy((char*)bDesc, (char*)dDesc);
            }
        }
    }

    if (b->name != NULL && d->name != NULL) {
        memcpy(b->name, d->name, 0x20);
        ((BitFieldDf6cc*)((char*)a + 2))->counter++;
    }

    return 1;
}
