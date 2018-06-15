//use QT_perfusion.ino file

#include "MainWindow.h"
#include <QTimer>
#include<QDebug>
#include "serial.h"
#include <QMouseEvent>
#include <QPushButton>
#include "QSignalMapper"

//#include "vars.h"
int bufShowSize=3000;
int nodes_N=340;
int lines_N=5;
float f;

Serial hSerial;
QPushButton* ON_BTN1;
QPushButton* ON_BTN2;
QPushButton* return_BTN;
QTimer *timer;
QTimer *run_timer;
QString qstr;
bool on1, on2;
uint8_t sendVal=1;
//work* WK;


void whitening(QWidget* w);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    QSignalMapper* signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(int)),
            this, SLOT(buttonClicked(int)));

    ON_BTN1=new QPushButton("off1");
    ON_BTN2=new QPushButton("off2");


    connect(ON_BTN1, SIGNAL(clicked()),
            signalMapper,         SLOT(map()));
    signalMapper->setMapping(ON_BTN1, 4);

    connect(ON_BTN2, SIGNAL(clicked()),
            signalMapper,         SLOT(map()));
    signalMapper->setMapping(ON_BTN2, 5);

//    return_BTN=new QPushButton("return");
    LE_COM=new QLineEdit();
    qstr=QString("COM5");
    LE_COM->setText(qstr);

    int frame_width=4;
    QGridLayout* GL=new QGridLayout();
    GL->addWidget(LE_COM,0/frame_width,0%frame_width);

    GL->addWidget(ON_BTN1,1,0);
    GL->addWidget(ON_BTN2,1,1);


    ON_BTN1->setMinimumWidth(60);
    ON_BTN1->setMaximumWidth(60);
    ON_BTN1->setMinimumHeight(60);

    ON_BTN2->setMinimumWidth(60);
    ON_BTN2->setMaximumWidth(60);
    ON_BTN2->setMinimumHeight(60);

    LE_COM->setMaximumWidth(120);
    //    ON_BTN1->setStyleSheet();

    QWidget *centralWidget1=new QWidget();
    centralWidget1->setLayout(GL);
    setCentralWidget(centralWidget1);


    timer=new QTimer(this);

//    connect(ON_BTN1,SIGNAL(released()),this,SLOT(turn()));
    connect(this,SIGNAL( btn_sig(int)),this,SLOT(btn_slot(int)));
    connect(LE_COM,SIGNAL(returnPressed()),this,SLOT(waitCOM_Subm()));

    timer->start(100);

    run_timer=new QTimer;

    this->update();



//    ON_BTN1->setStyleSheet("background-image: url(release/red.png); font-size: 20px;");
//    LE_COM->setStyleSheet("background-image: url(release/empty.png); font-size: 16px;");

    //        QPixmap bkgnd("C:/Users/chibi/Documents/Lightshot/empty.png)");
    //        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    //        QPalette palette;
    //        palette.setBrush(QPalette::Background, bkgnd);
    //        this->setPalette(palette);
}

void MainWindow::buttonClicked(int i)
{
    switch(i)
    {
    case 4:

        on1=!on1;
        if(on1)
        {
            ON_BTN1->setText("on1");
            hSerial.write((uint8_t)(254));

        }
        else
        {
            ON_BTN1->setText("off1");
            hSerial.write((uint8_t)(0));

        }
        break;
    case 5:

        on2=!on2;
        if(on2)
        {
            ON_BTN2->setText("on2");
            hSerial.write((uint8_t)(255));

        }
        else
        {
            ON_BTN2->setText("off2");
            hSerial.write((uint8_t)(1));

        }
        break;

    case 6:
        hSerial.write((uint8_t)(6));

        break;
    }
}

void MainWindow::drawing()
{
    this->update();
}



void MainWindow::waitCOM_Subm()
{
    qstr=LE_COM->text();
    std::string str1=qstr.toUtf8().constData();
    std::wstring str(str1.begin(),str1.end());
    hSerial.InitCOM(str.c_str());//was L"COM5"

    hSerial.write((uint8_t)(40));

    LE_COM->setDisabled(1);

//    LE_speed->setDisabled(0);
//   ON_BTN1->setDisabled(0);
//   return_BTN->setDisabled(0);
    //    buttonClicked(4);
}

void MainWindow::send()
{

        hSerial.write(0);
//    }
}

void MainWindow::mousePressEvent(QMouseEvent *)
{

}



void MainWindow::paintEvent(QPaintEvent* e)
{
    //    static float t=1;
    //    t+=.06;
    //    if(t>10)t=10;
    //    for (int i=0;i<t;i++)
    //        mainCircLE_COM();

    //    QPainter* painter=new QPainter(this);
    //    painter->setRenderHint(QPainter::Antialiasing, 1);
    //    QPen pen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    //    painter->setPen(pen);
    //    painter->scaLE_COM(1.5,1.5);



    //    deLE_COMte painter;
}

MainWindow::~MainWindow()
{

}


