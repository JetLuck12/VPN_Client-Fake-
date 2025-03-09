import Foundation

class VPNClient: ObservableObject {
    @Published var vpn_back = VpnBackend.instance()
    @Published var connectionStatus: String = "Отключен"

    func toggleConnection(ipAddress: String) {
        if connectionStatus == "Подключен" {
            disconnect()
        } else {
            connect(to: ipAddress)
        }
    }

    private func connect(to ipAddress: String) {
        connectionStatus = "Подключение..."
        DispatchQueue.main.asyncAfter(deadline: .now() + 2.5) {
            self.vpn_back.pointee.saveLastIPAddress(std.string(ipAddress))
            print(String(self.vpn_back.pointee.getLastIPPath()))
            print(ipAddress)
            self.connectionStatus = "Подключен"
        }
    }

    private func disconnect() {
        connectionStatus = "Отключен"
    }
}
