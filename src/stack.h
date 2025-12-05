#pragma once

#include <vector>

#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

using namespace godot;

class Stack : public RefCounted {
    GDCLASS(Stack, RefCounted)

protected:
    static void _bind_methods();

public:
    Stack();
    ~Stack() = default;

    void set_strict_type();
    Variant::Type get_expected_type() const;
    void push(const Variant &value);
    Variant pop();
    Variant peek() const;

private:
    std::vector<Variant> m_Elements;
    Variant::Type m_ExpectedType;
    bool m_IsStrictlyTyped;
};
