 #ifndef MAINWINDOW_H
 #define MAINWINDOW_H

 #include "animatedbutton.h"
 
 #include <QtWidgets/QMainWindow>
 #include <QtWidgets/QPushButton>
 
 namespace Ui {
    class MainWindow;
 }
 
 class MainWindow : public QMainWindow
 {
    Q_OBJECT
 public:
    explicit MainWindow(QWidget *parent = 0);
 private slots:
    void handleDarkButton();
    void handleLightButton();
    void handleTestButton();
 private:
    QPushButton *dark_button;
    QPushButton *light_button;
    AnimatedHoverButton *test_button;
 };
 
 #endif // MAINWINDOW_H