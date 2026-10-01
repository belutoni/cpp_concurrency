//
// Created by Antonie Gabriel Belu on 01/10/2026.
//

#ifndef CPP_CONCURRENCY_SCOPE_GUARD_H
#define CPP_CONCURRENCY_SCOPE_GUARD_H

#include <concepts>
#include <stdexcept>

template <typename T>
concept JoinableThread = requires(T thread)
{
    { thread.joinable() }   -> std::same_as<bool>;
    { thread.join() }       -> std::same_as<void>;
    { thread.detach() }     -> std::same_as<void>;
};

template <JoinableThread ThreadType>
class scoped_thread {
    ThreadType m_thread;
public:
    explicit scoped_thread(ThreadType thread) : m_thread(std::move(thread)) {
        if (!m_thread.joinable()) {
            throw std::invalid_argument("Pass a joinable thread");
        }
    }

    ~scoped_thread() {
        m_thread.join();
    }

    scoped_thread& operator=(scoped_thread const& other) = delete;
    scoped_thread(scoped_thread const& other) = delete;
};

#endif //CPP_CONCURRENCY_SCOPE_GUARD_H
