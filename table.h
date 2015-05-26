#ifndef TABLE_H
#define TABLE_H

namespace opc
{
/*
����� ������������ ��� ���������� ���������� � ������� ��� � �����������
��� ������ ������� ��� ������� � ���������������� ���� �� ����������
*/

/*
 * ����� ����� ������� ���� ����� ������ � ���� ��������� ����� � ������� (������ ���������������� vector � ����� ��������� �������)
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
