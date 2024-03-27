#include <iostream>
#include <map>
#include <string>

// Define a struct to represent a cheat/mod option
struct CheatOrModOption {
    std::string name;
    bool enabled;

    CheatOrModOption(std::string n) : name(n), enabled(false) {}

    void toggle() {
        enabled = !enabled;
    }
};

// Define a map of cheat/mod options
const std::map<std::string, CheatOrModOption> cheatOrModOptions = {
    {"beam_deform", CheatOrModOption("BeamDeform")},
    {"time_delay", CheatOrModOption("Time Delay")},
    {"control", CheatOrModOption("Control")},
    {"road_spikes", CheatOrModOption("Road Spikes")},
    {"car_turbos", CheatOrModOption("Car Turbos")},
    {"monster_trucks", CheatOrModOption("Monster Trucks")}
};

// Function to display the admin panel
void displayAdminPanel() {
    std::cout << "======== BEAMNG.Drive Admin Panel ========\n";
    for (const auto& option : cheatOrModOptions) {
        std::cout << option.first << ": " << (option.second.enabled ? "ON" : "OFF") << "\n";
    }
    std::cout << "==================================\n";
}

// Function to enable/disable a cheat/mod option
void toggleCheatOrModOption(const std::string& optionName) {
    auto it = cheatOrModOptions.find(optionName);
    if (it != cheatOrModOptions.end()) {
        it->second.toggle();
    } else {
        std::cout << "Invalid option name: " << optionName << "\n";
    }
}
