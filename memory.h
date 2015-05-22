#ifndef MEMORY_H
#define MEMORY_H
#include "cache.h"


namespace memory
{

class Memory
{
public:
    Memory();
    ~Memory();

    template <typename KeyType, typename ValueType>
    Cache<KeyType, ValueType>& Page()
    {
        static uint id = ++type_id;

        Pages::iterator it = memory.find(id);
        if (it != memory.end())
        {
            return *static_cast<Cache<KeyType, ValueType> *>(it->second);
        }
        else
        {
            Cache<KeyType, ValueType> *ptr = new Cache<KeyType, ValueType>();
            memory.insert(PagesItem(id, ptr));
            return *ptr;
        }
    }

    void Reset();

private:
    typedef unsigned int uint;
    typedef CacheBase* CachePtr;
    typedef std::pair<const uint, CachePtr> PagesItem;
    typedef std::map<const uint, CachePtr> Pages;

    Pages memory;
    static uint type_id;
};

}

#endif // MEMORY_H
