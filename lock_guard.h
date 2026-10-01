//
// Created by Antonie Gabriel Belu on 01/10/2026.
//

#ifndef CPP_CONCURRENCY_LOCK_GUARD_H
#define CPP_CONCURRENCY_LOCK_GUARD_H

#include <concepts>

template <typename T>
concept Lockable = requires(T mutex)
{
    { mutex.lock() }        -> std::same_as<void>;
    { mutex.unlock() }      -> std::same_as<void>;
    { mutex.try_lock() }    -> std::same_as<bool>;
};

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
