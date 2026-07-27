# Write System call

Write systemcall is essentially the one which is required inorder to write the data from the buffer into the file provided via the fileDescriptor.

## Syntax for Write systemcall

```c
write(int fileDescriptor,const void* buf, ssize_t nbyte)
```

- `buf` - Points to a character array, with content to be written to the file
- `nbyte` - the number of bytes to be written from the buffer

> we use ssize_t indicating a signed value. write systemcall returns signed value when there's no error otherwise it returns a value -1.
