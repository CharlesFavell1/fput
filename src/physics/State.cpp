//
// Created by charlesfavell on 30/09/2025.
//
#include "../../include/physics/State.h"
#include <algorithm>
#include <cassert>
#include <numeric>
#include <span>

State::State(std::size_t N, std::size_t D)
    : _N(N), _D(D), _ids2idx(N), _idx2ids(N), _q(N * D), _p(N * D) {}

void State::initial_condition(std::vector<double> q0, std::vector<double> p0) {
  assert(q0.size() == p0.size() && q0.size() == (_N * _D) &&
         "initial_condition: q0/p0 must both have size N*D");
  _q = std::move(q0);
  _p = std::move(p0);

  std::iota(_ids2idx.begin(), _ids2idx.end(), std::size_t{0});
  std::iota(_idx2ids.begin(), _idx2ids.end(), std::size_t{0});
}

void State::remove(std::span<std::size_t> rows) {
  // takes a container of the indices to be removed
  // make decreasing to prevent any cock-ups
  if (rows.empty())
    return;
  std::sort(rows.begin(), rows.end(), std::greater<>{});
  for (std::size_t idx : rows) {
    State::_remove_row(idx, _q);
    State::_remove_row(idx, _p);
  }
}

std::size_t State::size() const noexcept { return _N; }
std::size_t State::dim() const noexcept { return _D; }
std::size_t State::idx(std::size_t i, std::size_t k) const noexcept {
  return i * _D + k;
}
std::size_t State::ids2idx(std::size_t id) const noexcept {
  return _ids2idx[id];
};
std::size_t State::idx2ids(std::size_t i) const noexcept { return _idx2ids[i]; }

double &State::q(std::size_t i, std::size_t k) noexcept {
  return _q[idx(i, k)];
}
const double &State::q(std::size_t i, std::size_t k) const noexcept {
  return _q[idx(i, k)];
}
double &State::p(std::size_t i, std::size_t k) noexcept {
  return _p[idx(i, k)];
}
const double &State::p(std::size_t i, std::size_t k) const noexcept {
  return _p[idx(i, k)];
}

std::span<double> State::q(std::size_t i) noexcept {
  return {_q.data() + i * _D, _D};
}
std::span<const double> State::q(std::size_t i) const noexcept {
  return {_q.data() + i * _D, _D};
}
std::span<double> State::p(std::size_t i) noexcept {
  return {_p.data() + i * _D, _D};
}
std::span<const double> State::p(std::size_t i) const noexcept {
  return {_p.data() + i * _D, _D};
}

// helper function

void State::_update_mapping(std::size_t idx) {}

void State::_remove_row(std::size_t idx, std::vector<double> &vec) {
  assert(idx < _N);
  const std::size_t last = _N - 1;
  if (idx != last) {
    std::copy_n(vec.data() + last * _D, _D, vec.data() + idx * _D);
  }
  vec.resize((_N - 1) * _D);
  --_N;
}