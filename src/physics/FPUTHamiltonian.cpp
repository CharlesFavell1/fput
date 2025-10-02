//
// Created by charlesfavell on 30/09/2025.
//

#include "../../include/physics/FPUTHamiltonian.h"
#include "../../include/physics/State.h"

#include <cmath>

FPUTHamiltonian::FPUTHamiltonian(const double mass, const double k,
                                 const double alpha, const double beta,
                                 std::shared_ptr<const Connectivity> bonds)
    : mass_(1.0 / mass), k_(k), alpha_(alpha), beta_(beta),
      bonds_(std::move(bonds)) {}

void FPUTHamiltonian::drift(State &state, double dt) {
  const std::size_t N = state.size();
  const std::size_t D = state.dim();

  for (std::size_t i = 0; i < N; ++i) {
    auto qi = state.q(i);
    auto pi = state.p(i);
    for (std::size_t k = 0; k < D; ++k) {
      qi[k] += dt * pi[k] / mass_;
    }
  }
}

void FPUTHamiltonian::kick(State &s, double dt) {
  // f_{i,j} = - ( q_i - q_j ) * ( k + alpha * r + beta * r * r )
  const std::size_t D = s.dim();

  for (const Edge &e : bonds_->edges()) {
    // we have no sink but just to force the logic
    std::size_t i_idx = s.ids2idx(e.i), j_idx = s.ids2idx(e.j);

    auto qi = s.q(i_idx), qj = s.q(j_idx);
    auto pi = s.p(i_idx), pj = s.p(j_idx);

    // distance
    double r2 = 0.0;
    for (std::size_t a = 0; a < D; ++a) {
      const double d = qj[a] - qi[a];
      r2 += d * d;
    }

    const double r = std::sqrt(r2);
    const double coeff = k_ + alpha_ * r + beta_ * r2;

    // N dimensional kick

    for (std::size_t a = 0; a < D; ++a) {
      const double d = qj[a] - qi[a];
      const double f = coeff * d;
      pi[a] += dt * f;
      pj[a] -= dt * f;
    }
  }
}
}
}
