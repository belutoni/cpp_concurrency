//
// Created by Antonie Gabriel Belu on 02/10/2026.
//

#ifndef CPP_CONCURRENCY_SPINLOCK_MUTEX_H
#define CPP_CONCURRENCY_SPINLOCK_MUTEX_H

#include "concurrency_concepts.h"
#include <atomic>

class spinlock_mutex {
    std::atomic_flag m_flag;
public:
    explicit spinlock_mutex() : m_flag(ATOMIC_FLAG_INIT) {}

    void lock() {
        while (m_flag.test_and_set(std::memory_order_acquire));
    }

    void unlock() {
        m_flag.clear(std::memory_order_release);
    }
};

#endif //CPP_CONCURRENCY_SPINLOCK_MUTEX_H
