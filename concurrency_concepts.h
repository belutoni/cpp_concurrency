//
// Created by Antonie Gabriel Belu on 01/10/2026.
//

#ifndef CPP_CONCURRENCY_CONCURRENCY_CONCEPTS_H
#define CPP_CONCURRENCY_CONCURRENCY_CONCEPTS_H

#include <concepts>

template <typename T>
concept JoinableThread = requires(T thread)
{
    { thread.joinable() }   -> std::same_as<bool>;
    { thread.join() }       -> std::same_as<void>;
    { thread.detach() }     -> std::same_as<void>;
};

template <typename T>
concept Lockable = requires(T mutex)
{
    { mutex.lock() }        -> std::same_as<void>;
    { mutex.unlock() }      -> std::same_as<void>;
    { mutex.try_lock() }    -> std::same_as<bool>;
};

#endif //CPP_CONCURRENCY_CONCURRENCY_CONCEPTS_H
