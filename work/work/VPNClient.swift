import Foundation

class VPNClient: ObservableObject {
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
            QtBridge.saveLastIPAddress(ipAddress)
            self.connectionStatus = "Подключен"
        }
    }

    private func disconnect() {
        connectionStatus = "Отключен"
    }
}
