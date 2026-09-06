#include <globaldefs.h>

struct EntryList020bbc68;
struct Ring020bbc78;
struct Job020bbc38 { char pad[0xc]; int size; };

Job020bbc38* GetIndexedEntry020bbc68(EntryList020bbc68* list);
int AdvanceRing020bbc78(Ring020bbc78* ring);
int RunJobAtIndex020bbc38(Job020bbc38* job);

extern char data_0210cf94[];

// USA: func_020bbcb4
ARM void ProcessRingJobs020bbcb4(void) {
    char* q = data_0210cf94;
    Job020bbc38* job = GetIndexedEntry020bbc68((EntryList020bbc68*)q);
    if (!AdvanceRing020bbc78((Ring020bbc78*)q)) return;
    do {
        RunJobAtIndex020bbc38(job);
        *(int*)(q + 0x10) -= job->size;
        job = GetIndexedEntry020bbc68((EntryList020bbc68*)q);
    } while (AdvanceRing020bbc78((Ring020bbc78*)q));
}
