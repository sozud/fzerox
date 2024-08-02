#include "libultra/ultra64.h"
#include "leo/leo_internal.h"

s32 LeoRezero(LEOCmd* cmdBlock, OSMesgQueue* mq) {
    if (__leoActive == 0) {
        return -1;
    }
    cmdBlock->header.command = LEO_COMMAND_REZERO;
    cmdBlock->header.reserve1 = 0;
    cmdBlock->header.control = 0;
    cmdBlock->header.reserve3 = 0;
    if (mq != NULL) {
        cmdBlock->header.control |= LEO_CONTROL_POST;
        cmdBlock->header.post = mq;
    }
    leoCommand(cmdBlock);
    return 0;
}
