#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "RtAudio.h"
#include "EqualizerProcessing.h"
#include "State.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static State* state;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void setUpFrequences();
private:
    Ui::MainWindow *ui;
    RtAudio audio;
    
};
#endif // MAINWINDOW_H
