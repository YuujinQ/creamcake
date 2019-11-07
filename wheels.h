#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "typedef.h"


typedef struct Solution
{
    fHandle handle;
    WORD32  memSize;
    UCHAR   memAddrNum;
    VOID*   headerAddr;
    VOID*   dynamicAddr[DYN_MEM_SEG_NUM];
    WORD32  memSegSize[DYN_MEM_SEG_NUM];
}Solution;


VOID PrintPointerAddr(VOID *pointer);
