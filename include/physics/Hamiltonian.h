//
// Created by charlesfavell on 30/09/2025.
//

#ifndef FPUT_HAMILTONIAN_H
#define FPUT_HAMILTONIAN_H

class State;

class Hamiltonian {
public:
  virtual ~Hamiltonian() = default;

  virtual void drift(State &state, double dt) = 0;
  virtual void kick(State &state, double dt) = 0;
  virtual double energy(const State &state) const = 0;
};

#endif // FPUT_HAMILTONIAN_H