#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include "student.h"
#include "find.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void show_sort_basic(int row,Stu_List* current);

    void keyPressEvent(QKeyEvent* event) override;

    void get_stu_info(const QString& stufile);
    void save_to_file(const QString& stufile);
private slots:

    void on_Listbtn_released();

    void on_Findbtn_released();

    void on_Sortbtn_released();

    void on_Exitbtn_released();

    void on_add_stubtn_released();

    void on_pushButton_released();

    void on_save_stubtn_released();

    void on_save_btn_released();

    void on_savestubtn_released();

    void on_save_allbtn_released();

    void on_delete_stubtn_released();

    void on_pushButton_clicked();

    void on_gpa_sortbtn_clicked();

    void on_math_gpabtn_clicked();

    void on_al_sortbtn_clicked();

    void on_oop_gpabtn_clicked();

    void on_oopds_sortbtn_clicked();

    void on_phy_gpabtn_clicked();

    void on_eg_gpabtn_clicked();

    void on_find_idbtn_clicked();

    void on_findbtn_clicked();

    void on_find_namebtn_clicked();

private:
    Ui::Widget *ui;
protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // WIDGET_H
