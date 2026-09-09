#pragma once

#include "../System/ProcessorContext.h"
#include "../System/Mutex.h"

// Provides a global instance of a mutex to be locked/unlocked by
// various different resource-related operations. For example, it's used
// by memory allocators and the BackgroundLoader for files

// usa: _Z23InitializeResourceMutexv
void InitializeResourceMutex();

// usa: _Z27SetResourceMutexOperationalb
// If set to false, lock and unlock operations on the mutex will not
// go through. If set to true, they will behave as normal.
// Returns the old status.
bool SetResourceMutexOperational(bool to);
// usa: _Z17LockResourceMutexv
void LockResourceMutex();
// usa: _Z19UnlockResourceMutexv
void UnlockResourceMutex();
// usa: _Z29SleepIfResourceMutexNotLockedj
void SleepIfResourceMutexNotLocked(unsigned int milliseconds);