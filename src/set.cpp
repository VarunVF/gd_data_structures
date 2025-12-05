#include "set.h"

void Set::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("add", "element"), &Set::add);
	godot::ClassDB::bind_method(D_METHOD("has", "element"), &Set::has);
	godot::ClassDB::bind_method(D_METHOD("clear"), &Set::clear);
	godot::ClassDB::bind_method(D_METHOD("erase", "element"), &Set::erase);
}

void Set::add(const Variant &element) {
    m_Dictionary[element] = Variant::NIL;
}

bool Set::has(const Variant &element) const {
    return m_Dictionary.has(element);
}

void Set::clear() {
    m_Dictionary.clear();
}

void Set::erase(const Variant & element) {
    m_Dictionary.erase(element);
}
