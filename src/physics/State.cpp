//
// Created by charlesfavell on 30/09/2025.
//
#include "../../include/physics/State.h"
#include <cassert>   // if you add checks

State::State(std::size_t n, std::size_t d)
    : N(n), D(d), _q(n*d), _p(n*d) {}

std::size_t State::size() const noexcept { return N; }
std::size_t State::dim()  const noexcept { return D; }
std::size_t State::idx(std::size_t i, std::size_t k) const noexcept { return i*D + k; }

double&       State::q(std::size_t i, std::size_t k)       noexcept { return _q[idx(i,k)]; }
const double& State::q(std::size_t i, std::size_t k) const noexcept { return _q[idx(i,k)]; }
double&       State::p(std::size_t i, std::size_t k)       noexcept { return _p[idx(i,k)]; }
const double& State::p(std::size_t i, std::size_t k) const noexcept { return _p[idx(i,k)]; }

std::span<double>       State::q(std::size_t i)       noexcept { return { _q.data() + i*D, D }; }
std::span<const double> State::q(std::size_t i) const noexcept { return { _q.data() + i*D, D }; }
std::span<double>       State::p(std::size_t i)       noexcept { return { _p.data() + i*D, D }; }
std::span<const double> State::p(std::size_t i) const noexcept { return { _p.data() + i*D, D }; }
