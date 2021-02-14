#pragma once

#include <cstdint>
#include <atomic>
#include <chrono>
#include <string>

namespace tml {
    using operation_id_t = uint64_t;

    using clock = std::chrono::steady_clock;

    using time_point = std::chrono::time_point<clock>;

    using duration = double;
};

