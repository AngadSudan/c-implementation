#!/bin/bash

LOG_FILE="server_access.log"

sed -E -i '/^#/d' "$LOG_FILE"

sed -E -i 's/HTTP\/1\.0/HTTP\/1.1/g' "$LOG_FILE"

sed -E -i 's/[0-9]{4}-?[0-9]{4}-?[0-9]{4}-?[0-9]{4}/XXXX-XXXX-XXXX-XXXX/g' "$LOG_FILE"

echo "Log cleanup completed!"