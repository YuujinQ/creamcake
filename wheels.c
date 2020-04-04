#include "wheels.h"

VOID PrintPointerAddr(VOID *pointer)
{
    printf("Address of pointer is 0x%p\n", pointer);
}

VOID InitSolutionStruct(Solution *solution, WORD32 size)
{
    memset(solution, 0, sizeof(*solution));
    solution->memSize = size;
    solution->memLeft = solution->memSize;
    solution->headerAddr = (VOID*)malloc(size);
    solution->dynamicAddr[0] = solution->headerAddr;
}

VOID DestructSolution(Solution *solution)
{
    FREE_PTR(solution->headerAddr);
    for(WORD32 memLoop = 0; memLoop < solution->memAddrNum; ++memLoop)
    {
        FREE_PTR(solution->dynamicAddr[memLoop]);
    }
}

BOOL AllocMemoryWithSize(Solution *solution, WORD32 size, void *srcPtr)
{
    if(solution->memAddrNum >= DYN_MEM_SEG_NUM || solution->memLeft < size) return false;
    solution->memSegSize[solution->memAddrNum] = size;
    memcpy(solution->dynamicAddr[solution->memAddrNum], srcPtr, size);
    solution->dynamicAddr[solution->memAddrNum + 1] = solution->dynamicAddr[solution->memAddrNum] + size;
    solution->memAddrNum++;
    solution->memLeft -= size;
}