
#ifndef COMPORGPROJECT_CACHE
#define COMPORGPROJECT_CACHE

/* Cache Sizes (in words) */
#define CACHE_SIZE 7500
#define BLOCK_SIZE 1
#define numBLOCK 7500

struct cache
{
    uint32_t addr;
    uint32_t tag;
    uint32_t index;
    uint32_t offset;

};
void InitializeCache();
void CacheWrite(uint32_t Address);
int CacheRead(uint32_t Address, uint32_t data);
#endif