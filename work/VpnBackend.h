#ifndef VPNBACKEND_H
#define VPNBACKEND_H

#include <string>

class VpnBackend {
public:
    static VpnBackend& instance();
    void saveLastIPAddress(const std::string& ip);
    std::string getLastIPAddress() const;
    std::string getLastIPPath() const;
private:
    VpnBackend();
    std::string lastIPAddress;
};

#endif // VPNBACKEND_H
