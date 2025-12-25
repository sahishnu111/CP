#!/bin/bash

# Quick Commit Script
# Usage: ./quick-commit.sh "your commit message"
# Or just: ./quick-commit.sh (will auto-generate message)

cd /home/b1ank/Documents/codeCP

# Add all changes
git add -A

# Check if there are changes to commit
if ! git diff --staged --quiet; then
    # Use provided message or auto-generate one
    if [ -z "$1" ]; then
        # Auto-generate commit message with changed files
        CHANGED_FILES=$(git diff --staged --name-only | head -3 | tr '\n' ', ' | sed 's/,$//')
        COMMIT_MSG="Update: $CHANGED_FILES - $(date '+%Y-%m-%d %H:%M')"
    else
        COMMIT_MSG="$1"
    fi
    
    # Commit (this will trigger the post-commit hook which auto-pushes)
    git commit -m "$COMMIT_MSG"
    
    echo "✅ Committed and pushed to GitHub!"
else
    echo "ℹ️  No changes to commit"
fi
