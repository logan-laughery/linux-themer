// #include <QtWidgets/QApplication>
// #include <QtWidgets/QPushButton>


// int main( int argc, char **argv ) {
//   QApplication a( argc, argv );

//   QPushButton themer( "Linux Themer: Hello world!", 0 );
//   themer.resize( 100, 30 );

//   themer.show();
//   return a.exec();
// }

 #include "mainwindow.h"
 #include <QtWidgets/QApplication>
 
 int main(int argc, char *argv[]) 
 {
     QApplication app(argc, argv);
     MainWindow mainWindow;
     mainWindow.showMaximized();
     return app.exec();
 }