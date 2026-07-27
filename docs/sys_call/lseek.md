# lseek systemcall

The lseek system call repositions the file offset of an open file descriptor, enabling random access to file content by changing the current read/write position.

## Syntax for lseek systemcall

```c
off_t lseek(int fd, off_t offset, int whence)
```

- `offset` - means the number of bytes to read from the curr position of the file.
- `whence` - refer the initial position of the file offset.

> the initial position of the file offset will be whence + offset.

### whence

- `SEEK_SET` - sets the offset to the beginning of the file plus the offset value
- `SEEK_CUR` - sets the offset to the current offset plus the offset value
- `SEEK_END` - sets the offset to the end of the file

On success, it returns the new file offset measured in bytes from the beginning of the file; on error, it returns -1. It is particularly useful for navigating large files or creating sparse files by seeking beyond the current end of the file.
