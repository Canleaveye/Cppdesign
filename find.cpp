#include "find.h"
#include <QDebug>
extern StudentList stu_list;

find::find()
{

}

void find::display(QTableWidget *table,Stu_List* current)
{
    int row = table->rowCount();
    table->insertRow(row);
    QTableWidgetItem* list1 = new QTableWidgetItem(current->stu->getid());
    //将链表里面的数据显示出来
    table->setItem(row,0,list1);
    QTableWidgetItem* list2 = new QTableWidgetItem(current->stu->getname());
    table->setItem(row,1,list2);
    QTableWidgetItem* list3 = new QTableWidgetItem(current->stu->getsex());
    table->setItem(row,2,list3);
    QTableWidgetItem* list4 = new QTableWidgetItem(current->stu->getfolk());
    table->setItem(row,3,list4);
    QTableWidgetItem* list5 = new QTableWidgetItem(QString::number(current->stu->getage()));
    table->setItem(row,4,list5);
    QTableWidgetItem* list6 = new QTableWidgetItem(current->stu->getaddr());
    table->setItem(row,5,list6);
    QTableWidgetItem* list7 = new QTableWidgetItem(QString::number(current->stu->getgpa()));
    table->setItem(row,6,list7);
    QTableWidgetItem* list8 = new QTableWidgetItem(QString::number(current->stu->getoop()));
    table->setItem(row,7,list8);
    QTableWidgetItem* list9 = new QTableWidgetItem(QString::number(current->stu->getoopds()));
    table->setItem(row,8,list9);
    QTableWidgetItem* list10 = new QTableWidgetItem(QString::number(current->stu->getmath()));
    table->setItem(row,9,list10);
    QTableWidgetItem* list11 = new QTableWidgetItem(QString::number(current->stu->getal()));
    table->setItem(row,10,list11);
    QTableWidgetItem* list12 = new QTableWidgetItem(QString::number(current->stu->getphy()));
    table->setItem(row,11,list12);
    QTableWidgetItem* list13 = new QTableWidgetItem(QString::number(current->stu->geteg()));
    table->setItem(row,12,list13);
}

//查询学生学号
void find_id::findStu(QTableWidget* table,QString key_word)
{
    Stu_List* current = stu_list.getHead();
    while(current!=nullptr)
    {
        if(current->stu->getid().contains(key_word))
        {
            this->display(table,current);
        }
        current = current->next;
    }
}



void find_name::findStu(QTableWidget *table, QString key_word)
{
    Stu_List* current = stu_list.getHead();
    while(current!=nullptr)
    {
        if(current->stu->getname().contains(key_word))
        {
            this->display(table,current);
        }
        current = current->next;
    }
}

void find_sex::findStu(QTableWidget *table, QString key_word)
{
    Stu_List* current = stu_list.getHead();
    while(current!=nullptr)
    {
        if(current->stu->getsex().contains(key_word))
        {
            this->display(table,current);
        }
        current = current->next;
    }
}


void find_folk::findStu(QTableWidget *table, QString key_word)
{
    Stu_List* current = stu_list.getHead();
    while(current!=nullptr)
    {
        if(current->stu->getfolk().contains(key_word))
        {
            this->display(table,current);
        }
        current = current->next;
    }
}


void find_age::findStu(QTableWidget *table, QString key_word)
{
    Stu_List* current = stu_list.getHead();
    while(current!=nullptr)
    {
        if(current->stu->getage() == key_word.toInt())
        {
            this->display(table,current);
        }
        current = current->next;
    }
}

void find_addr::findStu(QTableWidget *table, QString key_word)
{
    Stu_List* current = stu_list.getHead();
    while(current!=nullptr)
    {
        if(current->stu->getaddr().contains(key_word))
        {
            this->display(table,current);
        }
        current = current->next;
    }
}

void find_oop::findStu(QTableWidget *table, QString key_word)
{
    Stu_List* current = stu_list.getHead();
    while(current!=nullptr)
    {
        if(current->stu->getoop() == key_word.toDouble())
        {
            this->display(table,current);
        }
        current = current->next;
    }
}

void find_all::findStu(QTableWidget *table, QString key_word)
{
    Stu_List* current = stu_list.getHead();
    while(current!=nullptr)
    {
        if(current->stu->getgpa() == key_word.toDouble())
        {
            this->display(table,current);
        }
        current = current->next;
    }
}

void find_oopds::findStu(QTableWidget *table, QString key_word)
{
    Stu_List* current = stu_list.getHead();
    while(current!=nullptr)
    {
        if(current->stu->getoopds() == key_word.toDouble())
        {
            this->display(table,current);
        }
        current = current->next;
    }
}

void find_math::findStu(QTableWidget *table, QString key_word)
{
    Stu_List* current = stu_list.getHead();
    while(current!=nullptr)
    {
        if(current->stu->getmath() == key_word.toDouble())
        {
            this->display(table,current);
        }
        current = current->next;
    }
}

void find_al::findStu(QTableWidget *table, QString key_word)
{
    Stu_List* current = stu_list.getHead();
    while(current!=nullptr)
    {
        if(current->stu->getal() == key_word.toDouble())
        {
            this->display(table,current);
        }
        current = current->next;
    }
}

void find_phy::findStu(QTableWidget *table, QString key_word)
{
    Stu_List* current = stu_list.getHead();
    while(current!=nullptr)
    {
        if(current->stu->getphy() == key_word.toDouble())
        {
            this->display(table,current);
        }
        current = current->next;
    }
}

void find_eg::findStu(QTableWidget *table, QString key_word)
{
    Stu_List* current = stu_list.getHead();
    while(current!=nullptr)
    {
        if(current->stu->geteg() == key_word.toDouble())
        {
            this->display(table,current);
        }
        current = current->next;
    }
}
