# GitHub Repository Setup Guide

## Step 1: Configure Git Identity

Run these commands (replace with your details):
```bash
git config --global user.email "your-email@example.com"
git config --global user.name "Your Name"
```

## Step 2: Create GitHub Repository

1. Go to [GitHub](https://github.com) and log in
2. Click the **"+"** icon in the top right → **"New repository"**
3. Repository name: `competitive-programming` (or any name you prefer)
4. Description: "My competitive programming solutions"
5. Choose **Public** or **Private**
6. **Don't** initialize with README (we already have one)
7. Click **"Create repository"**

## Step 3: Link Local Repo to GitHub

After creating the GitHub repo, run these commands in `/home/b1ank/Documents/codeCP`:

```bash
# Add the remote (replace USERNAME with your GitHub username)
git remote add origin https://github.com/USERNAME/competitive-programming.git

# Commit initial files
git commit -m "Initial commit: CP solutions and auto-push setup"

# Push to GitHub
git push -u origin main
```

## Step 4: Set Up Auto-Push (Choose ONE method)

### Option A: Real-time File Watcher (Recommended)

Automatically pushes whenever you save a file.

1. Install inotify-tools:
```bash
sudo apt-get update && sudo apt-get install -y inotify-tools
```

2. Run the watcher script in background:
```bash
cd /home/b1ank/Documents/codeCP
nohup ./autopush.sh > /dev/null 2>&1 &
```

3. (Optional) Set up as a system service for auto-start:
```bash
sudo cp autopush.service /etc/systemd/system/
sudo systemctl daemon-reload
sudo systemctl enable autopush.service
sudo systemctl start autopush.service

# Check status
sudo systemctl status autopush.service
```

### Option B: Cron-based (Every 5 minutes)

Runs every 5 minutes and pushes if there are changes.

1. Edit crontab:
```bash
crontab -e
```

2. Add this line:
```
*/5 * * * * /home/b1ank/Documents/codeCP/autopush-cron.sh
```

## Step 5: Test It!

1. Create or modify a CP solution file
2. Wait a few seconds (Option A) or up to 5 minutes (Option B)
3. Check your GitHub repo to confirm the auto-push worked!

## Stopping Auto-Push

### Stop File Watcher:
```bash
pkill -f autopush.sh
```

### Stop System Service:
```bash
sudo systemctl stop autopush.service
sudo systemctl disable autopush.service
```

### Remove Cron Job:
```bash
crontab -e  # Then delete the autopush line
```

## Notes

- The `.gitignore` file excludes compiled binaries (*.exe, *.out, a.out)
- Check logs at `/home/b1ank/Documents/codeCP/.autopush.log`
- Auto-commits include timestamp and changed files in the message
- You can still manually commit/push if you prefer more control

## Troubleshooting

**If push fails with authentication error:**
- For HTTPS: GitHub no longer accepts passwords, use a [Personal Access Token](https://github.com/settings/tokens)
- Or switch to SSH: `git remote set-url origin git@github.com:USERNAME/competitive-programming.git`
