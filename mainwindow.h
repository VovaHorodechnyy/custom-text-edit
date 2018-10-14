#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include<QScrollArea>
#include<QScrollBar>
#include <QDesktopWidget>
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

    void on_action_Open_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
