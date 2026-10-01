#include <iostream>
#include <array>
#include <mutex>
#include <thread>

#include "thread_guard.h"
#include "scoped_thread.h"
#include "lock_guard.h"

struct Order {
    int         id;
    std::string name;
    int         price_in_ron;
};

constexpr std::array orders = {
    Order{ .id = 1, .name = "Coca-Cola",         .price_in_ron = 5 },
    Order{ .id = 2, .name = "Gummy Bear",        .price_in_ron = 10 },
    Order{ .id = 3, .name = "A dancing koala",   .price_in_ron = 10000 },
};

std::mutex orders_mutex;

void print_all_orders() {
    for (const auto& order : orders) {
        std::cout << "[" << order.id << "] " << order.name << ", "
            << order.price_in_ron << " RON" << std::endl;
    }
    std::cout << std::endl;
}

void print_all_orders_lg() {
    lock_guard<std::mutex> lock(orders_mutex);
    for (const auto& order : orders) {
        std::cout << "[" << order.id << "] " << order.name << ", "
            << order.price_in_ron << " RON" << std::endl;
    }
}

int main() {
    scoped_thread<std::thread> t1{std::thread(print_all_orders_lg)};
    scoped_thread<std::thread> t2{std::thread(print_all_orders_lg)};
    return 0;
}
