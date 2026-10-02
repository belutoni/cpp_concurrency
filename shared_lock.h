//
// Created by Antonie Gabriel Belu on 02/10/2026.
//

#ifndef CPP_CONCURRENCY_SHARED_LOCK_H
#define CPP_CONCURRENCY_SHARED_LOCK_H

#include "concurrency_concepts.h"

template <SharedLockable SharedMutexType>
class shared_lock {
    SharedMutexType& m_shared_mtx;
public:
    explicit shared_lock(SharedMutexType& mutex) : m_shared_mtx(mutex) {
        m_shared_mtx.lock_shared();
    }
    ~shared_lock() {
        m_shared_mtx.unlock_shared();
    }

    shared_lock& operator=(shared_lock const& other) = delete;
    shared_lock(shared_lock const& other) = delete;
};

#endif //CPP_CONCURRENCY_SHARED_LOCK_H
