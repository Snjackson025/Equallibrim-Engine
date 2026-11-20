#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

// ==========================================
// EQUILIBRIUM ENGINE
// Core System Version 1.0
// ==========================================

// 1. REALITY LAYER
struct RealityLayer {
    int layerID;
    string layerName;
    double energy;
    double stability;
    bool active;
};

// 2. EQUILIBRIUM CORE
class EquilibriumCore {
public:
    double calculateBalance(double positive, double negative) {
        return positive - negative;
    }

    bool isBalanced(double balance) {
        return abs(balance) < 0.001;
    }

    double calculateStability(double balance) {
        return 1.0 / (1.0 + abs(balance));
    }
};

// 3. ENERGY STORAGE
class EnergyStorage {
private:
    double storedEnergy;
    double capacity;

public:
    EnergyStorage(double maxCapacity)
        : storedEnergy(0.0), capacity(maxCapacity) {}

    void storeEnergy(double amount) {
        if (amount <= 0) return;

        double accepted = min(amount, capacity - storedEnergy);
        storedEnergy += accepted;
    }

    double releaseEnergy(double amount) {
        if (amount <= 0) return 0;

        double released = min(amount, storedEnergy);
        storedEnergy -= released;

        return released;
    }

    double getEnergy() const {
        return storedEnergy;
    }

    double getCapacity() const {
        return capacity;
    }
};

// 4. SUPERPOSITION MEMORY
struct PossibleState {
    string stateName;
    double probability;
};

class SuperpositionMemory {
private:
    vector<PossibleState> memory;

public:
    void addState(string name, double probability) {
        memory.push_back({name, probability});
    }

    void displayStates() const {
        cout << "\n--- SUPERPOSITION MEMORY ---\n";

        for (const auto& state : memory) {
            cout << state.stateName
                 << " | Probability: "
                 << state.probability * 100 << "%\n";
        }
    }

    void clearMemory() {
        memory.clear();
    }
};

// 5. STATE TRANSITION ENGINE
class StateTransitionEngine {
public:
    string determineState(double stability) {
        if (stability >= 0.90)
            return "STABLE";

        if (stability >= 0.50)
            return "TRANSITIONING";

        return "UNSTABLE";
    }
};

// ==========================================
// MAIN EQUILIBRIUM ENGINE
// ==========================================

int main() {

    cout << fixed << setprecision(4);

    cout << "=================================\n";
    cout << "       EQUILIBRIUM ENGINE\n";
    cout << "          VERSION 1.0\n";
    cout << "=================================\n";

    // Initialize systems
    EquilibriumCore equilibrium;
    EnergyStorage storage(1000.0);
    SuperpositionMemory memory;
    StateTransitionEngine transition;

    // Create reality layers
    vector<RealityLayer> layers = {
        {1, "Physical Layer", 100, 0.95, true},
        {2, "Energy Layer", 150, 0.85, true},
        {3, "Information Layer", 200, 0.90, true}
    };

    // Energy input
    storage.storeEnergy(500);

    cout << "\nENERGY STORAGE: "
         << storage.getEnergy() << "\n";

    // Load possible states
    memory.addState("Stable", 0.50);
    memory.addState("Transition", 0.30);
    memory.addState("Unstable", 0.20);

    memory.displayStates();

    // Process reality layers
    cout << "\n--- REALITY LAYERS ---\n";

    for (const auto& layer : layers) {

        double balance = equilibrium.calculateBalance(
            layer.energy,
            layer.energy * 0.10
        );

        double stability =
            equilibrium.calculateStability(balance / 100.0);

        cout << "\nLayer: " << layer.layerName;
        cout << "\nEnergy: " << layer.energy;
        cout << "\nBalance: " << balance;
        cout << "\nStability: " << stability;

        cout << "\nState: "
             << transition.determineState(stability)
             << "\n";
    }

    cout << "\n=================================\n";
    cout << " EQUILIBRIUM ENGINE COMPLETE\n";
    cout << "=================================\n";

    return 0;
}
