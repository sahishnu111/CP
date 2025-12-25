#!/bin/bash

# Simple Auto Git Push Script (Alternative - Cron-based)
# This runs periodically (e.g., every 5 minutes via cron) and pushes changes if any

WATCH_DIR="/home/b1ank/Documents/codeCP"
cd "$WATCH_DIR" || exit 1

# Add all changes
git add -A

# Check if there are changes to commit
if ! git diff --staged --quiet; then
    # Create a commit message with timestamp
    COMMIT_MSG="Auto-commit: $(date '+%Y-%m-%d %H:%M:%S')"
    
    git commit -m "$COMMIT_MSG"
    git push origin main
    
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] Pushed changes to GitHub" >> .autopush.log
fi
