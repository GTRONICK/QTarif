#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("www.gtronick.com");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calcularButton_clicked()
{
    int hInicio = ui->horaInicioTextField->text().toInt();
    int mInicio = ui->minutoInicioTextfield->text().toInt();
    int hFin = ui->horaFinTextField->text().toInt();
    int mFin = ui->minutoFinTextField->text().toInt();
    int descanso = ui->descansoTextField->text().toInt();
    int valorMinuto = ui->valorMinutoTextField->text().toInt();

    int totalMinutos = ((hFin*60 + mFin) - (hInicio*60 + mInicio) - descanso);
    int totalPagar = totalMinutos * valorMinuto;

    ui->totalMinutosResultLabel->setText(QString("%1").arg(totalMinutos));
    if(totalPagar/1000 > 0)
        ui->totalResultLabel->setText(QString("  $ %1.%2").arg(totalPagar/1000).arg(totalPagar - ((totalPagar/1000) * 1000),3,10,QLatin1Char('0')));
    else{
        ui->totalResultLabel->setText(QString("  $ %1").arg(totalPagar - ((totalPagar/1000) * 1000),3,10,QLatin1Char('0')));
    }
}
