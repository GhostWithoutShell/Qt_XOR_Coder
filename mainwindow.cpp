#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptr.reset(nullptr);
    initMenu();

}
void MainWindow::initMenu()
{
    QMenu *menu = new QMenu("File",this);
    QAction *action = new QAction("Save",this);
    QAction *set_im = new QAction("Set image",this);
    connect(set_im,&QAction::triggered,this,&MainWindow::setImage);
    connect(action,&QAction::triggered,this,&MainWindow::saveImage);
    menu->addAction(action);
    menu->addAction(set_im);
    ui->menuBar->addMenu(menu);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::saveImage()
{

}
void MainWindow::codeImage()
{
    if(ptr.get() != nullptr)
    {
        ptr->code();
    }
}
void MainWindow::setImage()
{
    QString name = QFileDialog::getOpenFileName(this,"","","(*.jpg)");
    if(name != "")
    {
        cv::Mat temp = cv::imread(name.toStdString().c_str());
        ptr.release();
        ptr.reset(new XOR_Coder(cv::Mat()));
        ui->label->setPixmap(QPixmap(name));
    }
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->pushButton->setText("Decode Image");
}

void MainWindow::on_radioButton_clicked()
{
    ui->pushButton->setText("Code Image");
}
