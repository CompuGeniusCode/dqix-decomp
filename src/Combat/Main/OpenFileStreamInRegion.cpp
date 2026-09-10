#include <globaldefs.h>

struct AllocatorHolder;
extern "C" void func_020bd984(struct AllocatorHolder*);
extern "C" void func_0203a914(void*);
extern "C" extern void* func_020bd914(void* start, unsigned int size);
struct StreamHolder;
extern "C" int func_020bd110(struct StreamHolder* holder, const char* path, int allocatorHolder, int unknown3);
extern "C" int func_020be6c4(void* allocatorHolder);
extern "C" void func_020be9e8(void* contextPriority, void* allocatorHolder);
struct AllocatorHolder;
extern "C" int func_020bdac0(struct AllocatorHolder*);

struct SoundPlayer {
    void* allocatorHolder;
    char unknown4[0x9c];
    int savedAllocatorState;
};

// Opens a file stream inside a caller-supplied memory region, discarding whatever the sound player
// already had open there. func_020bd914 lays a region allocator over [start, start+size) and the
// holder for it is kept at +0x0; the stream holder func_020bd110 initialises -- a NitroVM plus a
// file accessor for path -- sits at +0x4, and func_020be6c4 then allocates that stream's entry
// buffers out of the same allocator, giving up quietly when it cannot. initStreamPool additionally
// runs func_020be9e8, which brings the four-entry streaming VM pool at data_02110a4c up once: the
// two bgm.sdat openers pass 1 and SetSoundSceneMode passes 0 for the se_norm/se_btl archives.
// func_020be9e8's other argument is the priority it hands PopulateContext through func_020bf2f8 for
// the streaming context at data_02110560, and this call passes 0. +0xa0 keeps the allocator
// save-state index func_020bdac0 hands back, or -1 when that fails. A size of 0 or 1 is treated as
// no region at all, and the repeated null test on the old allocator holder is in the original.
// What arg3 of func_020bd110 selects is not established; every caller passes 0.
extern "C" ARM void OpenFileStreamInRegion(struct SoundPlayer* player, const char* path, void* start, unsigned int size, void* initStreamPool) {
    void* allocatorHolder;
    if (size <= 1) {
        return;
    }
    allocatorHolder = player->allocatorHolder;
    if (allocatorHolder == 0) {
        goto skip_both;
    }
    if (allocatorHolder == 0) {
        goto skip_destroy;
    }
    func_020bd984((struct AllocatorHolder*)allocatorHolder);
skip_destroy:
    func_0203a914(player);
skip_both:
    player->allocatorHolder = func_020bd914(start, size);
    func_020bd110((struct StreamHolder*)((char*)player + 4), path, (int)player->allocatorHolder, 0);
    if (func_020be6c4(player->allocatorHolder) == 0) {
        return;
    }
    if (initStreamPool != 0) {
        func_020be9e8(0, player->allocatorHolder);
    }
    player->savedAllocatorState = func_020bdac0((struct AllocatorHolder*)player->allocatorHolder);
}
