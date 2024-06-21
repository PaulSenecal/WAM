#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectionDataBase();
    displaytableContent("weapon");



}

MainWindow::~MainWindow()
{
    delete ui;
}

QSqlDatabase MainWindow::connectionDataBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Programmation/C++/WAM/wamDb.db");
    if (!db.open()) {
        QMessageBox::information(this, "Erreur de connection", "impossible de se connecter a la base de donnée , Veuillez contacter votre administrateur system");
        qDebug() << "Error:";
    }
    return db;
}


void MainWindow::displaytableContent(QString tableName)
{
    tableModel = new QSqlTableModel;
    tableModel->setTable(tableName);
    tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    tableModel->select();



    tableModel->setHeaderData(0, Qt::Horizontal, tr("status"));
    tableModel->setHeaderData(1, Qt::Horizontal, tr("type"));
    tableModel->setHeaderData(2, Qt::Horizontal, tr("quantité"));
    tableModel->setHeaderData(3, Qt::Horizontal, tr("marque"));
    tableModel->setHeaderData(4, Qt::Horizontal, tr("nom"));

      //ui->tableView->hideColumn(0);

    ui->tableView->setModel(tableModel);

}

void MainWindow::on_weaponButton_clicked()
{
    displaytableContent("weapon");
}


void MainWindow::on_equipmentButton_clicked()
{
    displaytableContent("equipement");
}


void MainWindow::on_ammunitionButton_clicked()
{
    displaytableContent("ammunition");
}


void MainWindow::on_accessoriesButton_clicked()
{
    displaytableContent("accessories");
}


void MainWindow::on_consumableButton_clicked()
{
    displaytableContent("consumable");
}

void MainWindow::on_resetDataButton_clicked()
{
    tableModel->revertAll();
}

void MainWindow::on_sendDataButton_clicked()
{
    if (tableModel->submitAll()) {
        QMessageBox::information(this, "Enregistrement", "Les modifications ont été enregistrées avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'enregistrement des modifications.");
    }
}

void MainWindow::on_addMaterialButton_clicked()
{
    add = new addWindow;
    add->show();
}
/*
void MainWindow::display()
{
    QSqlQuery query("SELECT * FROM weapon");
    if (query.exec()) {
        while (query.next()) {
            QString name = query.value("name").toString();
            qDebug() << " Name:" << name ;
        }
    } else {
        QSqlError error = query.lastError();
        qDebug() << "Error executing query:" << error.text();
    }
}

*/


