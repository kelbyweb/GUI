// Assignment I3: Due June 26
// Written by: Kelby Webster (klw231)
// GUI Summer session, Dr. Dan Tamir
// mainMenu.h



#pragma once

#include <QMainWindow>
#include <QApplication>

class QAction;
class QMenu;
class QLabel;

class mainMenu : public QMainWindow {
    
    Q_OBJECT
    
public:
   mainMenu(QWidget *parent = 0);
    
private slots:
    void open();
    void save();
    void quit();
    void about();
    void aboutQt();
    
private:
    void createActions();
    void createMenus();

    
    QMenu *fileMenu;
    QMenu *helpMenu;
    QMenu *QuitMenu;
    QAction *openAct;
    QAction *saveAct;
    QAction *quitAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QLabel *infoLabel;
};

#endif
