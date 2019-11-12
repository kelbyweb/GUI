// Assignment I3: Due June 26
// Written by: Kelby Webster (klw231)
// GUI Summer session, Dr. Dan Tamir
// mainMenu.cpp


#include "mainMenu.h"
#include <QWidget>
#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <QDial>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include <QMenu>
#include <QMainWindow>
#include <QStatusBar>
#include <QAction>
#include <QTextEdit>
#include <QWidget>
#include <QHeaderView>
#include <QToolBar>
#include <QCoreApplication>
#include <QKeySequence>
#include <QtGui>

mainMenu::mainMenu(QWidget *parent)
: QMainWindow(parent) {
    
   
    // declaring widgets
    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    QDial *dial = new QDial;
    QLCDNumber *lcd = new QLCDNumber;
    QRadioButton *am = new QRadioButton("AM");
    QRadioButton *fm = new QRadioButton("FM");
    QLabel *tuner = new QLabel("Tuner");
    QSpinBox *bassSpin = new QSpinBox;
    QSlider *bassSlide = new QSlider(Qt::Vertical);
    QSpinBox *trebleSpin = new QSpinBox;
    QSlider *trebleSlide = new QSlider(Qt::Vertical);
    QLabel *volume = new QLabel("    Volume");
    volume->setBuddy(lcd);
    QLabel *bass = new QLabel("Bass");
    QLabel *treble = new QLabel("Treble");
    QLabel *modulation = new QLabel("Modulation");
    modulation->setBuddy(am);
    QPushButton *exit = new QPushButton("Exit");
    
    QTextEdit *textEdit = new QTextEdit;
    QLabel *textEditArea = new QLabel("Text Edit Area");
  
    // menu bar
    createActions();
    createMenus();

    
    // exit button
    QObject::connect(exit, SIGNAL(clicked()),
                     QApplication::instance(), SLOT(quit()));
    
    // tuner spinbox/slider
    spinBox->setRange(540, 1600);
    slider->setRange(540, 1600);
    spinBox->setValue(1070);
    tuner->setBuddy(slider);
    
    QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                     slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)),
                     spinBox, SLOT(setValue(int)));
    
    
    
    // bass and treble spinbox/sliders
    bassSpin->setRange(-15, 15);
    bassSlide->setRange(-15, 15);
    bassSpin->setValue(0);
    bass->setBuddy(bassSlide);
    
    QObject::connect(bassSpin, SIGNAL(valueChanged(int)),
                     bassSlide, SLOT(setValue(int)));
    QObject::connect(bassSlide, SIGNAL(valueChanged(int)),
                     bassSpin, SLOT(setValue(int)));
    
    
    trebleSpin->setRange(-15, 15);
    trebleSlide->setRange(-15, 15);
    trebleSpin->setValue(0);
    treble->setBuddy(trebleSlide);
    
    QObject::connect(trebleSpin, SIGNAL(valueChanged(int)),
                     trebleSpin, SLOT(setValue(int)));
    QObject::connect(trebleSlide, SIGNAL(valueChanged(int)),
                     trebleSpin, SLOT(setValue(int)));
    
    
    
    // connecting volume dial to lcd
    dial->setRange(0, 100);
    dial->setNotchesVisible(true);
    QObject::connect(dial, SIGNAL(valueChanged(int)), lcd , SLOT(display(int)));
    
    
    
    // layouts
    QVBoxLayout *topLeftLayout = new QVBoxLayout;
    topLeftLayout ->addWidget(modulation);
    topLeftLayout->addWidget(am);
    topLeftLayout->addWidget(fm);
    topLeftLayout->addWidget(tuner);
    topLeftLayout->addWidget(spinBox);
    topLeftLayout->addWidget(slider);
    topLeftLayout->addWidget(exit);
    exit->show();
    
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(volume);
    rightLayout->addWidget(dial);
    rightLayout->addWidget(lcd);
    
    
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(bass);
    leftLayout->addWidget(bassSpin);
    leftLayout->addWidget(bassSlide);
    leftLayout->addWidget(treble);
    leftLayout->addWidget(trebleSpin);
    leftLayout->addWidget(trebleSlide);
    
    QVBoxLayout *farRightLayout = new QVBoxLayout;
    farRightLayout->addWidget(textEditArea);
    farRightLayout->addWidget(textEdit);
    
    
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addLayout(topLeftLayout);
    layout->addLayout(leftLayout); 
    layout->addLayout(rightLayout);
    layout->addLayout(farRightLayout);
   
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);
}

void mainMenu::open()
{
    infoLabel->setText(tr("Invoked <b>File|Open</b>"));
}

void mainMenu::save()
{
    infoLabel->setText(tr("Invoked <b>File|Save</b>"));
}

void mainMenu::quit()
{
    infoLabel->setText(tr("Invoked <b>Quit|Quit application</b>"));

}

void mainMenu::about()
{
    infoLabel->setText(tr("Invoked <b>Help|About</b>"));
    QMessageBox::about(this, tr("About Menu"),
                       tr("The <b>Menu</b> example shows how to create "
                          "menu-bar menus and context menus."));
}

void mainMenu::aboutQt()
{
    infoLabel->setText(tr("Invoked <b>Help|About Qt</b>"));
}




void mainMenu::createActions()
{
    openAct = new QAction(tr("&Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
    
    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));
    
    
    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    
    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(aboutQtAct, SIGNAL(triggered()), this, SLOT(aboutQt()));
    
    
    quitAct = new QAction(tr("&Quit application"), this);
    quitAct->setShortcuts(QKeySequence::Quit);
    quitAct->setStatusTip(tr("Exit the application"));
    connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));
      //QObject::connect(quit, SIGNAL(triggered()), QApplication::instance(), SLOT(quit()));
    
}



void mainMenu::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
    
    QuitMenu = menuBar()->addMenu(tr("&Quit"));
    QuitMenu->addAction(quitAct);
    
}




