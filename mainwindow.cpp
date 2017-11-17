#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->setText("<style>"
                               "a:link {"
                                   "color: orange;"
                                   "background-color: transparent;"
                                   "text-decoration: none;"
                               "}"
                               "</style>"
                               "<p><a href='http://www.gtronick.com'>GTRONICK</a>");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calcularButton_clicked()
{
    int liHoraInicio = ui->horaInicioTextField->text().toInt();
    int liMinutoInicio = ui->minutoInicioTextfield->text().toInt();
    int liHoraFin = ui->horaFinTextField->text().toInt();
    int liMinutoFin = ui->minutoFinTextField->text().toInt();
    int liDescanso = ui->descansoTextField->text().toInt();
    int liValorMinuto = ui->valorMinutoTextField->text().toInt();

    int totalMinutos = ((liHoraFin*60 + liMinutoFin) - (liHoraInicio*60 + liMinutoInicio) - liDescanso);
    int totalPagar = totalMinutos * liValorMinuto;

    ui->totalMinutosResultLabel->setText(QString("%1").arg(totalMinutos));
    if(totalPagar/1000 >=1000) {
        ui->totalResultLabel->setText(QString("  $ %1.%2").arg(totalPagar/1000).arg(totalPagar - ((totalPagar/1000) * 1000),3,10,QLatin1Char('0')));
    }else if(totalPagar/1000 > 0 && totalPagar/1000 < 1000){
        ui->totalResultLabel->setText(QString("  $ %1.%2").arg(totalPagar/1000).arg(totalPagar - ((totalPagar/1000) * 1000),2,10,QLatin1Char('0')));
    }else{
        ui->totalResultLabel->setText(QString("  $ %1").arg(totalPagar - ((totalPagar/1000) * 1000),1,10,QLatin1Char('0')));
    }
}

void MainWindow::on_valorMinutoTextField_textChanged(const QString &arg1)
{
    int liValue = arg1.toInt();

    if(liValue > 999999){
        liValue = liValue/10;
    }

    ui->valorMinutoTextField->setText(QString("%1").arg(liValue,6,10,QLatin1Char('0')));
}

void MainWindow::on_horaInicioTextField_textChanged(const QString &arg1)
{
    int liValue = arg1.toInt();

    if(liValue > 24){
        liValue = liValue/10;
    }

    ui->horaInicioTextField->setText(QString("%1").arg(liValue,2,10,QLatin1Char('0')));

}

void MainWindow::on_minutoInicioTextfield_textChanged(const QString &arg1)
{
    int liValue = arg1.toInt();

    if(liValue > 59){
        liValue = liValue/10;
    }

    ui->minutoInicioTextfield->setText(QString("%1").arg(liValue,2,10,QLatin1Char('0')));
}

void MainWindow::on_descansoTextField_textChanged(const QString &arg1)
{

    int liValue = arg1.toInt();

    if(liValue > 1440){
        liValue = liValue/10;
    }

    ui->descansoTextField->setText(QString("%1").arg(liValue,4,10,QLatin1Char('0')));
}

void MainWindow::on_horaFinTextField_textChanged(const QString &arg1)
{
    int liValue = arg1.toInt();

    if(liValue > 24){
        liValue = liValue/10;
    }

    ui->horaFinTextField->setText(QString("%1").arg(liValue,2,10,QLatin1Char('0')));
}

void MainWindow::on_minutoFinTextField_textChanged(const QString &arg1)
{
    int liValue = arg1.toInt();

    if(liValue > 59){
        liValue = liValue/10;
    }

    ui->minutoFinTextField->setText(QString("%1").arg(liValue,2,10,QLatin1Char('0')));
}
