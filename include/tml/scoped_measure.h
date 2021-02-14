#pragma once

#include "operation.h"

namespace tml {
    class scoped_measure {
    public:
        explicit scoped_measure(const std::string& name) :
            operation_id_(operation_started(name)) {
        }

        ~scoped_measure() noexcept {
            try {
                operation_ended(operation_id_, std::uncaught_exception() ? operation_result::kSucceeded : operation_result::kFailed);
            } catch (...) {

            }
        }

        scoped_measure(const scoped_measure&) = delete;
        scoped_measure& operator=(const scoped_measure&) = delete;
        scoped_measure(scoped_measure&&) = delete;
        scoped_measure& operator=(scoped_measure&&) = delete;

    private:
        operation_id_t operation_id_;
    };
}
