#ifndef CGOTOROW_H
#define CGOTOROW_H

#include <QDialog>
#include<QTextEdit>

namespace Ui {
class CGoToRow;
}

class CGoToRow : public QDialog
{
    Q_OBJECT

public:
    explicit CGoToRow(QWidget *parent = nullptr);
    CGoToRow(QWidget *parent = nullptr,QTextEdit * textarea = nullptr);
    ~CGoToRow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CGoToRow *ui;
    QTextEdit *m_pTextarea;


};

#endif // CGOTOROW_H
