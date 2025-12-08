#include "queue.h"

void Queue::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("enqueue", "value"), &Queue::enqueue);
	godot::ClassDB::bind_method(D_METHOD("dequeue"), &Queue::dequeue);
	godot::ClassDB::bind_method(D_METHOD("peek"), &Queue::peek);
	godot::ClassDB::bind_method(D_METHOD("clear"), &Queue::clear);
	godot::ClassDB::bind_method(D_METHOD("size"), &Queue::size);
	godot::ClassDB::bind_method(D_METHOD("is_empty"), &Queue::is_empty);
	godot::ClassDB::bind_method(D_METHOD("to_array"), &Queue::to_array);
	godot::ClassDB::bind_method(D_METHOD("from_array", "array"), &Queue::from_array);
}

void Queue::enqueue(const Variant &value) {
	m_Queue.push_back(value);
}

Variant Queue::dequeue() {
    ERR_FAIL_COND_V_MSG(m_Queue.empty(), Variant{},
        "Queue::dequeue(): Cannot dequeue from empty queue");
    
	Variant next = m_Queue.front();
    m_Queue.pop_front();
    return next;
}

Variant Queue::peek() const {
    ERR_FAIL_COND_V_MSG(m_Queue.empty(), Variant{},
        "Queue::peek(): Cannot peek an empty queue");
    
	return m_Queue.front();
}

void Queue::clear() {
    m_Queue.clear();
}

int Queue::size() const {
	return m_Queue.size();
}

bool Queue::is_empty() const {
	return m_Queue.empty();
}

Array Queue::to_array() const {
	Array array;
    array.resize(m_Queue.size());
    for (int i = 0; i < m_Queue.size(); i++)
        array[i] = m_Queue[i];
    return array;
}

void Queue::from_array(const Array& array) {
    m_Queue.resize(array.size());
    for (int i = 0; i < m_Queue.size(); i++)
        m_Queue[i] = array[i];
}
