#include <iostream>
#include <map>
#include <string>

// Define a struct to represent a cheat option
struct CheatOption {
    std::string name;
    bool enabled;

    CheatOption(std::string n) : name(n), enabled(false) {}

    void toggle() {
        enabled = !enabled;
    }
};

// Define a map of cheat options
std::map<std::string, CheatOption> cheatOptions = {
    {"Beam Deform", CheatOption("BeamDeform")},
    {"Time Delay", CheatOption("timeDelay")},
    {"Control", CheatOption("control")}
};

// Function to display the cheat menu
void displayCheatMenu() {
    std::cout << "============ BEAMNG.Drive Cheat Menu ============\n";
    for (const auto& option : cheatOptions) {
        std::cout << option.first << ": " << (option.second.enabled ? "ON" : "OFF") << "\n";
    }
    std::cout << "==============================================\n";
}

// Function to enable/disable a cheat option
void toggleCheatOption(std::string optionName) {
    if (cheatOptions.find(optionName) != cheatOptions.end()) {
        cheatOptions[optionName].toggle();
    }
}

int main() {
    // Game loop
    while (true) {
        // Display the cheat menu
        displayCheatMenu();

        // Get user input
        std::cout << "Enter a cheat option to toggle (or 'exit' to quit): ";
        std::string input;
        std::cin >> input;

        if (input == "exit") {
            break;
        }

        // Toggle the cheat option
        toggleCheatOption(input);
    }

    return 0;
}