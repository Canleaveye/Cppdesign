#include "widget.h"
#include "ui_widget.h"
#include "find.h"
#include <QTableWidget>
#include <QMessageBox>
#include <QFile>
#include <QDebug> //输出错误信息
#include <QTextStream>
#include <QStringList> //字符串数组
#include <memory>


//这里使用了单例的设计模式
StudentList stu_list;
QStringList fir;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //在初始化时候就把学生信息加载进来
    get_stu_info("D:\\Student\\StudentManagement\\res\\Student1.txt");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::show_sort_basic(int row,Stu_List* current)
{
    //调用API在表格里面加一行
    ui->Sort_Stu->insertRow(row);
    QTableWidgetItem* list1 = new QTableWidgetItem(current->stu->getid());
    //将链表里面的数据显示出来
    ui->Sort_Stu->setItem(row,0,list1);
    QTableWidgetItem* list2 = new QTableWidgetItem(current->stu->getname());
    ui->Sort_Stu->setItem(row,1,list2);
    QTableWidgetItem* list3 = new QTableWidgetItem(current->stu->getsex());
    ui->Sort_Stu->setItem(row,2,list3);
    QTableWidgetItem* list4 = new QTableWidgetItem(current->stu->getfolk());
    ui->Sort_Stu->setItem(row,3,list4);
    QTableWidgetItem* list5 = new QTableWidgetItem(QString::number(current->stu->getage()));
    ui->Sort_Stu->setItem(row,4,list5);
    QTableWidgetItem* list6 = new QTableWidgetItem(current->stu->getaddr());
    ui->Sort_Stu->setItem(row,5,list6);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    //退出该页就回去原来的页面
    if(event->key() == Qt::Key_Escape)
    {
        ui->stackedWidget->setCurrentWidget(ui->Menu);
    }
}

void Widget::get_stu_info(const QString& stufile)
{
    //创建文件对象
    QFile stuf(stufile);
    //先判断文件是否成功打开
    if(!stuf.open(QIODevice::ReadOnly))
    {
        qInfo() << "抱歉，由于某些原因，无法读取学生信息" << endl;
        QMessageBox::information(nullptr,"出错了","抱歉，由于某些原因，无法读取学生信息,您可以尝试重启");
        return ;
    }
    QTextStream text(&stuf);
    fir = text.readLine().split("\t",QString::SplitBehavior::SkipEmptyParts); //表头

    while(!text.atEnd())
    {
        //获取文件数据
        QStringList stu1 = text.readLine().split("\t",QString::SplitBehavior::SkipEmptyParts);
        //将这些先存储起来
        Student* temp = new Student;
        temp->set_id(stu1[0]);
        temp->set_name(stu1[1]);
        temp->set_sex(stu1[2]);
        temp->set_folk(stu1[3]);
        temp->set_age(stu1[4].toInt());
        temp->set_addr(stu1[5]);
        temp->set_oop(stu1[7].toDouble());
        temp->set_oopds(stu1[8].toDouble());
        temp->set_math(stu1[9].toDouble());
        temp->set_al(stu1[10].toDouble());
        temp->set_phy(stu1[11].toDouble());
        temp->set_eg(stu1[12].toDouble());
        temp->count_gpa();
        //存储到链表里面
        stu_list.add_node(temp);
        //调试使用，现在不用了
//        stu_list.display();
    }
}

void Widget::save_to_file(const QString &stufile)
{
    // 创建文件对象
    QFile stuf(stufile);
    // 先判断文件是否成功打开
    if (!stuf.open(QIODevice::WriteOnly | QIODevice::Text))
    {
    qInfo() << "抱歉，目前无法保存学生信息，您可以重启试试" << endl;
    QMessageBox::information(nullptr, "出错了", "抱歉，目前无法保存学生信息，您可以重启试试");
    return;
    }

    QTextStream out(&stuf);

    // 写入表头
    for (int i = 0; i < fir.size(); ++i)
    {
        out << fir[i];
        if (i != fir.size() - 1)
        {
            out << "\t";
        }
    }
    out << "\n";

    // 遍历链表并写入学生信息
    Stu_List* current = stu_list.getHead();
    while (current != nullptr)
    {
        Student* student = current->stu;
        out << student->getid() << "\t";
        out << student->getname() << "\t";
        out << student->getsex() << "\t";
        out << student->getfolk() << "\t";
        out << student->getage() << "\t";
        out << student->getaddr() << "\t";
        out << student->getgpa() << "\t";
        out << student->getoop() << "\t";
        out << student->getoopds() << "\t";
        out << student->getmath() << "\t";
        out << student->getal() << "\t";
        out << student->getphy() << "\t";
        out << student->geteg() << "\n";

        current = current->next;
    }

    stuf.close();
    qInfo() << "学生信息已成功保存到文件" << endl;
}




void Widget::on_Listbtn_released()
{
    //调用API跳转到基础功能页面
    ui->stackedWidget->setCurrentWidget(ui->basicpage);
    //先清空表格
    ui->Stu_Info->clear();
    ui->Stu_Info->setRowCount(0);
    ui->Stu_Info->setColumnCount(0);
    //设置将所有数据显示上去
    ui->Stu_Info->setColumnCount(fir.size());
    ui->Stu_Info->setHorizontalHeaderLabels(fir);
    Stu_List* current = stu_list.getHead();
    for(int i = 0;i < stu_list.getLength();i++)
    {
        int row = ui->Stu_Info->rowCount();
        //调用API在表格里面加一行
        ui->Stu_Info->insertRow(row);
        QTableWidgetItem* list1 = new QTableWidgetItem(current->stu->getid());
        //将链表里面的数据显示出来
        ui->Stu_Info->setItem(row,0,list1);
        QTableWidgetItem* list2 = new QTableWidgetItem(current->stu->getname());
        ui->Stu_Info->setItem(row,1,list2);
        QTableWidgetItem* list3 = new QTableWidgetItem(current->stu->getsex());
        ui->Stu_Info->setItem(row,2,list3);
        QTableWidgetItem* list4 = new QTableWidgetItem(current->stu->getfolk());
        ui->Stu_Info->setItem(row,3,list4);
        QTableWidgetItem* list5 = new QTableWidgetItem(QString::number(current->stu->getage()));
        ui->Stu_Info->setItem(row,4,list5);
        QTableWidgetItem* list6 = new QTableWidgetItem(current->stu->getaddr());
        ui->Stu_Info->setItem(row,5,list6);
        QTableWidgetItem* list7 = new QTableWidgetItem(QString::number(current->stu->getgpa()));
        ui->Stu_Info->setItem(row,6,list7);
        QTableWidgetItem* list8 = new QTableWidgetItem(QString::number(current->stu->getoop()));
        ui->Stu_Info->setItem(row,7,list8);
        QTableWidgetItem* list9 = new QTableWidgetItem(QString::number(current->stu->getoopds()));
        ui->Stu_Info->setItem(row,8,list9);
        QTableWidgetItem* list10 = new QTableWidgetItem(QString::number(current->stu->getmath()));
        ui->Stu_Info->setItem(row,9,list10);
        QTableWidgetItem* list11 = new QTableWidgetItem(QString::number(current->stu->getal()));
        ui->Stu_Info->setItem(row,10,list11);
        QTableWidgetItem* list12 = new QTableWidgetItem(QString::number(current->stu->getphy()));
        ui->Stu_Info->setItem(row,11,list12);
        QTableWidgetItem* list13 = new QTableWidgetItem(QString::number(current->stu->geteg()));
        ui->Stu_Info->setItem(row,12,list13);
        current = current->next;
    }
}

void Widget::on_Findbtn_released()
{
    //跳转到查询页面
    ui->stackedWidget->setCurrentWidget(ui->Searchpage);
}

void Widget::on_Sortbtn_released()
{
    //跳转到排序页面
    ui->stackedWidget->setCurrentWidget(ui->Sortpage);
}

void Widget::on_Exitbtn_released()
{
    //退出学生管理系统
    close();
}


void Widget::on_add_stubtn_released()
{
    //先添加一行
    int row = ui->Stu_Info->rowCount();
    ui->Stu_Info->insertRow(row);
    //跳转到最后一行
    ui->Stu_Info->scrollToBottom();
    //添加一个学生
    Student* temp = new Student;
    stu_list.add_node(temp);
}


//重写关闭事件，防止误触
void Widget::closeEvent(QCloseEvent *event)
{
    // 创建并显示确认对话框
    QMessageBox::StandardButton reply = QMessageBox::question(this, "确认退出","您确定要退出吗", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes)
        {
            // 用户确认退出，接受关闭事件
            event->accept();
        }
        else
        {
            // 用户取消退出，忽略关闭事件
            event->ignore();
        }
}




void Widget::on_save_allbtn_released()
{
    Stu_List* current = stu_list.getHead();
    //遍历页面上的所有数据，把他们都重新保存到链表里面去
    for(int i = 0;i < ui->Stu_Info->rowCount();i++)
    {
        current->stu->set_id(ui->Stu_Info->item(i,0)->text());
        current->stu->set_name(ui->Stu_Info->item(i,1)->text());
        current->stu->set_sex(ui->Stu_Info->item(i,2)->text());
        current->stu->set_folk(ui->Stu_Info->item(i,3)->text());
        current->stu->set_age(ui->Stu_Info->item(i,4)->text().toDouble());
        current->stu->set_addr(ui->Stu_Info->item(i,5)->text());
        current->stu->set_gpa(ui->Stu_Info->item(i,6)->text().toDouble());
        current->stu->set_oop(ui->Stu_Info->item(i,7)->text().toDouble());
        current->stu->set_oopds(ui->Stu_Info->item(i,8)->text().toDouble());
        current->stu->set_math(ui->Stu_Info->item(i,9)->text().toDouble());
        current->stu->set_al(ui->Stu_Info->item(i,10)->text().toDouble());
        current->stu->set_phy(ui->Stu_Info->item(i,11)->text().toDouble());
        current->stu->set_eg(ui->Stu_Info->item(i,12)->text().toDouble());
        current = current->next;
    }
    if(current != nullptr)
    {
        Stu_List* current2 = current->next;
        stu_list.delete_node(current->stu);
        current = current2;
    }
    QMessageBox::information(nullptr,"提示","保存成功!");
    save_to_file("D:\\Student\\StudentManagement\\res\\Student1.txt");
}

//删除学生
void Widget::on_delete_stubtn_released()
{
    int row = ui->Stu_Info->currentRow();
    QMessageBox::StandardButton tip = QMessageBox::question(nullptr,"操作确认","确定要删除该学生吗?",QMessageBox::Yes|QMessageBox::No);
    if(tip == QMessageBox::Yes)
    {
        ui->Stu_Info->removeRow(row);
    }
    else
    {
        return ;
    }

}



void Widget::on_gpa_sortbtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Sortgpapage);
    //先对学生的总绩点进行排序
    GpaSort gpasort;
    stu_list.setSortStrategy(&gpasort);
    stu_list.sort();
    //先清空表格
    ui->Sort_Stu->clear();
    ui->Sort_Stu->setRowCount(0);
    ui->Sort_Stu->setColumnCount(0);
    //设置将所有数据显示上去
    ui->Sort_Stu->setColumnCount(fir.size()-6);

    ui->Sort_Stu->setHorizontalHeaderLabels(fir);
    Stu_List* current = stu_list.getHead();
    for(int i = 0;i < stu_list.getLength();i++)
    {
        int row = ui->Sort_Stu->rowCount();
        //调用API在表格里面加一行
        show_sort_basic(row,current);
        QTableWidgetItem* list7 = new QTableWidgetItem(QString::number(current->stu->getgpa()));
        ui->Sort_Stu->setItem(row,6,list7);
        current = current->next;
    }
}


void Widget::on_math_gpabtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Sortgpapage);
    //先对学生的高数绩点进行排序
    MathgpaSort gpasort;
    stu_list.setSortStrategy(&gpasort);
    stu_list.sort();
    //先清空表格
    ui->Sort_Stu->clear();
    ui->Sort_Stu->setRowCount(0);
    ui->Sort_Stu->setColumnCount(0);
    //获取里面前几个元素
    QStringList elements = fir.mid(0,6);
    elements.append(fir.at(9));
    //设置将所有数据显示上去
    ui->Sort_Stu->setColumnCount(elements.size());
    ui->Sort_Stu->setHorizontalHeaderLabels(elements);
    Stu_List* current = stu_list.getHead();
    for(int i = 0;i < stu_list.getLength();i++)
    {
        int row = ui->Stu_Info->rowCount();
        show_sort_basic(row,current);
        QTableWidgetItem* list7 = new QTableWidgetItem(QString::number(current->stu->getmath()));
        ui->Sort_Stu->setItem(row,6,list7);
        current = current->next;
    }
}

void Widget::on_al_sortbtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Sortgpapage);
    //先对学生的线代绩点进行排序
    AlgpaSort gpasort;
    stu_list.setSortStrategy(&gpasort);
    stu_list.sort();
    //先清空表格
    ui->Sort_Stu->clear();
    ui->Sort_Stu->setRowCount(0);
    ui->Sort_Stu->setColumnCount(0);
    //获取里面前几个元素
    QStringList elements = fir.mid(0,6);
    elements.append(fir.at(10));
    //设置将所有数据显示上去
    ui->Sort_Stu->setColumnCount(elements.size());
    ui->Sort_Stu->setHorizontalHeaderLabels(elements);
    Stu_List* current = stu_list.getHead();
    for(int i = 0;i < stu_list.getLength();i++)
    {
        int row = ui->Stu_Info->rowCount();
        show_sort_basic(row,current);
        QTableWidgetItem* list7 = new QTableWidgetItem(QString::number(current->stu->getal()));
        ui->Sort_Stu->setItem(row,6,list7);
        current = current->next;
    }
}



void Widget::on_oop_gpabtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Sortgpapage);
    //先对学生的面向对象程序设计绩点进行排序
    oopgpaSort gpasort;
    stu_list.setSortStrategy(&gpasort);
    stu_list.sort();
    //先清空表格
    ui->Sort_Stu->clear();
    ui->Sort_Stu->setRowCount(0);
    ui->Sort_Stu->setColumnCount(0);
    //获取里面前几个元素
    QStringList elements = fir.mid(0,7);
    //设置将所有数据显示上去
    ui->Sort_Stu->setColumnCount(elements.size());
    ui->Sort_Stu->setHorizontalHeaderLabels(elements);
    Stu_List* current = stu_list.getHead();
    for(int i = 0;i < stu_list.getLength();i++)
    {
        int row = ui->Stu_Info->rowCount();
        show_sort_basic(row,current);
        QTableWidgetItem* list7 = new QTableWidgetItem(QString::number(current->stu->getoop()));
        ui->Sort_Stu->setItem(row,6,list7);
        current = current->next;
    }
}


void Widget::on_oopds_sortbtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Sortgpapage);
    //先对学生的面向对象课设绩点进行排序
    oopdsgpaSort gpasort;
    stu_list.setSortStrategy(&gpasort);
    stu_list.sort();
    //先清空表格
    ui->Sort_Stu->clear();
    ui->Sort_Stu->setRowCount(0);
    ui->Sort_Stu->setColumnCount(0);
    //获取里面前几个元素
    QStringList elements = fir.mid(0,6);
    elements.append(fir.at(8));
    //设置将所有数据显示上去
    ui->Sort_Stu->setColumnCount(elements.size());
    ui->Sort_Stu->setHorizontalHeaderLabels(elements);
    Stu_List* current = stu_list.getHead();
    for(int i = 0;i < stu_list.getLength();i++)
    {
        int row = ui->Stu_Info->rowCount();
        show_sort_basic(row,current);
        QTableWidgetItem* list7 = new QTableWidgetItem(QString::number(current->stu->getoopds()));
        ui->Sort_Stu->setItem(row,6,list7);
        current = current->next;
    }
}

void Widget::on_phy_gpabtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Sortgpapage);
    phygpaSort gpasort;
    stu_list.setSortStrategy(&gpasort);
    stu_list.sort();
    //先清空表格
    ui->Sort_Stu->clear();
    ui->Sort_Stu->setRowCount(0);
    ui->Sort_Stu->setColumnCount(0);
    //获取里面前几个元素
    QStringList elements = fir.mid(0,6);
    elements.append(fir.at(11));
    //设置将所有数据显示上去
    ui->Sort_Stu->setColumnCount(elements.size());
    ui->Sort_Stu->setHorizontalHeaderLabels(elements);
    Stu_List* current = stu_list.getHead();
    for(int i = 0;i < stu_list.getLength();i++)
    {
        int row = ui->Stu_Info->rowCount();
        show_sort_basic(row,current);
        QTableWidgetItem* list7 = new QTableWidgetItem(QString::number(current->stu->getphy()));
        ui->Sort_Stu->setItem(row,6,list7);
        current = current->next;
    }
}

void Widget::on_eg_gpabtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Sortgpapage);
    eggpaSort gpasort;
    stu_list.setSortStrategy(&gpasort);
    stu_list.sort();
    //先清空表格
    ui->Sort_Stu->clear();
    ui->Sort_Stu->setRowCount(0);
    ui->Sort_Stu->setColumnCount(0);
    //获取里面前几个元素
    QStringList elements = fir.mid(0,6);
    elements.append(fir.at(12));
    //设置将所有数据显示上去
    ui->Sort_Stu->setColumnCount(elements.size());
    ui->Sort_Stu->setHorizontalHeaderLabels(elements);
    Stu_List* current = stu_list.getHead();
    for(int i = 0;i < stu_list.getLength();i++)
    {
        int row = ui->Stu_Info->rowCount();
        show_sort_basic(row,current);
        QTableWidgetItem* list7 = new QTableWidgetItem(QString::number(current->stu->geteg()));
        ui->Sort_Stu->setItem(row,6,list7);
        current = current->next;
    }
}



void Widget::on_findbtn_clicked()
{

    //获取QLineEdit控件中的内容
    QString key_word = ui->keyword->text();
    //调试用
//    qInfo() << key_word << endl;
    //1. 先获取选择查询的内容
    //在这里标记一下，0：学号 1：姓名 2：性别 3：民族 4：年龄 5：地址 6：面向对象 7：课设 8：高数 9：线代 10：大物 11：大英
    int sele = ui->comboBox->currentIndex();
    //调试用
//    qInfo() << sele << endl;
    //先清空表格
    ui->id_search->clear();
    ui->id_search->setRowCount(0);
    ui->id_search->setColumnCount(0);
    //先加入表头
    ui->id_search->setColumnCount(fir.size());
    ui->id_search->setHorizontalHeaderLabels(fir);


    //进行不同情况的排序
    switch(sele)
    {
    case 0:
    {
        find_id i;
        i.findStu(ui->id_search,key_word);
        break;
    }
    case 1:
    {
        find_name i1;
        i1.findStu(ui->id_search,key_word);
        break;
    }
    case 2:
    {
        find_sex i2;
        i2.findStu(ui->id_search,key_word);
        break;
    }
    case 3:
    {
        find_folk i3;
        i3.findStu(ui->id_search,key_word);
        break;
    }
    case 4:
    {
        find_age i4;
        i4.findStu(ui->id_search,key_word);
        break;
    }
    case 5:
    {
        find_addr i5;
        i5.findStu(ui->id_search,key_word);
        break;
    }
    case 6:
    {
        find_all i6;
        i6.findStu(ui->id_search,key_word);
        break;
    }
    case 7:
    {
        find_oop i7;
        i7.findStu(ui->id_search,key_word);
        break;
    }
    case 8:
    {
        find_oopds i8;
        i8.findStu(ui->id_search,key_word);
        break;
    }
    case 9:
    {
        find_math i9;
        i9.findStu(ui->id_search,key_word);
        break;
    }
    case 10:
    {
        find_al i10;
        i10.findStu(ui->id_search,key_word);
        break;
    }
    case 11:
    {
        find_phy i10;
        i10.findStu(ui->id_search,key_word);
    }
    case 12:
    {
        find_eg i10;
        i10.findStu(ui->id_search,key_word);
        break;
    }
    }

}


