extends Node


func _ready() -> void:
	print("\n=== STACK TESTS ===")
	test_basic()
	test_empty_pop()
	test_strict_typing()
	test_order()
	print("=== STACK TESTS DONE ===\n")

func test_basic():
	var s := Stack.new()
	s.push(10)
	s.push(20)
	assert(s.pop() == 20)
	assert(s.pop() == 10)

func test_empty_pop():
	var s := Stack.new()
	var v = s.pop()  # Should print error and return null
	assert(v == null)

func test_strict_typing():
	var s := Stack.new()
	s.set_strict_type()
	s.push(1)
	s.push(2)
	s.push("hello") # Should print error and be ignored
	assert(s.pop() == 2)
	assert(s.pop() == 1)

func test_order():
	var s := Stack.new()
	for i in 5:
		s.push(i)
	for i in range(4, -1, -1):
		assert(s.pop() == i)
