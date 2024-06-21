#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QWidget>
#include <QString>

namespace Ui {
class addWindow;
}

class addWindow : public QWidget
{
    Q_OBJECT

public:
    explicit addWindow(QWidget *parent = nullptr);
    ~addWindow();
    QString selectedCategory();
    void displayCategory(int);

private slots:
    void on_selectedCategoryComboBox_currentTextChanged(const QString &arg1);

private:
    Ui::addWindow *ui;
};

#endif // ADDWINDOW_H
