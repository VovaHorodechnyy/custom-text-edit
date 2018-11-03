#include "cgotorow.h"
#include "ui_cgotorow.h"

CGoToRow::CGoToRow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CGoToRow)
{
    ui->setupUi(this);
}

CGoToRow::~CGoToRow()
{
    delete ui;
}

CGoToRow::CGoToRow(QWidget *parent ,QTextEdit *cursor):
     QDialog(parent),
     ui(new Ui::CGoToRow),
   m_pTextarea(cursor)
{
     ui->setupUi(this);
}

void CGoToRow::on_pushButton_clicked()
{
    size_t row = ui->lineEdit->text().toInt();

    m_pTextarea->moveCursor(QTextCursor::Start);

    for( size_t ix = 1 ; ix < row ; ++ix )
    {
        m_pTextarea->moveCursor(QTextCursor::Down);
    }
}
