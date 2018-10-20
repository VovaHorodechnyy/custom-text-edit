#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include<QScrollArea>
#include<QScrollBar>
#include <QDesktopWidget>
#include <stdio.h>
#include <QByteArray>
#include<QDir>
namespace Ui {
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

private:
    Ui::MainWindow *ui;
    QString m_sPathLastFile;

    QString readFile(const QString&aPath);
    QString getSaveFile();
    void saveFile(const QString&aPath);
};

#endif // MAINWINDOW_H
