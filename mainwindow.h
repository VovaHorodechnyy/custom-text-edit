#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include<QScrollArea>
#include<QScrollBar>
#include <QDesktopWidget>
#include <stdio.h>
#include <QByteArray>
#include <QDir>
#include <QMap>
#include <QPointer>
#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QColorDialog>
#include <QComboBox>
#include <QFontComboBox>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QFontDatabase>
#include <QMenu>
#include <QMenuBar>
#include <QTextCodec>
#include <QTextEdit>
#include <QStatusBar>
#include <QToolBar>
#include <QTextCursor>
#include <QTextDocumentWriter>
#include <QTextList>
#include <QtDebug>
#include <QCloseEvent>
#include <QMessageBox>
#include <QMimeData>
#include <QDateTime>
#include <QFontDialog>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printer)
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#endif
#include <QPrinter>
#if QT_CONFIG(printpreviewdialog)
#include <QPrintPreviewDialog>
#endif
#endif
#endif

#include "dialog.h"
#include "cgotorow.h"

namespace Ui {


class QAction;
class QComboBox;
class QFontComboBox;
class QTextEdit;
class QTextCharFormat;
class QMenu;
class QPrinter;

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionUndo_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionfind_triggered();

    void on_actionRedo_triggered();

    void on_actionPrint_Preview_triggered();

    void on_actionPrint_triggered();

    void on_actionExport_PDF_triggered();

    void on_actionFind_triggered();

    void on_actionGo_to_row_triggered();

    void on_actionGet_posiytion_triggered();

    void on_actionSelect_all_triggered();

    void on_actionTime_date_triggered();

    void on_actionBold_triggered();

    void on_actionItalic_triggered();

    void on_actionUnderline_triggered();

    void on_actionColor_triggered();

    void on_actionFont_triggered();

private:
    Ui::MainWindow *ui;
    QString m_sPathLastFile;

    QString readFile(const QString&aPath);
    QString getSaveFile();
    void saveFile(const QString&aPath);

    void printPreview(QPrinter *printer);
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    void textAlign(QAction *a);
    void colorChanged(const QColor &c);
};

#endif // MAINWINDOW_H
