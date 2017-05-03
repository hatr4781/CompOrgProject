#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "main.h"
#include "Cache.h"
struct cache caches[numBlocks];

void InitializeCache()
{
    int a, b;
    for(a = 0; a < numBlocks; a++)
    {
        caches[numBlocks].addr = 0;
        caches[numBlocks].tag = 0;
        caches[numBlocks].index = 0;
        caches[numBlocks].offset = 0;
    }
}

void CacheWrite(uint32_t Address)
{
    uint32_t Tag;
    uint32_t Index;
    uint32_t Offset;

    Tag = (Address >> 15) & 0x1ffff;
    Index = (Address >> 2) & 0x1fff;
    Offset = Address & 0x00000001;

    caches[Index].offset = Offset;
    caches[Index].tag = Tag;
    caches[Index].index = Index;
}

int CacheRead(uint32_t Address, uint32_t data)
{
    uint32_t Tag;
    uint32_t Index;
    uint32_t Offset;

    Tag = (Address >> 15) & 0x1ffff;
    Index = (Address >> 2) & 0x1fff;
    Offset = Address & 0x00000001;

    if(caches[Index].tag==Tag)
    {
        data = caches[Index].offset;
    }
    return data;
}