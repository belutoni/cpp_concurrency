//
// Created by Antonie Gabriel Belu on 01/10/2026.
//

#ifndef CPP_CONCURRENCY_THREAD_GUARD_H
#define CPP_CONCURRENCY_THREAD_GUARD_H

#include "concurrency_concepts.h"

template <JoinableThread ThreadType>
class thread_guard {
    ThreadType& m_thread;
public:
    explicit thread_guard(ThreadType& thread) : m_thread(thread) {}

    ~thread_guard() {
        if (m_thread.joinable()) {
            m_thread.join();
        }
    }

    thread_guard& operator=(thread_guard const& other) = delete;
    thread_guard(thread_guard const& other) = delete;
};


#endif //CPP_CONCURRENCY_THREAD_GUARD_H
