extends Node


func _ready() -> void:
	print("\n=== SET TESTS ===")
	test_basic()
	test_duplicates()
	test_erase()
	#test_strict_typing()
	#test_to_array()
	print("=== SET TESTS DONE ===\n")

func test_basic():
	var s := Set.new()
	s.add("a")
	s.add("b")
	assert(s.has("a"))
	assert(s.has("b"))
	assert(!s.has("c"))

func test_duplicates():
	var s := Set.new()
	s.add(10)
	s.add(10)
	s.add(10)
	assert(s.size() == 1)

func test_erase():
	var s := Set.new()
	s.add("x")
	s.add("y")
	assert(s.erase("x"))
	assert(!s.has("x"))
	assert(!s.erase("x")) # already removed

# Not implemented
#func test_strict_typing():
	#var s := Set.new()
	#s.set_strict_type()
	#s.add(1)
	#s.add(2)
	#s.add("nope")
	#assert(s.size() == 2)

# Not implemented
#func test_to_array():
	#var s := Set.new()
	#s.add("a")
	#s.add("b")
	#var arr = s.to_array()
	#assert(arr.size() == 2)
	#assert("a" in arr)
	#assert("b" in arr)
