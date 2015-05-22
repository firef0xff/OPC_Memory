#include "memory.h"

namespace memory
{
Memory::uint Memory::type_id = 0;
Memory::Memory()
{
}
Memory::~Memory()
{
}

void Memory::Reset()
{
    for (Pages::iterator it = memory.begin(), end = memory.end();
         it != end; ++it)
    {
        CacheBase *ptr = it->second;
        if (ptr)
            ptr->Reset();
    }
}

}
