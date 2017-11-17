#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_calcularButton_clicked();

    void on_valorMinutoTextField_textChanged(const QString &arg1);

    void on_horaInicioTextField_textChanged(const QString &arg1);

    void on_minutoInicioTextfield_textChanged(const QString &arg1);

    void on_descansoTextField_textChanged(const QString &arg1);

    void on_horaFinTextField_textChanged(const QString &arg1);

    void on_minutoFinTextField_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
