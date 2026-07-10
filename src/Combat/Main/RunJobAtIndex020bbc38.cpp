#include <globaldefs.h>

void CleanInvalidateDataCacheRange(int addr, int size);

typedef int (*JobFn020bbc38)(int, int, int);
extern JobFn020bbc38 data_020e92a8[];

struct Job020bbc38 {
    int idx;    // +0x0
    int addr;   // +0x4
    int mid;    // +0x8
    int size;   // +0xc
};

// USA: func_020bbc38
ARM int RunJobAtIndex020bbc38(Job020bbc38* job) {
    JobFn020bbc38 fn = data_020e92a8[job->idx];
    CleanInvalidateDataCacheRange(job->addr, job->size);
    return fn(job->addr, job->mid, job->size);
}
