# GitHub Personal Access Token Setup

## Why Use a Token?

GitHub requires Personal Access Tokens (PAT) for HTTPS authentication. Passwords are no longer supported for git operations.

## Step 1: Create a Personal Access Token

1. Go to [GitHub Settings → Developer Settings → Personal Access Tokens](https://github.com/settings/tokens)
2. Or navigate: GitHub Profile Picture → Settings → Developer settings → Personal access tokens → Tokens (classic)
3. Click **"Generate new token"** → **"Generate new token (classic)"**
4. Give it a name: `CP Solutions Auto-Push`
5. Set expiration: Choose duration (recommend 90 days or 1 year)
6. Select scopes (**important**):
   - ✅ **repo** (Full control of private repositories) - This is all you need!
7. Scroll down and click **"Generate token"**
8. **⚠️ COPY THE TOKEN NOW** - You won't be able to see it again!

## Step 2: Configure Git to Use Token

### Option A: Store Token in Git Credential Helper (Recommended)

This securely caches your credentials:

```bash
# Enable credential helper
git config --global credential.helper store

# Or use cache (stores for 15 minutes by default)
git config --global credential.helper cache

# Or cache for longer (e.g., 1 hour = 3600 seconds)
git config --global credential.helper 'cache --timeout=3600'
```

Then when you push:
```bash
git push -u origin main
```

It will ask for:
- **Username:** Your GitHub username
- **Password:** Paste your Personal Access Token (not your GitHub password!)

The token will be saved and reused automatically.

### Option B: Include Token in Remote URL

⚠️ **Less secure** - Token is stored in plaintext in `.git/config`

```bash
# Format: https://TOKEN@github.com/USERNAME/REPO.git
git remote set-url origin https://YOUR_TOKEN@github.com/YOUR_USERNAME/competitive-programming.git
```

Replace:
- `YOUR_TOKEN` - Your personal access token
- `YOUR_USERNAME` - Your GitHub username
- `competitive-programming` - Your repo name

## Step 3: Test It

```bash
# Test with a commit
cd /home/b1ank/Documents/codeCP
git add .
git commit -m "Test commit"
git push -u origin main
```

If using Option A, enter your token when prompted. If using Option B, it should push without prompting.

## Step 4: Verify Auto-Push Works

1. Make a small change to any `.cpp` file
2. Save it
3. If auto-push is running, check your GitHub repo in ~5-30 seconds
4. You should see the new commit!

## Security Best Practices

✅ **DO:**
- Use credential helper (Option A) - more secure
- Set token expiration
- Use fine-grained tokens if available
- Regenerate tokens periodically

❌ **DON'T:**
- Share your token with anyone
- Commit your token to a repository
- Use the same token for everything
- Give tokens more permissions than needed

## Troubleshooting

### "Authentication failed" error:
- Token might have expired - generate a new one
- Token might not have `repo` scope - check permissions
- Wrong username/token - verify credentials

### Token expired:
1. Generate a new token (same steps as above)
2. Update stored credentials:
   ```bash
   # If using credential helper
   git credential reject
   # Then paste:
   protocol=https
   host=github.com
   # Press Enter twice, then push again to re-enter credentials
   
   # If using URL method
   git remote set-url origin https://NEW_TOKEN@github.com/USERNAME/REPO.git
   ```

### Check current remote URL:
```bash
git remote -v
```

## Alternative: SSH Keys (More Secure)

If you prefer SSH over HTTPS:

1. Generate SSH key:
```bash
ssh-keygen -t ed25519 -C "your-email@example.com"
```

2. Add to GitHub: Settings → SSH and GPG keys → New SSH key
3. Copy public key:
```bash
cat ~/.ssh/id_ed25519.pub
```

4. Update remote URL:
```bash
git remote set-url origin git@github.com:USERNAME/competitive-programming.git
```

SSH doesn't require tokens - authentication is key-based.

## Quick Reference

### Using Token with Git:
```bash
# HTTPS with token (when prompted for password, use token)
git push

# Or include in URL
git remote set-url origin https://TOKEN@github.com/USER/REPO.git
```

### Manage Stored Credentials:
```bash
# View credential helper
git config --global credential.helper

# Clear cached credentials
git credential-cache exit

# Remove stored credentials (store method)
rm ~/.git-credentials
```
