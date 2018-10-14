#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QRect availableGeometry = QApplication::desktop()->availableGeometry(ui->textEdit);
    ui->textEdit->setLineWrapColumnOrWidth(QTextEdit::LineWrapMode());
    auto &mw = ui->textEdit;
    mw->resize(availableGeometry.width() / 2, (availableGeometry.height() * 2) / 3);
    mw->move((availableGeometry.width() - mw->width()) / 2,
            (availableGeometry.height() - mw->height()) / 2);

//    ui->textEdit->verticalScrollBar()->setSliderPosition(
//    ui->textEdit->verticalScrollBar()->maximum());
//    QScrollBar *v = ui->textEdit->verticalScrollBar();
//    v->setValue(v->maximum());
    //QTextEdit::ensureCursorVisible();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    ui->textEdit->clear();
}

void MainWindow::on_action_Open_triggered()
{
    QFileDialog dialog(this);
    QStringList mimeTypeFilters;
    mimeTypeFilters << "image/jpeg" // will show "JPEG image (*.jpeg *.jpg *.jpe)
                << "image/png"  // will show "PNG image (*.png)"
                << "application/octet-stream"; // will show "All files (*)"
   dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml);;All files (*.*)"));
   // dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.exec();
}
