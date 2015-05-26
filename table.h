#ifndef TABLE_H
#define TABLE_H

namespace opc
{
/*
Класс предназначен для компановки переменных в таблицы как в контроллере
его задача хранить имя таблицы и инициализировать поля на переменные
*/

/*
 * кроме всего прочего этот класс должен в себе содержать буфер с данными (массив предположительно vector и буфер строковых адресов)
*/

class Table
{
public:
    Table(const char* name);
    ~Table();
    const char* Name() const;

protected:
    const char *name;
};

}

#endif // TABLE_H
