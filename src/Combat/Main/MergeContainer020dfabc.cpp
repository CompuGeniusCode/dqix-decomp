#include <globaldefs.h>
#include "std_library_functions.h"

struct Container020dfa68;
struct Element020dfa68;
typedef int (*ElementCallback020dfa68)(struct Container020dfa68 *, struct Element020dfa68 *);
extern int ForEachElement020dfa68(struct Container020dfa68 *, ElementCallback020dfa68);

struct ScaledPair020dfbc0;
extern int GetScaledFieldSum(struct ScaledPair020dfbc0 *);

struct MergedContainer020dfabc {
    unsigned short count;
    unsigned short pad2;
    unsigned int pad4a : 15;
    unsigned int doneFlag : 1;
    unsigned int pad4b : 16;
    void *elements;
    unsigned int end;
};

// USA: func_020dfabc
ARM int MergeContainer020dfabc(struct MergedContainer020dfabc *self, struct MergedContainer020dfabc *src, char *outFlag, ElementCallback020dfa68 cb) {
    *outFlag = 0;
    if (src == NULL) return 0;
    memcpy(self, src, 8);
    self->elements = (void *)((char *)src + 8);
    self->end = (unsigned int)((GetScaledFieldSum((struct ScaledPair020dfbc0 *)self) + 8) + (char *)src);
    if (self->doneFlag) {
        *outFlag = 1;
        return 1;
    }
    ForEachElement020dfa68((struct Container020dfa68 *)self, cb);
    self->doneFlag = 1;
    src->doneFlag = 1;
    return 1;
}
