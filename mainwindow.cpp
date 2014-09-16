#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "server.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initThings();
}

void MainWindow::initThings(){

    // SERWEROWNIA
    // PUT REQ_SERVER IN A NEW THREAD
    QThread *thread = new QThread;
    server *HOME = new server;
    HOME->moveToThread(thread);
    QObject::connect(thread,SIGNAL(started()),
                     HOME,SLOT(runServerRun()));

    // START SERVER THREAD
    thread->start();


    // KLIENTOWNIA
    // CLIENT ONE, SEPARATE THREADS
    QThread *c1_thread = new QThread;
    client *c1_client = new client;
    c1_client->moveToThread(c1_thread);

    // CONNECT WITH BUTTON AND START THREAD
    QObject::connect(c1_thread,SIGNAL(started()),
                     c1_client,SLOT(goConnect()));
    QObject::connect(ui->buttonClient,SIGNAL(clicked()),
                     c1_client,SLOT(sendMsg()));
    // START
    c1_thread->start();

    //ANOTHER CLIENT, ANOTHER THREAD!
    QThread *c2_thread = new QThread;
    client *c2_client = new client;
    c2_client->moveToThread(c2_thread);

    // CONNECT WITH BUTTON AND START THREAD
    QObject::connect(c2_thread,SIGNAL(started()),
                     c2_client,SLOT(goConnect()));
    QObject::connect(ui->buttonClient2,SIGNAL(clicked()),
                     c2_client,SLOT(sendMsg()));
    // START
    c2_thread->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}
