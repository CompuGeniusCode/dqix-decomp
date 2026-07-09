#include <globaldefs.h>

struct Entry0206f110 {
    char pad[0x1c];
};

struct EntryList0206f110 {
    unsigned int count : 12;
    unsigned int rest : 20;
    struct Entry0206f110* entries;
};

// USA: func_0206f110
ARM int InvokeCallbackForEachEntry(struct EntryList0206f110* self,
                                   void (*callback)(struct EntryList0206f110*, struct Entry0206f110*)) {
    int count;
    struct Entry0206f110* entry = self->entries;
    int i;
    if (entry != NULL) {
        count = self->count;
        if (count != 0 && callback != NULL) {
            goto run;
        }
    }
    return 0;
run:
    i = 0;
    while (i < count) {
        callback(self, entry);
        i++;
        entry++;
    }
    return 1;
}
