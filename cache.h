#ifndef CACHE_H
#define CACHE_H
#include <map>
#include <list>
#include <auto_ptr.h>
/*
Нужно создать типонезависимый кеш,
для получения значения нужно указать адресс(ключ),
значение может иметь любой тип

нужна функция для сброса кэша
*/

namespace memory
{

class CacheBase
{
public:
    CacheBase()
    {}
    virtual ~CacheBase()
    {}
    virtual void Reset() = 0;
};

template <typename KeyType, typename ValueType>
class Cache : public CacheBase
{
public:
    Cache()
    {
    }
    ~Cache()
    {
    }
    void Reset()
    {
        data.clear();
    }
    void Write(const KeyType &addr, const ValueType &data)
    {
        this->data[addr] = data;
    }

    const ValueType& Read(const KeyType &addr)
    {
        return this->data[addr];
    }
protected:
    typedef std::pair<const KeyType, ValueType> DataItem;
    typedef std::map<const KeyType, ValueType> Data;

    Data data;
};

}

#endif // CACHE_H

