#include <globaldefs.h>

short FindMappedMemberId02080468(void* obj, int id);
extern "C" void func_ov014_02188a8c(void* self, short key);

struct EntryNode_021873a0 {
    EntryNode_021873a0* next;
    char pad4[0x16];
    short f1a;
};

struct SelfType_021873a0 {
    char pad0[0x98];
    void* f98;
    char pad9c[0x1c];
    EntryNode_021873a0* fb8;
    EntryNode_021873a0* fbc;
    void* fc0;
    char padc4[0xb2];
    short f176;
};

// USA: func_ov014_021873a0  (semantic: SearchAndAdvanceEntry_021873a0)
extern "C" ARM EntryNode_021873a0* func_ov014_021873a0(SelfType_021873a0* self) {
    void* obj = self->fc0;
    short id = FindMappedMemberId02080468(obj, 5);
    short target = (short)(self->f176 - id);
    EntryNode_021873a0* node = self->fbc;
    short count = 0;
    while (node != 0) {
        if (target == count) {
            break;
        }
        EntryNode_021873a0* next = node->next;
        if (next == 0) {
            break;
        }
        count = count + 1;
        node = next;
    }
    if (node == 0) {
        self->fbc = self->fb8;
        count = 0;
    }
    id = FindMappedMemberId02080468(obj, 5);
    self->f176 = count + id;
    if (node != 0) {
        short key = node->f1a;
        func_ov014_02188a8c(self, key);
        self->f98 = (char*)self + 0x182;
    }
    return node;
}
