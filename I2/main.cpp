// Assignment I2: Due June 21
// Written by: Kelby Webster (klw231)
// GUI Summer session, Dr. Dan Tamir
// main.cpp


#include <QApplication>
#include "mainMenu.h"
#include "mainMenu.cpp"


int main(int argc, char *argv[]) {
    
    QApplication app(argc, argv);
    
    // main and menu window
    mainMenu window;
    
    window.resize(450, 450);
    window.setWindowTitle("Radio Interface");
    window.show();
    
    return app.exec();
}
