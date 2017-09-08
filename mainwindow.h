#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"xor_coder.h"
#include"coder.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void codeImage();
    void saveImage();
    void setImage();
    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<XOR_Coder> ptr;
private:
    void initMenu();
};

#endif // MAINWINDOW_H
