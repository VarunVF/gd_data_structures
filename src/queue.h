#pragma once

#include <deque>

#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/variant.hpp"

using namespace godot;

class Queue : public RefCounted {
    GDCLASS(Queue, RefCounted)

protected:
    static void _bind_methods();

public:
    Queue() = default;
    ~Queue() = default;

    void enqueue(const Variant& value);
    Variant dequeue();
    Variant peek() const;
    
    void clear();
    int size() const;
    bool is_empty() const;
    
    Array to_array() const;
    void from_array(const Array& array);

private:
    std::deque<Variant> m_Queue;
};
