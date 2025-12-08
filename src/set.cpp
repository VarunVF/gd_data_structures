#include "set.h"

void Set::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("add", "element"), &Set::add);
	godot::ClassDB::bind_method(D_METHOD("has", "element"), &Set::has);
	godot::ClassDB::bind_method(D_METHOD("clear"), &Set::clear);
	godot::ClassDB::bind_method(D_METHOD("erase", "element"), &Set::erase);
    godot::ClassDB::bind_method(D_METHOD("size"), &Set::size);
}

void Set::add(const Variant& element) {
    m_Set.insert(element);
}

bool Set::has(const Variant& element) const {
    return m_Set.count(element) > 0;
}

void Set::clear() {
    m_Set.erase(m_Set.begin(), m_Set.end());
}

bool Set::erase(const Variant& element) {
    return m_Set.erase(element) > 0;
}

int Set::size() const {
	return static_cast<int>(m_Set.size());
}
