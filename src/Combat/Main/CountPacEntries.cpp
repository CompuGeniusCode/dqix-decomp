#include <globaldefs.h>

struct ActiveEntry02046900 {
    signed char active;
    char pad[0x47];
    int stride;
};

// Counts the entries of a .pac archive already read into memory. An entry begins with a
// NUL-terminated name in the first 0x40 bytes, then three words: header size, payload size and
// total entry size. The chain is terminated by a zero-filled header, which is what the test on the
// first byte is looking at, and the step is the size at 0x48.
// GetPacEntryByIndex walks the same chain to fetch entry i and its payload length.
extern "C" ARM int CountPacEntries(struct ActiveEntry02046900* entry) {
    int count = 0;
    while (entry->active ? 1 : 0) {
        count++;
        entry = (struct ActiveEntry02046900*)((char*)entry + entry->stride);
    }
    return count;
}
