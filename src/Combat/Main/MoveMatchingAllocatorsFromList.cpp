#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);
void InsertAllocatorHeaderLocked(SignedAllocatorHeader* header);

// USA: func_020bf358
ARM void MoveMatchingAllocatorsFromList(SignedAllocatorList* list, SignedAllocatorHeader* matchNext) {
    unsigned int mask;
    SignedAllocatorHeader* element;
    SignedAllocatorHeader* next;
    mask = DisableInterrupts();
    element = list->ElementAfter(0);
    if (element != 0) {
        do {
            next = list->ElementAfter(element);
            if (element->pNextAllocator == matchNext) {
                list->Remove(element);
                InsertAllocatorHeaderLocked(element);
            }
            element = next;
        } while (element != 0);
    }
    RestoreInterrupts(mask);
}
