//
// Created by Antonie Gabriel Belu on 02/10/2026.
//

#ifndef CPP_CONCURRENCY_SCOPED_LOCK_H
#define CPP_CONCURRENCY_SCOPED_LOCK_H

#include "concurrency_concepts.h"
#include <mutex>
#include <tuple>

template<Lockable... MutexTypes>
class scoped_lock;

template <>
class scoped_lock<> {
public:
    explicit scoped_lock() = default;
    explicit scoped_lock(std::adopt_lock_t) noexcept {}
    ~scoped_lock() = default;

    scoped_lock& operator=(scoped_lock const& other) = delete;
    scoped_lock(scoped_lock const& other) = delete;
};

template<Lockable MutexType>
class scoped_lock<MutexType> {
    MutexType& m_mutex;
public:
    explicit scoped_lock(MutexType& mutex) : m_mutex(mutex) {
        m_mutex.lock();
    }

    explicit scoped_lock(std::adopt_lock_t, MutexType& mutex) noexcept : m_mutex(mutex) {}


    ~scoped_lock() {
        m_mutex.unlock();
    }

    scoped_lock& operator=(scoped_lock const& other) = delete;
    scoped_lock(scoped_lock const& other) = delete;
};

template<Lockable FirstM, Lockable SecondM, Lockable... Rest>
class scoped_lock<FirstM, SecondM, Rest...> {
    std::tuple<FirstM&, SecondM&, Rest&...> m_mutexes;
public:
    explicit scoped_lock(FirstM& f, SecondM& s, Rest&... r) : m_mutexes(f, s, r...) {
        std::lock(f, s, r...);
    }

    explicit scoped_lock(std::adopt_lock_t, FirstM& f, SecondM& s, Rest&... r) noexcept : m_mutexes(f, s, r...) {}

    ~scoped_lock() {
        std::apply([](auto&... m) {
            (m.unlock(), ...);
        }, m_mutexes);
    }

    scoped_lock& operator=(scoped_lock const& other) = delete;
    scoped_lock(scoped_lock const& other) = delete;
};

#endif //CPP_CONCURRENCY_SCOPED_LOCK_H
