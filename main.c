#include "wheels.h"


int main()
{
    Solution solution = {0};
    InitSolutionStruct(&solution, DEFAULT_MEM_SIZE);
    ASSERT_NULL_PTR(solution.headerAddr);
    solution.dynamicAddr[0] = &solution.headerAddr;
    WORD16 i[160] = {0};
    AllocMemoryWithSize(&solution, sizeof(i));
    WORD32 *j[20];
    AllocMemoryWithSize(&solution, sizeof(j));
    PrintPointerAddr(&solution.headerAddr);
    PrintPointerAddr(solution.dynamicAddr[0]);
    PrintPointerAddr(solution.dynamicAddr[1]);
    PrintPointerAddr(solution.dynamicAddr[2]);
    DestructSolution(&solution);

    return 0;
}
