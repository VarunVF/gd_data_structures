#pragma once

#include <unordered_set>

#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/variant.hpp"

using namespace godot;

class Set : public RefCounted {
    GDCLASS(Set, RefCounted)

private:
    struct ElementHasher {
        uint32_t operator()(const Variant& variant) const {
            return variant.hash();
        }
    };

    struct ElementKeyEq {
        bool operator()(const Variant& lhs, const Variant& rhs) const {
            return lhs == rhs;
        }
    };

protected:
    static void _bind_methods();

public:
    Set() = default;
    ~Set() = default;

    void add(const Variant& element);
    bool has(const Variant& element) const;
    void clear();
    bool erase(const Variant& element);
    int size() const;

private:
    std::unordered_set<Variant, ElementHasher, ElementKeyEq> m_Set;
};
