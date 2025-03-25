#include "Server.hpp"

Server::Server(QObject* parent)
    : QObject(parent), udpSocket(new QUdpSocket(this)) {}

Server::~Server() {
    delete udpSocket;
}

void Server::start(quint16 port) {
    udpSocket->bind(QHostAddress::Any, port, QUdpSocket::ShareAddress);
    connect(udpSocket, &QUdpSocket::readyRead, this, &Server::processPendingDatagrams);
}

void Server::stop() {
    udpSocket->close();
}

void Server::processPendingDatagrams() {
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray data;
        data.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(data.data(), data.size());
        udpSocket->writeDatagram(data, udpSocket->peerAddress(), udpSocket->peerPort());
    }
}
