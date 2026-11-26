# Equallibrim-Engine

**EQUILIBRIUM ENGINE — an energetic equalizer.**

## What it does

- **EquilibriumCore** — tracks physical, energy, and information stability
- **EnergyStorage** — capacity 1000.0, stores and releases energy
- **SuperpositionMemory** — remembers states in superposition
- **StateTransitionEngine** — moves the system between states
- **RealityLayer** — the layer the engine operates on

Run it and it reports energy storage, stability readings, and whether
each layer is stable, transitioning, or unstable — then prints
"EQUILIBRIUM ENGINE COMPLETE."

## Build and run

With Visual Studio, open the solution and build Debug x64. Or with g++:

```sh
g++ -std=c++17 -Wall -Wextra -o equallibrim equallibrim.cpp
./equallibrim
```

## Continuous integration

`.github/workflows/equallibrim.yml` builds the project and runs it. It
also runs daily at 06:00 UTC.
