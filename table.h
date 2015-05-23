#ifndef TABLE_H
#define TABLE_H

namespace opc
{
/*
����� ������������ ��� ���������� ���������� � ������� ��� � �����������
��� ������ ������� ��� ������� � ���������������� ���� �� ����������
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
