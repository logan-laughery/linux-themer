 #include "mainwindow.h"

 #include <QCoreApplication>
 
 MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
 {
    // Create the button, make "this" the parent
    dark_button = new QPushButton("Dark", this);
    light_button = new QPushButton("Light", this);
    // set size and location of the button
    dark_button->setGeometry(QRect(QPoint(200, 200), 
    QSize(200, 50)));
    light_button->setGeometry(QRect(QPoint(100, 100),
    QSize(200, 50)));
 
    // Connect button signal to appropriate slot
    connect(dark_button, SIGNAL (released()), this, SLOT (handleDarkButton()));
    connect(light_button, SIGNAL (released()), this, SLOT (handleLightButton()));

    test_button = new AnimatedHoverButton(tr("Hover Over Me"), this);
    test_button->setGeometry(QRect(QPoint(300, 300), 
    QSize(200, 50)));
    QPalette p(test_button->palette());

    p.setBrush(QPalette::Button, QColor("#F89778"));
    p.setBrush(QPalette::ButtonText, QColor("#FFFFFF"));
    p.setBrush(QPalette::Highlight, QColor("#F4511E"));

    test_button->setPalette(p);
    test_button->setTransitionDuration(300);

    QFont font = test_button->font();
    font.setPointSize(16);
    test_button->setFont(font);

    connect(test_button, SIGNAL (released()), this, SLOT (handleTestButton()));
 }
 
 void MainWindow::handleDarkButton()
 {
    // change the text
    dark_button->setText("Dark");
    // resize button
    dark_button->resize(100,100);
    QCoreApplication::exit(1);
 }

 void MainWindow::handleLightButton()
 {
    // change the text
    light_button->setText("Light");
    // resize button
    light_button->resize(100,100);
    QCoreApplication::exit(2);
 }

void MainWindow::handleTestButton()
{
    QFont font = test_button->font();
    font.setPointSize(14);
    test_button->setFont(font);
}
