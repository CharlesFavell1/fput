//
// Created by charlesfavell on 01/10/2025.
//

#ifndef FPUT_LINEARLATTICE_H
#define FPUT_LINEARLATTICE_H

#include "Connectivity.h"
#include <span>
#include <vector>

class LinearLattice : public Connectivity {
public:
    LinearLattice(std::size_t N, BC bc);

    std::size_t           sites() const noexcept override { return N_; }
    std::span<const Edge> edges() const noexcept override { return {edges_.data(), edges_.size()}; }

    void build_free();
    void build_periodic();
private:
    std::size_t       N_;
    std::vector<Edge> edges_;
};

#endif //FPUT_LINEARLATTICE_H
