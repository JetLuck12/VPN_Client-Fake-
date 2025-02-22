import SwiftUI

struct ContentView: View {
    @StateObject private var vpnClient = VPNClient()
    @State private var ipAddress: String = QtBridge.getLastIPAddress() ?? ""

    var body: some View {
        VStack(spacing: 20) {
            TextField("Введите IP-адрес", text: $ipAddress)
                .textFieldStyle(RoundedBorderTextFieldStyle())
                .padding()

            Button(action: {
                vpnClient.toggleConnection(ipAddress: ipAddress)
            }) {
                Text(vpnClient.connectionStatus == "Подключен" ? "Отключиться" : "Подключиться")
                    .font(.headline)
                    .padding()
                    .frame(maxWidth: .infinity)
                    .background(vpnClient.connectionStatus == "Подключен" ? Color.red : Color.green)
                    .foregroundColor(.white)
                    .cornerRadius(10)
            }
            .padding([.leading, .trailing])

            Text("Статус: \(vpnClient.connectionStatus)")
                .font(.subheadline)

            Spacer()
        }
        .padding()
        .onAppear{
            ipAddress = QtBridge.getLastIPAddress() ?? ""
        }
    }
}

#Preview {
    ContentView()
}
