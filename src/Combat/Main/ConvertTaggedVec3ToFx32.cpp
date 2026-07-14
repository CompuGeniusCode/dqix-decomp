#include <globaldefs.h>

struct TaggedValue02030b44 {
    int type;
    union { int i; float f; } value;
};
float GetTaggedValueAsFloat(struct TaggedValue02030b44* v);

// USA: func_02030b98
ARM struct TaggedValue02030b44* ConvertTaggedVec3ToFx32(struct TaggedValue02030b44* obj, int* outVec) {
    outVec[0] = (int)(4096.0f * GetTaggedValueAsFloat(obj + 0));
    outVec[1] = (int)(4096.0f * GetTaggedValueAsFloat(obj + 1));
    outVec[2] = (int)(4096.0f * GetTaggedValueAsFloat(obj + 2));
    return obj + 3;
}
