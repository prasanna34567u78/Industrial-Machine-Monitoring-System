#include <iostream>
#include <vector>
#include <cmath>

class User {
public:
    std::string username;
    std::string password;
    std::string role;
};

class Machine {
public:
    std::string name;
    double temperature;
    double pressure;
    double speed;

    Machine(const std::string& n) : name(n), temperature(0.0), pressure(0.0), speed(0.0) {}

    void displayData() {
        std::cout << "Machine: " << name << "\n";
        std::cout << "Temperature: " << temperature << " C\n";
        std::cout << "Pressure: " << pressure << " Pa\n";
        std::cout << "Speed: " << speed << " RPM\n";
        std::cout << "-------------------------\n";
    }
};

class MonitoringSystem {
public:
    std::vector<Machine> machines;

    void addMachine(const std::string& name) {
        machines.emplace_back(name);
    }

    void displayAllData() {
        for (const auto& machine : machines) {
            machine.displayData();
        }
    }
};

class AlertSystem {
public:
    void checkMachineParameters(const Machine& machine) {
        if (machine.temperature > 80.0 || machine.pressure > 100000.0 || machine.speed > 3000.0) {
            sendNotification("ALERT: Abnormal machine parameters detected!");
        }
    }

    void sendNotification(const std::string& message) {
        std::cout << "Notification: " << message << "\n";
    }
};

class RemoteControl {
public:
    void adjustMachineParameters(Machine& machine, double newTemperature, double newPressure, double newSpeed) {
        machine.temperature = newTemperature;
        machine.pressure = newPressure;
        machine.speed = newSpeed;
        std::cout << "Machine parameters adjusted remotely.\n";
    }
};

int main() {
    User admin{"admin", "admin123", "admin"};
    MonitoringSystem monitoringSystem;
    AlertSystem alertSystem;
    RemoteControl remoteControl;

    // Add machines to the monitoring system
    monitoringSystem.addMachine("Machine1");
    monitoringSystem.addMachine("Machine2");

    // Simulate real-time data monitoring
    for (int i = 0; i < 5; ++i) {
        for (auto& machine : monitoringSystem.machines) {
            machine.temperature = 60.0 + std::rand() % 40;
            machine.pressure = 50000.0 + std::rand() % 50000;
            machine.speed = 1000.0 + std::rand() % 2000;

            // Display machine data
            machine.displayData();

            // Check for alerts
            alertSystem.checkMachineParameters(machine);
        }

        // Display all machine data
        monitoringSystem.displayAllData();
    }

    // Simulate remote control
    remoteControl.adjustMachineParameters(monitoringSystem.machines[0], 75.0, 80000.0, 1500.0);

    return 0;
}
