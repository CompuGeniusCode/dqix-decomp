#pragma once

#include "ProcessorContext.h"

// This only works for arm9-exclusive objects. The mutex functions
// work by disabling IRQ interrupts and manually yielding the thread
struct Mutex
{
    BlockedContextList waitingContexts_;
    ProcessorContext* ownedContext_;
    // you can lock the mutex multiple times on the same thread
    unsigned int ownerRefcount_;
    Mutex* pNext_;
    Mutex* pPrev_;
};

// usa: _Z19ZeroInitializeMutexP5Mutex
void ZeroInitializeMutex(Mutex* mutex);
// usa: _Z9LockMutexP5Mutex
void LockMutex(Mutex* mutex);
// usa: _Z11UnlockMutexP5Mutex
void UnlockMutex(Mutex* mutex);
// usa: _Z31UnlockAllMutexesLockedByContextP16ProcessorContext
void UnlockAllMutexesLockedByContext(ProcessorContext* context);
// usa: _Z12TryLockMutexP5Mutex
bool TryLockMutex(Mutex* mutex);