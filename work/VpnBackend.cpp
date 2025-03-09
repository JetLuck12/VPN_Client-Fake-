#include "VpnBackend.h"
#include <fstream>
#include <filesystem>
#include "QtCore/QFile"
#include "QtCore/QTextStream"
#include "QtCore/QStandardPaths"

VpnBackend::VpnBackend()
{
    QString qip;
    QString path(getLastIPPath().c_str());
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        in >> qip;
        file.close();
    }
    lastIPAddress = qip.toStdString();
}

VpnBackend& VpnBackend::instance() {
    static VpnBackend backend;
    return backend;
}

void VpnBackend::saveLastIPAddress(const std::string &ip) {
    QString qip = QString::fromStdString(ip.c_str());
    QString path = QString::fromStdString(getLastIPPath());
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << qip;
        file.close();
    }
}

std::string VpnBackend::getLastIPPath() const {
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation).toStdString() + "/last_ip.txt";
}



std::string VpnBackend::getLastIPAddress() const{
    QString qip;
    QString path = QString::fromStdString(getLastIPPath().c_str());
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        qip = in.readAll();
        file.close();
    }
    return qip.toStdString();
}
