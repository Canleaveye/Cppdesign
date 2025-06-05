#ifndef FIND_H
#define FIND_H
#include "student.h"
#include <QTableWidget>
#include <QTableWidgetItem>

//学生信息查询类
class find
{
public:
    find();
    virtual void findStu(QTableWidget* table,QString key_word) = 0;
    void display(QTableWidget *table,Stu_List* current);
};

class find_id:public find
{
public:
    void findStu(QTableWidget *table,QString key_word) override;
};

class find_name:public find
{
public:
    void findStu(QTableWidget* table,QString key_word) override;
};

class find_sex:public find
{
public:
    void findStu(QTableWidget* table,QString key_word) override;
};

class find_folk:public find
{
public:
    void findStu(QTableWidget* table,QString key_word) override;
};

class find_age:public find
{
public:
    void findStu(QTableWidget* table,QString key_word) override;
};

class find_addr:public find
{
public:
    void findStu(QTableWidget* table,QString key_word) override;
};

class find_all:public find
{
public:
    void findStu(QTableWidget* table,QString key_word) override;
};

class find_oop:public find
{
public:
    void findStu(QTableWidget* table,QString key_word) override;
};

class find_oopds:public find
{
public:
    void findStu(QTableWidget* table,QString key_word) override;
};

class find_math:public find
{
public:
    void findStu(QTableWidget* table,QString key_word) override;
};

class find_al:public find
{
public:
    void findStu(QTableWidget* table,QString key_word) override;
};

class find_phy:public find
{
public:
    void findStu(QTableWidget* table,QString key_word) override;
};

class find_eg:public find
{
public:
    void findStu(QTableWidget* table,QString key_word) override;
};
#endif // FIND_H
