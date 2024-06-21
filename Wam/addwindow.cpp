#include "addwindow.h"
#include "ui_addwindow.h"

addWindow::addWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addWindow)
{
    ui->setupUi(this);
}

addWindow::~addWindow()
{
    delete ui;
}


QString addWindow::selectedCategory()
{
    QString selectedCategory = ui->selectedCategoryComboBox->currentText();
    ui->label->setText(selectedCategory);
    return selectedCategory;
}

void addWindow::displayCategory(int)
{

}

void addWindow::on_selectedCategoryComboBox_currentTextChanged(const QString &arg1)
{
    /*switch (selectedCategory()) {
    case "weapon":

        break;
    default:
        break;
    }*/
    selectedCategory();
}

