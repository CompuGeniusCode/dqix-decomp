#include <globaldefs.h>

struct Node02097844 {
    struct Node02097844* next;
    unsigned char pad4[0xf];
    unsigned char bit0 : 1;
    unsigned char marked : 1;
    unsigned char bit2_7 : 6;
};

// USA: func_02097844
ARM void RegroupMarkedRuns02097844(struct Node02097844** headPtr, int groupSize) {
    int runLen;
    int markedInRun;
    struct Node02097844* last;
    int keptCount;
    struct Node02097844* runStart;
    struct Node02097844* prevTail;
    struct Node02097844* firstTail;
    struct Node02097844* cursor;

    if (groupSize <= 0) {
        return;
    }
    runStart = *headPtr;
    runLen = 0;
    markedInRun = 0;
    keptCount = 0;
    prevTail = NULL;
    firstTail = NULL;
    cursor = runStart;
    while (cursor != NULL) {
        runLen++;
        if (cursor->marked) {
            markedInRun++;
        }
        last = cursor;
        cursor = cursor->next;
        if (runLen == groupSize || cursor == NULL) {
            if (markedInRun > 0) {
                keptCount++;
                if (prevTail != NULL) {
                    prevTail->next = runStart;
                } else {
                    *headPtr = runStart;
                }
                prevTail = last;
            }
            runLen = 0;
            markedInRun = 0;
            runStart = cursor;
            if (firstTail == NULL) {
                firstTail = last;
            }
        }
    }
    if (keptCount == 0) {
        if (firstTail != NULL) {
            firstTail->next = NULL;
        }
    } else {
        if (prevTail != NULL) {
            prevTail->next = NULL;
        }
    }
}
