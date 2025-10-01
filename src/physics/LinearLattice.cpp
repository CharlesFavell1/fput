//
// Created by charlesfavell on 30/09/2025.
//

#include "../../include/physics/LinearLattice.h"

LinearLattice::LinearLattice(std::size_t N, BC bc) : N_(N) {

    if (N_ < 2) return;
    if (bc == BC::Free)   edges_.reserve(N_ - 1);
    else                  edges_.reserve(N_);

    switch (bc) {
    case BC::Free:     build_free();     break;
    case BC::Periodic: build_periodic(); break;
    }
}

void LinearLattice::build_free() {
    for (std::size_t i = 0; i + 1 < N_; ++i)
        edges_.push_back({i, i + 1});
}

void LinearLattice::build_periodic() {
    for (std::size_t i = 0; i + 1 < N_; ++i)
        edges_.push_back({i, i + 1});
    edges_.push_back({N_ - 1, 0}); // wrap
}