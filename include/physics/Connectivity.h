//
// Created by charlesfavell on 30/09/2025.
//

#ifndef FPUT_CONNECTIVITY_H
#define FPUT_CONNECTIVITY_H
#include <cstddef>
#include <span>
#include <vector>

struct Edge {std::size_t i, j;};

enum class BC {Free, Periodic};

class Connectivity {
public:
    virtual ~Connectivity() = default;

    virtual std::size_t sites() const noexcept = 0;
    virtual std::span<const Edge> edges() const noexcept = 0;
};



#endif //FPUT_CONNECTIVITY_H

