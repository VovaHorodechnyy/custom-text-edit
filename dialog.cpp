#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //this->setFixedSize()
    setMinimumSize(200,200);
    m_pTextedit->moveCursor(QTextCursor::Start);
}

Dialog::Dialog(QWidget *parent ,QTextEdit *textedit) :
    QDialog (parent),ui(new Ui::Dialog),m_pTextedit(textedit)
{
        ui->setupUi(this);


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    QList<QTextEdit::ExtraSelection> extraSelections;

    m_pTextedit->textCursor().beginEditBlock();

        if(!m_pTextedit->isReadOnly())
        {

            QColor color = QColor(Qt::red).lighter(130);

           if(ui->checkBox->isChecked())
           {
               while(m_pTextedit->find(str))
                {
                    QTextEdit::ExtraSelection extra;
                    extra.format.setForeground(color);

                    extra.cursor =  m_pTextedit->textCursor();
                    extraSelections.append(extra);
                }
           }
           else
           {
               if(m_pTextedit->find(str))
                {
                    QTextEdit::ExtraSelection extra;
                    extra.format.setForeground(color);

                    extra.cursor =  m_pTextedit->textCursor();
                    extraSelections.append(extra);
                }
           }

        }

        m_pTextedit->setExtraSelections(extraSelections);
        m_pTextedit->textCursor().endEditBlock();

}
