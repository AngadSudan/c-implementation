# Read Systemcall

read Systemcall is a unix system call that is used to read the data provided from a file in a file system. The file is identified by its file descriptor.

The system call reads in bytes. The number of bytes read at once is specified by the user and stores them into the buffer.

## Syntax for Open systemcall

```c
read(int fileDescriptor, void* buf, size_t count)
```

- `buf` - the buffer in which the read data will be stored
- `count` - the number of data to be read at once.

It stops reading the values at EOF character and returns a negative value indicating no more data bytes to read.
