# Godot Data Structures Extension

A GDExtension providing generic, optionally strictly-typed data structures for Godot.
Currently includes:

- **Stack**: supports `Variant` values, optional strict typing
- **Set**: for storing just keys instead of key-value pairs in a `Dictionary` (not natively available in GDScript)

---

## Features

- Generic storage for any GDScript type
- Optional strict typing
- Safe operations: warnings instead of crashes
- GDScript-friendly API

Example:

```gdscript
var stack := Stack.new()
stack.push(42)
stack.push("hello")  # allowed, strict typing is off
print(stack.pop())  # "hello"
print(stack.pop())  # 42
```

Strict Typing:
```gdscript
var stack := Stack.new()
stack.set_strict_type()
stack.push(10)
stack.push(20)
stack.push("oops")  # prints error
```

## Notes

- Popping/peeking empty containers prints a warning.
- Strict typing can only be set before elements are inserted.
- Containers store `Variant` objects internally.
