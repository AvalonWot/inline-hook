//
// Created by lamoliu on 2017/4/1.
//

#ifdef __arm__
#include "HookerArm.h"
#include <stdlib.h>

void hooker::HookerArm::doHook(void *func, void *newAddr, void **origFunc) const {
    char *f = (char *)func;
    *(long *)&f[0] = 0xe51ff004; // ldr pc, addr
    *(long *)&f[4] = (long)newAddr;

    __builtin___clear_cache((void*)func,(void*)((unsigned char*)func + 8));
}
#endif
