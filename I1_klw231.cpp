// Assignment I1: Due June 16
// Written by: Kelby Webster (klw231)
// GUI Summer session, Dr. Dan Tamir


#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <QDial>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QLabel>

int main(int argc, char *argv[])
{
    // main window
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    window->resize(300,300);
    window->setWindowTitle("Radio Interface");
    
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
    
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addLayout(topLeftLayout);
    layout->addLayout(leftLayout);
    layout->addLayout(rightLayout);
    
    
    window->setLayout(layout);
    window->show();
    return app.exec();
}
