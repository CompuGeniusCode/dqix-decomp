#include <globaldefs.h>

struct Entry6_021538b4 { char pad[5]; unsigned char field5; };
Entry6_021538b4* FindEntryByShort_021538b4(Entry6_021538b4* base, int key);
extern Entry6_021538b4* data_ov004_021707c0;

// USA: func_ov004_02153860  (semantic: SumFieldOverRange1To6_02153860)
extern "C" ARM short func_ov004_02153860(void) {
    short total = 0;
    for (short i = 1; i <= 6; i++) {
        Entry6_021538b4* entry = FindEntryByShort_021538b4(data_ov004_021707c0, i);
        if (entry) total = total + entry->field5;
    }
    return total;
}
