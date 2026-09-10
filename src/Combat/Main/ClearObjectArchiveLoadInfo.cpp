#include <globaldefs.h>

struct ObjectArchiveLoadInfo {
    int unknown0;
    int data;
    int size;
    int allocator;
    int copyIntoAllocation;
    int unknown14;
    int unknown18;
    int packageId;
};

// Zeroes an ObjectArchiveLoadInfo before it is filled in and handed to
// Object3D::LoadFromCHRArchive or Object3D::LoadFromCCHROrCMOTArchive. The struct is the eight-int
// one declared in include/World/Object3D.h, whose last member is the package id. Its two callers
// name the middle of it: LoadCharaSubModel and ReloadEventChrAnimationPackage put the file data at
// +0x4, its length at +0x8 and the allocator at +0xc, and both set the copy-into-allocation word at
// +0x10 to 1. LoadCharaSubS202Model fills the same struct in line without calling this and is where
// that name comes from: Object3D::InternalLoadFromCHRArchive copies each file it pulls out of the
// archive into the allocator when +0x10 is nonzero. Only ReloadEventChrAnimationPackage writes a
// package id, 3, and it still passes 0 to MaybeSetBCFGAnimation, so the id does not pick the
// animation played; it tags the package Object3D::RemoveAnimationPackageByID matches. Nothing
// decompiled reads +0x0, +0x14 or +0x18, and both loaders take their file lengths from the archive
// rather than from +0x8.
extern "C" ARM void ClearObjectArchiveLoadInfo(struct ObjectArchiveLoadInfo* loadInfo) {
    loadInfo->unknown0 = 0;
    loadInfo->data = 0;
    loadInfo->size = 0;
    loadInfo->allocator = 0;
    loadInfo->copyIntoAllocation = 0;
    loadInfo->unknown14 = 0;
    loadInfo->unknown18 = 0;
    loadInfo->packageId = 0;
}
