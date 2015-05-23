#include "table.h"
#include <cstring>
namespace opc
{
Table::Table(const char* name)
{
    strncpy(this->name, name, 6);
}

Table::~Table()
{}

const char* Table::Name() const
{
    return name;
}
}
