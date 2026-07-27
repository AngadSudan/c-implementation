# Understanding Inodes in Linux

## What is an Inode?

An **inode** (Index Node) is a data structure used by Linux and Unix-like file systems to store metadata about a file or directory.

> **Important:** An inode does **not** store the file's name or its actual data. Instead, it stores information _about_ the file.

---

## What Does an Inode Store?

Each inode contains metadata such as:

- File size
- File type (regular file, directory, symbolic link, etc.)
- Owner User ID (UID)
- Group ID (GID)
- File permissions
- Number of hard links
- Creation, modification, and access timestamps
- Pointers to the data blocks where the file contents are stored

Example:

```text
Inode #12345

Permissions: rw-r--r--
Owner: alice
Group: developers
Size: 2048 bytes
Created: 2025-01-10
Modified: 2025-01-15
Data Blocks:
    Block 101
    Block 102
    Block 103
```

## Why Inodes Matter

Inodes make the filesystem efficient because:

- Metadata is separate from file names.
- Multiple filenames can reference the same data.
- Directories only store mappings.
- File lookup is fast.

## Hard Links

A hard link is simply another filename pointing to the same inode.

Create one:

```bash
ln notes.txt backup.txt
```

Now:

```
notes.txt ----+
              |
backup.txt ---+
              |
              v
          Inode 4589
```

Both filenames refer to the same inode.

Checking:

```bash
ls -li
```

Output:

```text
4589 notes.txt
4589 backup.txt
```

Notice they have the **same inode number**.

---

## Symbolic Links

A symbolic (soft) link has its **own inode**.

Example:

```bash
ln -s notes.txt shortcut.txt
```

```
shortcut.txt
      |
      v
  (contains path)
      |
      v
notes.txt -----> inode 4589
```

Unlike hard links, symbolic links store the path to another file.
