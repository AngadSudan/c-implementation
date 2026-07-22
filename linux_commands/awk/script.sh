#!/bin/bash

FILE="employees.txt"

echo "Task 1"
awk -F',' '{print $1, $2}' "$FILE"

echo

echo "Task 2"
awk -F',' '$2 == "Engineering"' "$FILE"

echo

echo "Task 3"
awk -F',' '{printf "%s gross pay: $%d\n", $1, $3 * $4}' "$FILE"

echo

echo "Task 4"
awk -F',' '{printf "%d (%d fields): %s\n", NR, NF, $0}' "$FILE"

echo

echo "Task 5"
awk -F',' '
BEGIN {
    total = 0
}
$2 == "Engineering" {
    total += $3 * $4
}
END {
    printf "Total Engineering Payroll: $%d\n", total
}
' "$FILE"
