#include "wheels.h"


int main()
{
    Solution solution = {0};
    memset(&solution, 0, sizeof(Solution));
    solution.memSize = DEFAULT_MEM_SIZE;
    solution.headerAddr = (VOID*)malloc(solution.memSize);
    ASSERT_NULL_PTR(solution.headerAddr);
    solution.dynamicAddr[0] = &solution.headerAddr;
    WORD32 *i[160] ;
    *i = &solution.dynamicAddr[0];
    solution.dynamicAddr[1] = solution.dynamicAddr[0] + sizeof(i);
    PrintPointerAddr(solution.dynamicAddr[1]);
    PrintPointerAddr(solution.dynamicAddr[0]);
    PrintPointerAddr(&solution.headerAddr);
    FREE_PTR(solution.headerAddr);

    return 0;
}
