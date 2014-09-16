#include "client.h"
#include <QDebug>

client::client(QObject *parent) :
    QObject(parent),
    c_context(zmq::context_t(1)),
    c_socket(zmq::socket_t(c_context, ZMQ_REQ))
{
}

void client::goConnect(){

    // Tu tylko laczy sie z adresem
    c_socket.connect("tcp://localhost:5555");
}

void client::sendMsg(){

    // SEND MESSAGE;
    zmq::message_t request (6);
    memcpy ((void *) request.data (), "Hello", 5);
    qDebug() << "trying to poke";
    c_socket.send(request);

    // RECIEVE REPLY
    zmq::message_t reply;
    c_socket.recv (&reply);

    // READ AS STRING
    QString test;
    test = static_cast<char*>(reply.data());
    qDebug() << "Client Received Stuff: " << test;
}
