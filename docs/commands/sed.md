# sed

`sed` is a Unix and Linux stream editor used to filter and transform text. It reads input, applies editing commands, and writes the result to standard output. It is especially useful for search-and-replace operations, line selection, and automated text processing.

## What `sed` does

- Processes text line by line
- Performs substitutions, deletions, insertions, and transformations
- Works on files or from standard input
- Often used in shell scripts and command pipelines

## Basic syntax

```bash
sed [options] 'script' file
```

## Common examples

### Replace text

Replace all occurrences of `old` with `new`:

```bash
sed 's/old/new/g' file.txt
```

Replace only the first occurrence:

```bash
sed 's/old/new/' file.txt
```

### Delete lines

Delete all lines containing a pattern:

```bash
sed '/pattern/d' file.txt
```

### Print specific lines

Print only line 10:

```bash
sed -n '10p' file.txt
```

Print lines 10 to 20:

```bash
sed -n '10,20p' file.txt
```

### Edit a file in place

Modify a file directly:

```bash
sed -i 's/old/new/g' file.txt
```

### Use with pipes

Process output from another command:

```bash
ls | sed 's/^/FILE: /'
```

## Useful options

- `-n`: suppress automatic printing
- `-e`: specify multiple editing commands
- `-i`: edit files in place
- `-f`: read commands from a script file

## Notes

`sed` is powerful but the syntax can be compact. In many cases, simple substitutions and line filtering are enough to make it one of the most useful command-line text tools on Linux.
