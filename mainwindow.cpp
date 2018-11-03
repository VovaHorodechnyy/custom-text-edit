#include "mainwindow.h"
#include "ui_mainwindow.h"




#ifdef Q_OS_MAC
const QString rsrcPath = ":/images/mac";
#else
const QString rsrcPath = ":/images/win";
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_sPathLastFile="new text file.txt";
    this->setWindowTitle("new text file.txt");
//    ui->textEdit->verticalScrollBar()->setSliderPosition(
//    ui->textEdit->verticalScrollBar()->maximum());
//    QScrollBar *v = ui->textEdit->verticalScrollBar();
//    v->setValue(v->maximum());
    //QTextEdit::ensureCursorVisible();
    const QIcon iconNew = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
    ui->actionNew->setIcon(iconNew);

    const QIcon iconOpen = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/fileopen.png"));
    ui->actionOpen->setIcon(iconOpen);

    const QIcon iconSave = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filesave.png"));
    ui->actionSave->setIcon(iconSave);

    const QIcon iconcopy = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/editcopy.png"));
    ui->actionCopy->setIcon(iconcopy);

    const QIcon iconcut = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/editcut.png"));
    ui->actionCut->setIcon(iconcut);

    const QIcon iconRedo = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/editredo.png"));
    ui->actionRedo->setIcon(iconRedo);

    const QIcon iconUndo = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/editundo.png"));
    ui->actionUndo->setIcon(iconUndo);

    const QIcon iconPaste = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/editpaste.png"));
    ui->actionPaste->setIcon(iconPaste);

    const QIcon iconPrint = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/editpaste.png"));
    ui->actionPrint_Preview->setIcon(iconPrint);
    ui->actionPrint->setIcon(iconPrint);

    const QIcon iconFind = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/editsearch.png"));
    ui->actionFind->setIcon(iconFind);

    const QIcon iconExport = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/exportpdf.png"));
    ui->actionExport_PDF->setIcon(iconExport);

    const QIcon iconBold = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/textbold.png"));
    QFont fontBold;
    fontBold.setBold(true);
    ui->actionBold->setFont(fontBold);
    ui->actionBold->setIcon(iconBold);
    ui->actionBold->setCheckable(true);

    const QIcon iconItalic = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/textitalic.png"));
    ui->actionItalic->setPriority(QAction::LowPriority);
    ui->actionItalic->setShortcut(Qt::CTRL + Qt::Key_I);
    QFont italic;
    italic.setItalic(true);
    ui->actionItalic->setFont(italic);
    ui->actionItalic->setIcon(iconItalic);
    ui->actionItalic->setCheckable(true);

    const QIcon iconUnderline = QIcon::fromTheme("format-text-underline", QIcon(rsrcPath + "/textunder.png"));
    ui->actionUnderline->setPriority(QAction::LowPriority);
    QFont underline;
    underline.setUnderline(true);
    ui->actionUnderline->setFont(underline);
    ui->actionUnderline->setCheckable(true);
    ui->actionUnderline->setIcon(iconUnderline);

    const QIcon iconLeft = QIcon::fromTheme("format-justify-left", QIcon(rsrcPath + "/textleft.png"));
    ui->actionLeft->setIcon(iconLeft);
    ui->actionLeft->setCheckable(true);
    ui->actionLeft->setPriority(QAction::LowPriority);

    const QIcon iconCenter = QIcon::fromTheme("format-justify-center", QIcon(rsrcPath + "/textcenter.png"));
    ui->actionCenter->setIcon(iconCenter);
    ui->actionCenter->setCheckable(true);
    ui->actionCenter->setPriority(QAction::LowPriority);

    const QIcon iconRight = QIcon::fromTheme("format-justify-right", QIcon(rsrcPath + "/textright.png"));
    ui->actionRight->setIcon(iconRight);
    ui->actionRight->setCheckable(true);
    ui->actionRight->setPriority(QAction::LowPriority);

    const QIcon iconJustify = QIcon::fromTheme("format-justify-fill", QIcon(rsrcPath + "/textjustify.png"));
    ui->actionJustify->setIcon(iconJustify);
    ui->actionJustify->setIcon(iconJustify);
    ui->actionJustify->setCheckable(true);
    ui->actionJustify->setPriority(QAction::LowPriority);

    QActionGroup *alignGroup = new QActionGroup(this);
    connect(alignGroup, &QActionGroup::triggered, this, &MainWindow::textAlign);

    if (QApplication::isLeftToRight()) {
        alignGroup->addAction(ui->actionLeft);
        alignGroup->addAction(ui->actionCenter);
        alignGroup->addAction(ui->actionRight);
    } else {
        alignGroup->addAction(ui->actionRight);
        alignGroup->addAction(ui->actionCenter);
        alignGroup->addAction(ui->actionLeft);
    }
    alignGroup->addAction(ui->actionJustify);

    QPixmap pix(16, 16);
    pix.fill(Qt::black);
    ui->actionColor->setIcon(pix);

}
void MainWindow::mergeFormatOnWordOrSelection(const QTextCharFormat &format)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}
MainWindow::~MainWindow()
{
    delete ui;
}
QString MainWindow::getSaveFile()
{
    return QFileDialog::getSaveFileName(this,"Save a file",QDir::homePath(),"Text files (*.txt);;XML files (*.xml);;All files (*.*)");
}
void MainWindow::saveFile(const QString &path)
{
    QFile file(path);
     if (!file.open(QIODevice::WriteOnly))
         return ;

    auto data=ui->textEdit->toPlainText().toUtf8();
    file.write(data);
    file.close();
}
QString MainWindow::readFile(const QString&aPath)
{
    m_sPathLastFile=aPath;
    QFile file(aPath); // создаем объект класса QFile
    QByteArray data; // Создаем объект класса QByteArray, куда мы будем считывать данные
    if (!file.open(QIODevice::ReadOnly)) // Проверяем, возможно ли открыть наш файл для чтения
        return ""; // если это сделать невозможно, то завершаем функцию
    data = file.readAll(); //считываем все данные с файла в объект data
    QFileInfo fileInfo(file.fileName());
    this->setWindowTitle(fileInfo.fileName());
    file.close();

    return QString(data);
}

void MainWindow::on_actionNew_triggered()
{
    ui->textEdit->clear();
    m_sPathLastFile = "NoName";
}

void MainWindow::on_actionOpen_triggered()
{
    // QFileDialog dialog(this);
    // QStringList mimeTypeFilters;
 //    mimeTypeFilters << "image/jpeg" // will show "JPEG image (*.jpeg *.jpg *.jpe)
 //                << "image/png"  // will show "PNG image (*.png)"
 //                << "application/octet-stream"; // will show "All files (*)"
 //   dialog.setNameFilter(tr("Text files (*.txt);;XML files (*.xml);;All files (*.*)"));
    // dialog.setMimeTypeFilters(mimeTypeFilters);

    // dialog.exec();
  // QString path =  dialog.getOpenFileName();

   QString path = QFileDialog::getOpenFileName(this,"Open a file",QDir::homePath(),"Text files (*.txt);;XML files (*.xml);;All files (*.*)");
   if(path!="")
   {
       QString data = readFile(path);
       ui->textEdit->setText(data);
   }
}

void MainWindow::on_actionSave_triggered()
{
    if(m_sPathLastFile=="NoName")
    {
        m_sPathLastFile = getSaveFile();
    }
     saveFile(m_sPathLastFile);
}

void MainWindow::on_actionSave_as_triggered()
{
    QString path = getSaveFile();
     if(path!="")
     {
         m_sPathLastFile = path;

         saveFile(m_sPathLastFile);
     }
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionCut_triggered()
{
     ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionfind_triggered()
{
 //ui->textEdit->find();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionPrint_Preview_triggered()
{
#if QT_CONFIG(printpreviewdialog)
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer, ui->textEdit);
     connect(&preview, &QPrintPreviewDialog::paintRequested, this, &MainWindow::printPreview);
    preview.exec();

#endif


}
void MainWindow::printPreview(QPrinter *printer)
{
#ifdef QT_NO_PRINTER
    Q_UNUSED(printer);
#else
    ui->textEdit->print(printer);
#endif
}

void MainWindow::on_actionPrint_triggered()
{
#if QT_CONFIG(printdialog)
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog *dlg = new QPrintDialog(&printer, this);
    if (ui->textEdit->textCursor().hasSelection())
        dlg->addEnabledOption(QAbstractPrintDialog::PrintSelection);
    dlg->setWindowTitle(tr("Print Document"));
    if (dlg->exec() == QDialog::Accepted)
        ui->textEdit->print(&printer);
    delete dlg;
#endif
}

void MainWindow::on_actionExport_PDF_triggered()
{
#ifndef QT_NO_PRINTER

    QFileDialog fileDialog(this, tr("Export PDF"));
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setMimeTypeFilters(QStringList("application/pdf"));
    fileDialog.setDefaultSuffix("pdf");
    if (fileDialog.exec() != QDialog::Accepted)
        return;
    QString fileName = fileDialog.selectedFiles().first();
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    ui->textEdit->document()->print(&printer);
    statusBar()->showMessage(tr("Exported \"%1\"")
                             .arg(QDir::toNativeSeparators(fileName)));

#endif
}

void MainWindow::on_actionFind_triggered()
{
    Dialog *dlg = new Dialog(this,ui->textEdit);


   //dlg.exec();
    dlg->show();

}

void MainWindow::on_actionGo_to_row_triggered()
{
    CGoToRow * nonModalDlg = new CGoToRow(this,ui->textEdit);

    nonModalDlg->show();
}

void MainWindow::on_actionGet_posiytion_triggered()
{
   auto posx =  ui->textEdit->textCursor().positionInBlock();
   int posy = ui->textEdit->textCursor().blockNumber();
   QMessageBox msg;
   msg.setText("Postions: \nX: " + QString::number(posx) + "\nY: " + QString::number(posy));
   msg.exec();

}

void MainWindow::on_actionSelect_all_triggered()
{
    ui->textEdit->selectAll();
}

void MainWindow::on_actionTime_date_triggered()
{
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    QString sDateUTC = UTC.toString();
    QString sDateLocal = local.toString();
    ui->textEdit->textCursor().insertText(sDateLocal);
}

void MainWindow::on_actionBold_triggered()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(ui->actionBold->isChecked() ? QFont::Bold : QFont::Normal);
    mergeFormatOnWordOrSelection(fmt);
}

void MainWindow::on_actionItalic_triggered()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(ui->actionItalic->isChecked());
    mergeFormatOnWordOrSelection(fmt);
}
void MainWindow::textAlign(QAction *a)
{
    if (a == ui->actionLeft)
        ui->textEdit->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
    else if (a == ui->actionCenter)
        ui->textEdit->setAlignment(Qt::AlignHCenter);
    else if (a == ui->actionRight)
        ui->textEdit->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
    else if (a == ui->actionJustify)
        ui->textEdit->setAlignment(Qt::AlignJustify);
}
void MainWindow::on_actionUnderline_triggered()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(ui->actionUnderline->isChecked());
    mergeFormatOnWordOrSelection(fmt);
}
void MainWindow::colorChanged(const QColor &c)
{
    QPixmap pix(16, 16);
    pix.fill(c);
    ui->actionColor->setIcon(pix);
}
void MainWindow::on_actionColor_triggered()
{
    QColor col = QColorDialog::getColor(ui->textEdit->textColor(), this);
    if (!col.isValid())
        return;
    QTextCharFormat fmt;
    fmt.setForeground(col);
    mergeFormatOnWordOrSelection(fmt);
    colorChanged(col);
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,QFont("Helvetica[Cronyx]",12),this);
    if(ok)
        ui->textEdit->setFont(font);

}
