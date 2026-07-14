#include <globaldefs.h>

struct TaggedValue02030b44 {
    int type;
    union { int i; float f; } value;
};
float GetTaggedValueAsFloat(struct TaggedValue02030b44* v);

// USA: func_02030c00
ARM struct TaggedValue02030b44* ConvertTaggedVec3ToFx16(struct TaggedValue02030b44* obj, short* outVec) {
    outVec[0] = (short)(int)(4096.0f * GetTaggedValueAsFloat(obj + 0));
    outVec[1] = (short)(int)(4096.0f * GetTaggedValueAsFloat(obj + 1));
    outVec[2] = (short)(int)(4096.0f * GetTaggedValueAsFloat(obj + 2));
    return obj + 3;
}
