#include "VpnBackend.h"
#include <fstream>
#include <filesystem>

VpnBackend::VpnBackend()
{
    std::ifstream file(getLastIPPath());
    std::string ip;
    
    if (file.is_open()) {
        std::getline(file, ip);
        file.close();
    }
    lastIPAddress = ip;
}

VpnBackend& VpnBackend::instance() {
    static VpnBackend backend;
    return backend;
}

void VpnBackend::saveLastIPAddress(const std::string& ip) {
    lastIPAddress = ip;
    std::ofstream file(getLastIPPath());
        if (file.is_open()) {
            file << ip;
            file.close();
        }
}

std::string VpnBackend::getLastIPAddress() const {
    std::ifstream file(getLastIPPath());
        std::string ip;
        
        if (file.is_open()) {
            std::getline(file, ip);
            file.close();
        }
    return lastIPAddress;
}

std::string VpnBackend::getLastIPPath() const {
    std::string path = std::filesystem::temp_directory_path().string() + "/last_ip.txt";
    return path;
}
