/*
# This file is Copyright 2010 Dean Hall.
#
# This file is part of the Python-on-a-Chip program.
# Python-on-a-Chip is free software: you can redistribute it and/or modify
# it under the terms of the GNU LESSER GENERAL PUBLIC LICENSE Version 2.1.
#
# Python-on-a-Chip is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# A copy of the GNU LESSER GENERAL PUBLIC LICENSE Version 2.1
# is seen in the file COPYING up one directory from this.
*/

/**
 * System Test 999
 * Eliminate remnants of unused OBJ_TYPE_EXN
 */

#include "pm.h"


#define HEAP_SIZE 0x2000

extern unsigned char usrlib_img[];


int main(void)
{
    uint8_t heap[HEAP_SIZE];
    PmReturn_t retval;

    retval = pm_init(heap, HEAP_SIZE, MEMSPACE_PROG, usrlib_img);
    PM_RETURN_IF_ERROR(retval);

    retval = pm_run((uint8_t *)"t248");
    C_ASSERT((int)retval == PM_RET_EX_ASSRT);
    if (retval == PM_RET_EX_ASSRT) return (int)PM_RET_OK;
    return (int)retval;
}
