//
// Created by charlesfavell on 30/09/2025.
//

#ifndef FPUT_FPUTHAMILTONIAN_H
#define FPUT_FPUTHAMILTONIAN_H

#include "Connectivity.h"
#include "Hamiltonian.h"
#include <memory>

class FPUTHamiltonian : public Hamiltonian {
public:
  FPUTHamiltonian(double mass, double k, double alpha, double beta,
                  std::shared_ptr<const Connectivity> bonds);

  void drift(State &state, double dt) override;
  void kick(State &state, double dt) override;
  double energy(const State &state) const override;

private:
  const double mass_;
  const double k_;
  const double alpha_;
  const double beta_;
  std::shared_ptr<const Connectivity> bonds_;
};

#endif // FPUT_FPUTHAMILTONIAN_H