# Equallibrim Engine — Workflow

Standalone project: Equallibrim-Engine, "Energetic Equalizer".
Code calls itself EQUILIBRIUM ENGINE, Core System Version 1.0.

## What it does

- `EquilibriumCore` — balance = positive - negative, stability = 1 / (1 + |balance|)
- `EnergyStorage` — capacity 1000.0, stores 500.0 in the demo run
- `SuperpositionMemory` — Stable 50%, Transition 30%, Unstable 20%
- `StateTransitionEngine` — STABLE >= 0.90, TRANSITIONING >= 0.50, otherwise UNSTABLE
- `RealityLayer` — Physical (100 energy), Energy (150), Information (200)

Demo run results, verified:
- Physical Layer: balance 90.0000, stability 0.5263, TRANSITIONING
- Energy Layer: balance 135.0000, stability 0.4255, UNSTABLE
- Information Layer: balance 180.0000, stability 0.3571, UNSTABLE

## Files

- `equallibrim.cpp` — the engine
- `scripts/equallibrim-check.sh` — local smoke test, mirrors the workflow
- `.github/workflows/equallibrim.yml` — GitHub Actions workflow

## Local check

```sh
bash scripts/equallibrim-check.sh
```

Compiles with `g++ -std=c++17 -Wall -Wextra`, runs the engine,
and verifies the output contains the header, 500.0000 stored energy,
the Physical Layer stability 0.5263, TRANSITIONING / UNSTABLE states,
and "EQUILIBRIUM ENGINE COMPLETE."

## GitHub workflow

`.github/workflows/equallibrim.yml` runs on pushes and pull requests
to `main` touching `equallibrim.cpp`, the check script, or the
workflow file itself. One job: compile, run, verify output.

Note: like the other projects, the workflow file cannot be pushed
via the Muse GitHub App (403 on `.github/workflows/*`). Add it
manually on github.com as `.github/workflows/equallibrim.yml`.
Repo is private under Snjackson025 — the Muse GitHub App must be
added to Snjackson025/Equallibrim-Engine before Muse can push to it.
