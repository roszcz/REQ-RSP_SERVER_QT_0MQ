#include "server.h"
#include <QDebug>
#include <windows.h>


server::server(QObject *parent) :
    QObject(parent),
    clicker(0)
{
}

void server::runServerRun(){
    // PREPARE
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:5555");
    qDebug() << "running";

    while (true){

        // MAKE RESPONSE
        zmq::message_t request;
        socket.recv(&request);
        qDebug() << "ding!";
        QString recieved;
        recieved = static_cast<char*>(request.data());
        qDebug()<<recieved << endl << "dong!";
        Sleep(1);

        // REPLY
        zmq::message_t reply(22);
        double LICZBA = (rand() % 100)/1000.0;
        // FORMAT MESSAGE
        snprintf( (char *) reply.data(),22,
                  "%d klikniec! %.5f",clicker++,LICZBA);
//       memcpy((void *)reply.data(),"oboze",5);
        socket.send(reply);
    }
}
