//
// Created by charlesfavell on 30/09/2025.
//

#ifndef FPUT_STATE_HPP
#define FPUT_STATE_HPP

#include <cstddef>
#include <span>
#include <vector>

class State {
public:
    State(std::size_t n, std::size_t d);

    void initial_condition(std::vector<double> q0, std::vector<double> p0);

    void _update_mapping(std::size_t idx);
    void _remove_row(std::size_t idx, std::vector<double>& vec);
    void remove(std::span<std::size_t> rows);

    std::size_t size() const noexcept;
    std::size_t dim()  const noexcept;
    std::size_t idx(std::size_t i, std::size_t k) const noexcept;
    std::size_t ids2idx(std::size_t i) const noexcept;
    std::size_t idx2ids(std::size_t i) const noexcept;

    double&       q(std::size_t i, std::size_t k)       noexcept;
    const double& q(std::size_t i, std::size_t k) const noexcept;
    double&       p(std::size_t i, std::size_t k)       noexcept;
    const double& p(std::size_t i, std::size_t k) const noexcept;

    std::span<double>       q(std::size_t i)       noexcept;
    std::span<const double> q(std::size_t i) const noexcept;
    std::span<double>       p(std::size_t i)       noexcept;
    std::span<const double> p(std::size_t i) const noexcept;
private:
    const std::size_t _D;
    std::size_t _N;

    std::vector<std::size_t> _ids2idx;
    std::vector<std::size_t> _idx2ids;
    std::vector<std::size_t> _free_ids; // i dont really want to have this but prevents bloat

    std::vector<double> _q;
    std::vector<double> _p;
};

#endif