extends Node

func _ready() -> void:
	#test_stack()
	test_set()


func test_stack() -> void:
	var stack := Stack.new()
	stack.set_strict_type()
	print(stack.get_expected_type())
	
	stack.push(42)  # first push sets the expected type
	stack.push(73)
	stack.pop()
	print(stack.get_expected_type())
	
	stack.push("hello")  # type mismatch, should error


func test_set() -> void:
	var items = Set.new()
	items.add(5)
	items.add(6)
	print(items.has(5))

	items.erase(5)
	print(items.has(5))
