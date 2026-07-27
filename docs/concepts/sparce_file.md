# Sparse Files

A `sparse file` is a file that contains empty (zero-filled) regions called `holes`. These holes are not physically stored on disk, allowing the file to have a large logical size while using much less actual storage.

## Key Characteristics

- Has a logical size larger than its physical disk usage.
- Reading a hole returns zero bytes, even though no disk blocks are allocated for it.
- Commonly used for virtual machine disk images, databases, backups, and container storage.
