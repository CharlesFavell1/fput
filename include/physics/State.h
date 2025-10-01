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

    std::size_t size() const noexcept;
    std::size_t dim()  const noexcept;
    std::size_t idx(std::size_t i, std::size_t k) const noexcept;

    double&       q(std::size_t i, std::size_t k)       noexcept;
    const double& q(std::size_t i, std::size_t k) const noexcept;
    double&       p(std::size_t i, std::size_t k)       noexcept;
    const double& p(std::size_t i, std::size_t k) const noexcept;

    std::span<double>       q(std::size_t i)       noexcept;
    std::span<const double> q(std::size_t i) const noexcept;
    std::span<double>       p(std::size_t i)       noexcept;
    std::span<const double> p(std::size_t i) const noexcept;
private:
    const std::size_t N;
    const std::size_t D;
    std::vector<double> _q;
    std::vector<double> _p;
};

#endif