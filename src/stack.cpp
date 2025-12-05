#include "stack.h"


void Stack::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("get_expected_type"), &Stack::get_expected_type);
	godot::ClassDB::bind_method(D_METHOD("set_strict_type"), &Stack::set_strict_type);
	godot::ClassDB::bind_method(D_METHOD("push", "value"), &Stack::push);
	godot::ClassDB::bind_method(D_METHOD("pop"), &Stack::pop);
	godot::ClassDB::bind_method(D_METHOD("peek"), &Stack::peek);
}

Stack::Stack()
    : m_Elements{}, m_ExpectedType{ Variant::Type::NIL }, m_IsStrictlyTyped{ false } {
}

void Stack::set_strict_type() {
    if (!m_Elements.empty()) {
        ERR_PRINT("Stack::set_strict_type(): Cannot set strict type while elements are inserted.");
        return;
    }
    m_IsStrictlyTyped = true;
}

Variant::Type Stack::get_expected_type() const {
    return m_ExpectedType;
}

void Stack::push(const Variant &value) {
    if (m_ExpectedType == Variant::Type::NIL) {
        // Strict type not yet defined
        m_ExpectedType = value.get_type();
    } else if (m_IsStrictlyTyped) {
        ERR_FAIL_COND_MSG(m_ExpectedType != value.get_type(),
            "Stack::push(): Type mismatch, expected " + Variant::get_type_name(m_ExpectedType)
            + " but got " + Variant::get_type_name(value.get_type())
        );
    }

	m_Elements.push_back(value);
}

Variant Stack::pop() {
    ERR_FAIL_COND_V_MSG(m_Elements.empty(), Variant{}, "Stack::pop() called on empty stack");

    auto value = m_Elements.back();
    m_Elements.pop_back();
	return value;
}

Variant Stack::peek() const {
    ERR_FAIL_COND_V_MSG(m_Elements.empty(), Variant{}, "Stack::peek() called on empty stack");

    return m_Elements.back();
}
