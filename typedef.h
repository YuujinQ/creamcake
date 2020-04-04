#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>


#define DEFAULT_MEM_SIZE    (1024 * 1024)
#define DYN_MEM_SEG_NUM     (16)

#define ASSERT_NULL_PTR(p)  if(NULL == p) return 0;
#define FREE_PTR(p)         free(p); p = NULL;

typedef unsigned long int WORD32;
typedef signed long int   SWORD32;
typedef unsigned int      WORD16;
typedef signed int        SWORD16;
typedef signed char       SCHAR;
typedef unsigned char     UCHAR;
typedef void              VOID;
typedef bool              BOOL;

typedef VOID* (*fHandle)(VOID*);
