extends Node


func _ready() -> void:
	var stack := Stack.new()
	stack.set_strict_type()
	print(stack.get_expected_type())
	
	stack.push(42)  # first push sets the expected type
	stack.push(73)
	stack.pop()
	print(stack.get_expected_type())
	
	stack.push("hello")  # type mismatch, should error
