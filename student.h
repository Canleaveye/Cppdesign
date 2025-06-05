#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include <memory> //使用智能指针


class Student
{
public:
    Student();
    //写一些函数接口来设置变量属性
    void set_id(QString id);
    void set_name(QString name);
    void set_sex(QString sex);
    void set_folk(QString folk);
    void set_age(int age);
    void set_addr(QString addr);
    void set_gpa(double gpa);
    void count_gpa();
    void set_math(double gpa);
    void set_oop(double gpa);
    void set_oopds(double gpa);
    void set_al(double gpa);
    void set_phy(double gpa);
    void set_eg(double gpa);
    QString getid();
    QString getname();
    QString getsex();
    QString getfolk();
    int getage();
    QString getaddr();
    double getgpa();
    double getmath();
    double getoop();
    double getoopds();
    double getal();
    double getphy();
    double geteg();
    void display();

private:
    QString id;
    QString name;
    QString sex;
    QString folk;
    int age;
    QString addr;
    double gpa;
    double mathgpa;
    double oopgpa;
    double oopdsgpa;
    double algpa;
    double phygpa;
    double eggpa;

};

class Stu_List
{
public:
    Stu_List(Student* stu);
    Student* stu;
    Stu_List* next;
};


//使用策略模式对学生进行排序
//一个排序策略接口

class MySortStrategy
{
public:
    virtual void sort() = 0;
};

//具体排序策略类
//对总的Gpa进行排序
class GpaSort:virtual public MySortStrategy
{
public:
    void sort();
};

//对高数绩点进行排序
class MathgpaSort:virtual public MySortStrategy
{
public:
    void sort();
};

//对线代绩点进行排序
class AlgpaSort:virtual public MySortStrategy
{
public:
    void sort();
};

//对面向对象程序设计绩点进行排序
class oopgpaSort:virtual public MySortStrategy
{
public:
    void sort();
};

//对面向对象课设绩点进行排序
class oopdsgpaSort:virtual public MySortStrategy
{
public:
    void sort();
};

//对大物绩点进行排序
class phygpaSort:virtual public MySortStrategy
{
public:
    void sort();
};

//对大英绩点进行排序
class eggpaSort:virtual public MySortStrategy
{
public:
    void sort();
};

//学生链表
class StudentList
{
public:
    //构造函数
    StudentList();
    //获取头节点
    Stu_List* getHead();
    //添加节点
    void add_node(Student* node);
    //删除节点
    void delete_node(Student* node);
    //修改节点
    void change_node(Student* node);
    //展示整个链表
    void display();
    //计算链表的长度
    int getLength();
    void setSortStrategy(MySortStrategy* strategy);
    void sort();

private:
    Stu_List* head;
    MySortStrategy* strategy;
};










//智能指针版本
//class Stu_List
//{
//public:
//    std::shared_ptr<Student> stu;
//    std::shared_ptr<Stu_List> next;
//    Stu_List(const std::shared_ptr<Student>& stu);
//};

//学生链表
//class StudentList
//{
//public:
//    //构造函数
//    StudentList();

//    //添加节点
//    void add_node(const std::shared_ptr<Student>& node);
//    //删除节点
//    void delete_node(Student* node);
//    //修改节点
//    void change_node(Student* node);
//    //展示整个链表
//    void display();

//private:
//    std::shared_ptr<Stu_List> head;
//};

#endif // STUDENT_H
