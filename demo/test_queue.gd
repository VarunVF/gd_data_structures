extends Node


func _ready() -> void:
	print("\n=== QUEUE TESTS ===")
	test_basic_enqueue_dequeue()
	test_peek()
	test_empty_dequeue_peek()
	test_clear()
	test_to_from_array()
	print("=== QUEUE TESTS DONE ===\n")

func test_basic_enqueue_dequeue():
	var q = Queue.new()
	q.enqueue(1)
	q.enqueue(2)
	q.enqueue(3)

	assert(q.dequeue() == 1)
	assert(q.dequeue() == 2)
	assert(q.dequeue() == 3)
	assert(q.is_empty())

func test_peek():
	var q = Queue.new()
	q.enqueue("a")
	q.enqueue("b")
	assert(q.peek() == "a")
	assert(q.size() == 2)
	q.dequeue()
	assert(q.peek() == "b")
	assert(q.size() == 1)

func test_empty_dequeue_peek():
	var q = Queue.new()
	assert(q.dequeue() == null)  # Should print error and return null
	assert(q.peek() == null)  # Should print error and return null

func test_clear():
	var q = Queue.new()
	q.enqueue(10)
	q.enqueue(20)
	q.clear()
	assert(q.is_empty())
	assert(q.size() == 0)

func test_to_from_array():
	var q = Queue.new()
	q.enqueue(1)
	q.enqueue(2)
	q.enqueue(3)

	var arr = q.to_array()
	assert(arr.size() == 3)
	assert(arr[0] == 1)
	assert(arr[1] == 2)
	assert(arr[2] == 3)

	var q2 = Queue.new()
	q2.from_array(arr)
	assert(q2.dequeue() == 1)
	assert(q2.dequeue() == 2)
	assert(q2.dequeue() == 3)
