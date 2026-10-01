//
// Created by Antonie Gabriel Belu on 01/10/2026.
//

#ifndef CPP_CONCURRENCY_LOCK_GUARD_H
#define CPP_CONCURRENCY_LOCK_GUARD_H

#include "concurrency_concepts.h"

template <Lockable MutexType>
class lock_guard {
    MutexType& m_mutex;
public:
    explicit lock_guard(MutexType& mutex) : m_mutex(mutex) {
        m_mutex.lock();
    }
    ~lock_guard() {
        m_mutex.unlock();
    }

    lock_guard& operator=(lock_guard const& other) = delete;
    lock_guard(lock_guard const& other) = delete;
};

#endif //CPP_CONCURRENCY_LOCK_GUARD_H
