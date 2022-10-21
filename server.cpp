#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    m_socket = new QUdpSocket(this);

    connect(m_socket, &QUdpSocket::stateChanged, [](QAbstractSocket::SocketState state) {
        qInfo("%d", state);
    });

    connect(m_socket, &QUdpSocket::readyRead, [this]() {
        QByteArray buffer;
        QHostAddress sender;
        quint16 senderPort;

        buffer.resize(Server::m_socket->pendingDatagramSize());
        m_socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
        QString str = QString(buffer);
        qInfo() << str;
    });

    m_socket->bind(QHostAddress::AnyIPv4, 5810);
}

void Server::sendPacket(void) {
    m_socket->writeDatagram((char*)&settings, sizeof(settings), QHostAddress("192.168.1.166"), 5810);
}
