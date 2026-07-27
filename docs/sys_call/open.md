# Open Systemcall

In unix programming whenever you want to access a file from a file system.This associates something called a file Descriptor and returns a handle that the process will use to refer that to a file.

During the `open`, the filesystem may allocate memory for buffers, or it may wait until the first operation. Returns -1 incase of any error in opening the file.

## Syntax for Open systemcall

```c
open(const char* path, int oflag,mode_t mode)
```

- `path` - the actual path of the file the open call is trying to read
- `oflag` - these are the actions that are allowed to perfrom by the file descriptor returned by the function call
- `mode` - an optional field only relevant when creating file as it allocates the file permissions.

### Oflag

The options available for OFlags are

- `O_RDONLY` - only read permitted to the file descriptor
- `O_WRONLY` - only write permitted to the file descriptor
- `O_RDWR` - both read and write permitted to the file descriptor
- `O_APPEND` - data written will be appended to the end of the file.
- `O_CREAT` - Create the file if it does not exist
- `O_TRUNC` - If the file already exists then discard its previous contents, reducing it to an empty file.

### mode

The options available for mode are

| Symbol    | Octal   | Description                                               |
| --------- | ------- | --------------------------------------------------------- |
| `S_IRWXU` | `00700` | User (file owner) has read, write, and execute permission |
| `S_IRUSR` | `00400` | User has read permission                                  |
| `S_IWUSR` | `00200` | User has write permission                                 |
| `S_IXUSR` | `00100` | User has execute permission                               |
| `S_IRWXG` | `00070` | Group has read, write, and execute permission             |
| `S_IRGRP` | `00040` | Group has read permission                                 |
| `S_IWGRP` | `00020` | Group has write permission                                |
| `S_IXGRP` | `00010` | Group has execute permission                              |
| `S_IRWXO` | `00007` | Others have read, write, and execute permission           |
| `S_IROTH` | `00004` | Others have read permission                               |
| `S_IWOTH` | `00002` | Others have write permission                              |
| `S_IXOTH` | `00001` | Others have execute permission                            |
