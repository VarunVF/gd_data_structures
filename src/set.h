#pragma once

#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/variant.hpp"

using namespace godot;

class Set : public RefCounted {
    GDCLASS(Set, RefCounted)

protected:
    static void _bind_methods();

public:
    Set() = default;
    ~Set() = default;

    void add(const Variant &element);
    bool has(const Variant &element) const;
    void clear();
    void erase(const Variant& element);

private:
    Dictionary m_Dictionary;
};
