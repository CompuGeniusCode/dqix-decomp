#include <globaldefs.h>
#include "Filesystem/NitroVM.h"
#include "Filesystem/FileAccessor.h"
#include "Filesystem/LowNitroHandle.h"

#pragma optimize_for_size off

// USA: func_ov027_021dac74
ARM CBool ReadFileWithSizeCheck_021dac74(const char* path, void* dst, int large)
{
    unsigned int capacity = large ? 0x200 : 0x20;
    char* dstAdjusted = large ? (char*)dst + 0x20 : (char*)dst;

    if (path == NULL)
        return false;

    NitroVM vm;
    NitroVM_Initialize(&vm);

    if (!NitroVM_PrepareReadFileByPath(&vm, path))
        return false;

    unsigned int size = vm.fileInfo.endOffset - vm.fileInfo.startOffset;
    if (capacity != size)
    {
        NitroVM_FinishRead(&vm);
        return false;
    }

    NitroVM_ReadSync(&vm, dstAdjusted, capacity);
    NitroVM_FinishRead(&vm);
    return true;
}
