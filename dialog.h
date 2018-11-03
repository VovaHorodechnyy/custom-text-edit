#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QTextEdit>
#include<QString>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
     Dialog(QWidget *parent ,QTextEdit *textedit);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QTextEdit * m_pTextedit;
};

#endif // DIALOG_H
