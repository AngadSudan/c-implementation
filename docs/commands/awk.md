# The `awk` Command

## Overview

The `awk` command is a powerful text processing tool for scanning and transforming structured text. It is commonly used for filtering log files, extracting fields, reformatting data, and performing simple calculations on text input.

## Basic Syntax

```bash
awk 'pattern { action }' file
```

## Common Options

- `-F fs`: Use `fs` as the input field separator
- `-f file`: Read the awk program from `file`
- `-v var=value`: Assign a variable before execution
- `-e 'program'`: Use the following string as the awk program

## Examples

### Print every line

```bash
awk '{ print }' data.txt
```

### Print lines matching a pattern

```bash
awk '/error/ { print }' logfile.txt
```

### Print the first field of each line

```bash
awk '{ print $1 }' data.txt
```

### Use a custom delimiter

```bash
awk -F: '{ print $1, $3 }' /etc/passwd
```

### Sum values in the second field

```bash
awk '{ sum += $2 } END { print sum }' numbers.txt
```

### Read the awk program from a file

```bash
awk -f script.awk input.txt
```

## Output Examples

```text
$ awk '{ print $1 }' data.txt
Alice
Bob
Carol
```

```text
$ awk -F: '{ print $1 " has UID " $3 }' /etc/passwd
root has UID 0
daemon has UID 1
```

## Use Cases

- Filter and search text files
- Extract specific columns from tabular data
- Reformat command output
- Process log files
- Perform basic aggregation and calculations

## Notes

- `awk` processes input line by line and splits each line into fields
- `$1`, `$2`, and so on refer to fields; `$0` refers to the whole line
- `BEGIN` and `END` blocks run before and after processing all input lines
- `awk` is especially useful for working with CSV-like or colon-separated data
