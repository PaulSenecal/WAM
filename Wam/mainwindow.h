#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QMessageBox>
#include <QStandardItemModel>
#include <QSqlTableModel>

#include "addwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase connectionDataBase();
    void display();
    void displaytableContent(QString);

private:
    Ui::MainWindow *ui;
    QSqlTableModel *tableModel;
    QSqlTableModel *weaponModel;
    addWindow * add;

private slots:
    void on_weaponButton_clicked();
    void on_equipmentButton_clicked();
    void on_ammunitionButton_clicked();
    void on_accessoriesButton_clicked();
    void on_consumableButton_clicked();
    void on_resetDataButton_clicked();
    void on_sendDataButton_clicked();
    void on_addMaterialButton_clicked();
};
#endif // MAINWINDOW_H
