//
// Created by roberto on 11/16/23.
//

#include <assert.h>
#include "t_utils.h"
#include "rc_memory.h"

void mem_check() {
    assert(memory_get_allocated() == memory_get_freed());
    printf("\n");
}