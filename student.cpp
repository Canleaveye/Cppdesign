#include "student.h"
#include <iostream>
#include <QDebug>
#include <QMessageBox>
using namespace std;
extern StudentList stu_list;

Student::Student()
{

}
void Student:: set_id(QString id)
{
    this->id = id;
}

void Student::set_name(QString name)
{
    this->name = name;
}

void Student::set_sex(QString sex)
{
    this->sex = sex;
}

void Student::set_folk(QString folk)
{
    this->folk = folk;
}
void Student::set_age(int age)
{
    this->age = age;
}
void Student::set_addr(QString addr)
{
    this->addr = addr;
}

void Student::set_gpa(double gpa)
{
    this->gpa = gpa;
}
void Student::count_gpa()
{
    this->gpa = (this->mathgpa + this->eggpa + this->oopgpa + this->oopdsgpa + this->phygpa + this->algpa)/6.0;
}

void Student::set_math(double gpa)
{
    this->mathgpa = gpa;
}
void Student::set_oop(double gpa)
{
    this->oopgpa = gpa;
}
void Student::set_oopds(double gpa)
{
    this->oopdsgpa = gpa;
}
void Student::set_al(double gpa)
{
    this->algpa = gpa;
}
void Student::set_phy(double gpa)
{
    this->phygpa = gpa;
}
void Student::set_eg(double gpa)
{
    this->eggpa = gpa;
}


//在控制台中展示链表信息，进行调试程序时使用
void Student::display()
{
    qInfo() << "学号: " << id << endl;
    qInfo() << "姓名: " << name << endl;
    qInfo() << "性别: " << sex << endl;
    qInfo() << "民族: " << folk << endl;
    qInfo() << "年龄：" << age << endl;
    qInfo() << "地址：" << addr << endl;
    qInfo() << "高数 GPA: " << mathgpa << endl;
    qInfo() << "大英 GPA: " << eggpa << endl;
    qInfo() << "面向对象程序设计 GPA: " << oopgpa << endl;
    qInfo() << "面向对象课设 GPA: " << oopdsgpa << endl;
    qInfo() << "大物 GPA: " << phygpa << endl;
    qInfo() << "线代 GPA: " << algpa << endl;
    qInfo() << "总的 GPA: " << gpa << endl;
}

QString Student::getid()
{
    return this->id;
}

QString Student::getname()
{
    return this->name;
}

QString Student::getsex()
{
    return this->sex;
}

QString Student::getfolk()
{
    return this->folk;
}

int Student::getage()
{
    return this->age;
}

QString Student::getaddr()
{
    return this->addr;
}


double Student::getgpa()
{
    return this->gpa;
}

double Student::getmath()
{
    return this->mathgpa;
}

double Student::getoop()
{
    return this->oopgpa;
}

double Student::getoopds()
{
    return this->oopdsgpa;
}

double Student::getal()
{
    return algpa;
}

double Student::getphy()
{
    return this->phygpa;
}

double Student::geteg()
{
    return this->eggpa;
}


Stu_List::Stu_List(Student *stu):stu(stu),next(nullptr)
{

}


StudentList::StudentList():head(nullptr)
{

}

Stu_List *StudentList::getHead()
{
    return this->head;
}


void StudentList::add_node(Student *node)
{
        //先判断是否是空链表
        if(this->head == nullptr)
        {
            //直接加入
            head = new Stu_List(node);
        }
        else
        {
            //使用尾插法
            auto temp = this->head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            auto node1 = new Stu_List(node);
            temp->next = node1;
        }
}

void StudentList::delete_node(Student* node)
{
    Stu_List* current = this->head;
    Stu_List* prev = nullptr;
    if(head == nullptr)
    {
        return ;
    }
    while(current != nullptr && current->stu->getid() != node->getid())
    {
        prev = current;
        current = current->next;
    }
    if(current == nullptr)
    {
        QMessageBox::warning(nullptr,"操作结果","未找到学号为 " + node->getid() + " 的学生！");
        return ;
    }
    else if(prev == nullptr)
    {
        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    delete current;
    qInfo() << "删除学号为: " << node->getid() << "的学生成功" << endl;
}

//void StudentList::delete_node(Student *node)
//{
//    if(this->head == nullptr)
//    {
//        qInfo() << "该链表为空链表，禁止进行删除操作" << endl;
//        return ;
//    }
//    Stu_List* temp = this->head;
//    while(temp->next != nullptr)
//    {
//        if(temp->stu)
//    }
//}

//展示整个链表
void StudentList::display()
{
    Stu_List* current = this->head;
    while(current != nullptr)
    {
        current->stu->display();
        current = current->next;
    }
}

int StudentList::getLength()
{
    Stu_List* current = this->head;
    int length = 0;
    while(current != nullptr)
    {
        length++;
        current = current->next;
    }
    return length;
}

void StudentList::setSortStrategy(MySortStrategy *strategy)
{
    this->strategy = strategy;
}

void StudentList::sort()
{
    if(this->strategy != nullptr)
    {
        strategy->sort();
    }
}


void GpaSort::sort()
{
    Stu_List* temp1 = nullptr;
    Stu_List* temp2 = nullptr;
    bool swapped;
    do
    {
        swapped = false;
        temp1 = stu_list.getHead();

        while(temp1->next != temp2)
        {
            if(temp1->stu->getgpa() < temp1->next->stu->getgpa())
            {
                Student* temp3 = temp1->stu;
                temp1->stu = temp1->next->stu;
                temp1->next->stu = temp3;
                swapped = true;
            }
            temp1 = temp1->next;
        }
        temp2 = temp1;
    }
    while(swapped);

}

void MathgpaSort::sort()
{
    Stu_List* temp1 = nullptr;
    Stu_List* temp2 = nullptr;
    bool swapped;
    do
    {
        swapped = false;
        temp1 = stu_list.getHead();

        while(temp1->next != temp2)
        {
            if(temp1->stu->getmath() > temp1->next->stu->getmath())
            {
                Student* temp3 = temp1->stu;
                temp1->stu = temp1->next->stu;
                temp1->next->stu = temp3;
                swapped = true;
            }
            temp1 = temp1->next;
        }
        temp2 = temp1;
    }
    while(swapped);

}

void AlgpaSort::sort()
{
    Stu_List* temp1 = nullptr;
    Stu_List* temp2 = nullptr;
    bool swapped;
    do
    {
        swapped = false;
        temp1 = stu_list.getHead();

        while(temp1->next != temp2)
        {
            if(temp1->stu->getal() > temp1->next->stu->getal())
            {
                Student* temp3 = temp1->stu;
                temp1->stu = temp1->next->stu;
                temp1->next->stu = temp3;
                swapped = true;
            }
            temp1 = temp1->next;
        }
        temp2 = temp1;
    }
    while(swapped);
}

void oopgpaSort::sort()
{
    Stu_List* temp1 = nullptr;
    Stu_List* temp2 = nullptr;
    bool swapped;
    do
    {
        swapped = false;
        temp1 = stu_list.getHead();

        while(temp1->next != temp2)
        {
            if(temp1->stu->getoop() > temp1->next->stu->getoop())
            {
                Student* temp3 = temp1->stu;
                temp1->stu = temp1->next->stu;
                temp1->next->stu = temp3;
                swapped = true;
            }
            temp1 = temp1->next;
        }
        temp2 = temp1;
    }
    while(swapped);
}

void oopdsgpaSort::sort()
{
    Stu_List* temp1 = nullptr;
    Stu_List* temp2 = nullptr;
    bool swapped;
    do
    {
        swapped = false;
        temp1 = stu_list.getHead();

        while(temp1->next != temp2)
        {
            if(temp1->stu->getoopds() > temp1->next->stu->getoopds())
            {
                Student* temp3 = temp1->stu;
                temp1->stu = temp1->next->stu;
                temp1->next->stu = temp3;
                swapped = true;
            }
            temp1 = temp1->next;
        }
        temp2 = temp1;
    }
    while(swapped);
}


void phygpaSort::sort()
{
    Stu_List* temp1 = nullptr;
    Stu_List* temp2 = nullptr;
    bool swapped;
    do
    {
        swapped = false;
        temp1 = stu_list.getHead();

        while(temp1->next != temp2)
        {
            if(temp1->stu->getphy() > temp1->next->stu->getphy())
            {
                Student* temp3 = temp1->stu;
                temp1->stu = temp1->next->stu;
                temp1->next->stu = temp3;
                swapped = true;
            }
            temp1 = temp1->next;
        }
        temp2 = temp1;
    }
    while(swapped);
}


void eggpaSort::sort()
{
    Stu_List* temp1 = nullptr;
    Stu_List* temp2 = nullptr;
    bool swapped;
    do
    {
        swapped = false;
        temp1 = stu_list.getHead();

        while(temp1->next != temp2)
        {
            if(temp1->stu->geteg() > temp1->next->stu->geteg())
            {
                Student* temp3 = temp1->stu;
                temp1->stu = temp1->next->stu;
                temp1->next->stu = temp3;
                swapped = true;
            }
            temp1 = temp1->next;
        }
        temp2 = temp1;
    }
    while(swapped);
}
//Stu_List::Stu_List(const std::shared_ptr<Student> &stu):stu(stu),next(nullptr)
//{

//}


//StudentList::StudentList():head(nullptr)
//{
//}



//智能指针版本有点问题，先不用了
//加节点
//void StudentList::add_node(const std::shared_ptr<Student>& node)
//{
//    //先判断是否是空链表
//    if(this->head == nullptr)
//    {
//        head = std::make_shared<Stu_List>(node);
//    }
//    else
//    {
//        //使用尾插法
//        auto temp = this->head;
//        while(temp->next != nullptr)
//        {
//            temp = temp->next;
//        }
//        auto node1 = std::make_shared<Stu_List>(node);
//        temp->next = node1;
//    }
//}










