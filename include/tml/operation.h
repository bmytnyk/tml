#pragma once

#include "common.h"

#include <unordered_map>

namespace tml {
    enum class operation_result {
        kSucceeded,
        kFailed,
        kCanceled
    };

    struct operation_info {
        operation_info(operation_result result, time_point start_point, double duration) :
            result_(result),
            start_point_(start_point),
            duration_(duration) {
        }

        operation_result result_;
        time_point start_point_;
        double duration_;
    };

    struct operation_in_progress_info {
        std::string name_;
        time_point start_point_;
    };

    struct operation_statistics {
        double min_duration_;
        double max_duration_;
        double average_duration_;
    };                    

    operation_id_t operation_started(const std::string& name);

    operation_statistics get_operation_statistics(const std::string& name);

    void operation_ended(operation_id_t operation_id, operation_result result);
};


