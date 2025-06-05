#include "widget.h"

#include <QMessageBox>
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //改变窗口名字
    w.setWindowTitle("学生成绩管理系统");
    QIcon pho("D:\\Student\\StudentManagement\\res\\NEU2.png");
    w.setWindowIcon(pho);
    w.show();
    QMessageBox::information(nullptr, "欢迎您", "欢迎来到学生管理系统!");
    return a.exec();
}
