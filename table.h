#ifndef TABLE_H
#define TABLE_H

namespace opc
{
/*
Класс предназначен для компановки переменных в таблицы как в контроллере
его задача хранить имя таблицы и инициализировать поля на переменные
*/
class Table
{
public:
    Table(const char* name);
    ~Table();
    const char* Name() const;

protected:
    char name[7] = {0};
};

}

#endif // TABLE_H
