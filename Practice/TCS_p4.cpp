#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#define PI 3.14159265

struct Device {
    int id;
    std::vector<std::pair<int, std::pair<double, double>>> connectedDevices; // Pair of (Device ID, Pair of (Distance, Angle))
};

double calculateDistance(Device device1, Device device2) {
    // Initialize coordinates for each device
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;

    // Calculate coordinates for device1
    for (const auto& connection : device1.connectedDevices) {
        x1 += connection.second.first * cos(connection.second.second * (PI / 180.0));
        y1 += connection.second.first * sin(connection.second.second * (PI / 180.0));
    }

    // Calculate coordinates for device2
    for (const auto& connection : device2.connectedDevices) {
        x2 += connection.second.first * cos(connection.second.second * (PI / 180.0));
        y2 += connection.second.first * sin(connection.second.second * (PI / 180.0));
    }

    // Calculate Euclidean distance
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


int main() {
    int N;
    std::cin >> N;

    std::vector<Device> devices(N);

    for (int i = 0; i < N; i++) {
        int id, numConnections;
        std::cin >> id >> numConnections;

        devices[i].id = id;

        for (int j = 0; j < numConnections; j++) {
            int connectedDeviceId;
            double distance, angle;
            std::cin >> connectedDeviceId >> distance >> angle;

            devices[i].connectedDevices.push_back(std::make_pair(connectedDeviceId, std::make_pair(distance, angle)));
        }
    }

    int device1Id, device2Id;
    std::cin >> device1Id >> device2Id;

    Device device1, device2;

    for (const auto& device : devices) {
        if (device.id == device1Id) {
            device1 = device;
        } else if (device.id == device2Id) {
            device2 = device;
        }
    }

    double distance = calculateDistance(device1, device2);

    std::cout << std::fixed << std::setprecision(2) << distance << std::endl;

    return 0;
}
