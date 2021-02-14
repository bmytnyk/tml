#include "operation.h"

#include <deque>
#include <stdexcept>
#include <mutex>

namespace tml {
    std::atomic<operation_id_t> cur_operation_id;

    using current_operations_map = std::unordered_map<operation_id_t, operation_in_progress_info>;

    current_operations_map current_operations;

    std::mutex current_operations_lock;

    using category_info_map = std::unordered_map<std::string, std::deque<operation_info>>;

    category_info_map completed_operations;

    std::mutex completed_operations_lock;

    operation_id_t operation_started(const std::string& name) {
        ++cur_operation_id;

        const operation_id_t new_operation_id = cur_operation_id.load();

        operation_in_progress_info info{ name, clock::now() };

        {
            std::lock_guard<std::mutex> auto_lock(current_operations_lock);
            current_operations[new_operation_id] = info;
        }

        return new_operation_id;
    }

    void operation_ended(operation_id_t operation_id, operation_result result) {
        const auto it = current_operations.find(operation_id);
        if (it == current_operations.end())
            throw std::invalid_argument("Invalid operation_id");

        const double duration = (clock::now() - it->second.start_point_).count();

        {
            // add to completed operations
            std::lock_guard<std::mutex> auto_lock(completed_operations_lock);
            completed_operations[it->second.name_].emplace_back(result, it->second.start_point_, duration);
        }

        {
            // remove from current operations
            std::lock_guard<std::mutex> auto_lock(current_operations_lock);
            current_operations.erase(it);
        }
    }

    operation_statistics get_operation_statistics(const std::string& name) {
        return operation_statistics{0.0, 0.0, 0.0};
    }
};