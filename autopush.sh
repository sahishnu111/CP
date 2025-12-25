#!/bin/bash

# Auto Git Push Script for CP Solutions
# This script watches for file changes and automatically commits & pushes to GitHub

WATCH_DIR="/home/b1ank/Documents/codeCP"
LOG_FILE="/home/b1ank/Documents/codeCP/.autopush.log"

# Function to log messages
log_message() {
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] $1" | tee -a "$LOG_FILE"
}

# Function to commit and push changes
auto_commit_push() {
    cd "$WATCH_DIR" || exit 1
    
    # Add all changes
    git add -A
    
    # Check if there are changes to commit
    if ! git diff --staged --quiet; then
        # Create a commit message with timestamp and changed files
        CHANGED_FILES=$(git diff --staged --name-only | head -5 | tr '\n' ', ' | sed 's/,$//')
        COMMIT_MSG="Auto-commit: $(date '+%Y-%m-%d %H:%M:%S') - Updated: $CHANGED_FILES"
        
        git commit -m "$COMMIT_MSG"
        
        # Push to remote
        if git push origin main 2>&1 | tee -a "$LOG_FILE"; then
            log_message "✓ Successfully pushed changes to GitHub"
        else
            log_message "✗ Failed to push changes to GitHub"
        fi
    fi
}

# Initial setup check
if ! git remote get-url origin &>/dev/null; then
    log_message "WARNING: No remote 'origin' configured. Please run:"
    log_message "git remote add origin <your-github-repo-url>"
    exit 1
fi

log_message "Starting auto-push watcher for $WATCH_DIR"

# Check if inotify-tools is installed
if ! command -v inotifywait &> /dev/null; then
    log_message "ERROR: inotify-tools not installed. Installing..."
    sudo apt-get update && sudo apt-get install -y inotify-tools
fi

# Watch for file changes and auto-commit/push
inotifywait -m -r -e modify,create,delete,move "$WATCH_DIR" \
    --exclude '\.git|\.autopush\.log' \
    --format '%w%f %e' |
while read -r file event; do
    log_message "Detected change: $event on $file"
    
    # Wait a bit to batch multiple rapid changes
    sleep 5
    
    # Commit and push
    auto_commit_push
done
