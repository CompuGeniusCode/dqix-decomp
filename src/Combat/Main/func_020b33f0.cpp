#include <globaldefs.h>

#pragma opt_common_subs off

struct Archive020b33f0 {
    char unk0[8];
    int sectionOffset;
};

struct Section020b33f0 {
    char unk0[2];
    unsigned short groupOffset;
};

struct Group020b33f0 {
    char unk0;
    unsigned char count;
    char unk2[4];
    unsigned short blockOffset;
};

struct RecordBlock020b33f0 {
    unsigned short recordSize;
    unsigned short entryOffset;
};

struct Binding020b33f0 {
    char unk0[0x34];
    unsigned short tableOffset;
};

extern "C" void *func_020b736c(void *table, void *entry);
extern "C" void func_020b3310(void *section, void *record, void *binding, void *resolved);

// USA: func_020b33f0
extern "C" ARM int func_020b33f0(Archive020b33f0 *archive, Binding020b33f0 *binding) {
    Group020b33f0 *group;
    unsigned int index;
    int allResolved = 1;
    Section020b33f0 *section;
    if (archive != 0 && archive->sectionOffset != 0) {
        section = (Section020b33f0 *)((char *)archive + archive->sectionOffset);
    } else {
        section = 0;
    }
    group = (Group020b33f0 *)((char *)section + section->groupOffset);
    index = 0;
    if (index < group->count) {
        int entryStep = 0;
        void *noEntry = 0;
        void *noMatch = 0;
        do {
            void *entry;
            if (group != 0 && index < group->count) {
                RecordBlock020b33f0 *block =
                    (RecordBlock020b33f0 *)((char *)group + group->blockOffset);
                entry = (char *)block + block->entryOffset + entryStep;
            } else {
                entry = noEntry;
            }
            void *resolved;
            if (binding != 0 && binding->tableOffset != 0) {
                resolved = func_020b736c((char *)binding + binding->tableOffset, entry);
            } else {
                resolved = noMatch;
            }
            if (resolved != 0) {
                void *record;
                if (group != 0 && index < group->count) {
                    RecordBlock020b33f0 *block =
                        (RecordBlock020b33f0 *)((char *)group + group->blockOffset);
                    record = (char *)block + 4 + block->recordSize * index;
                } else {
                    record = 0;
                }
                if (!(*((unsigned char *)record + 3) & 1)) {
                    func_020b3310(section, record, binding, resolved);
                }
            } else {
                allResolved = 0;
            }
            index++;
            entryStep += 0x10;
        } while (index < group->count);
    }
    return allResolved;
}
