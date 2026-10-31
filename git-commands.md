# Git Practice Record

This document records the Git commands used throughout the development of the **git-practice-BT25CSE194** repository and explains their purpose, along with a detailed report on how a merge conflict was created and resolved.

---

## 1. List of Git Commands Used

### 1.1 Repository Setup & Configuration
- `git init -b main`: Initializes a new local Git repository with `main` as the default branch.
- `git config user.name "Tejas Chandane"`: Sets the commit author name for the repository.
- `git config user.email "tejas@example.com"`: Sets the commit author email for the repository.
- `git config --list`: Displays all active Git configuration settings.
- `git remote add origin https://github.com/tejaschandane-cyber/git-practice-BT25CSE194.git`: Links the local repository to the remote GitHub repository.
- `git remote -v`: Verifies the configured remote URL for fetch and push operations.

### 1.2 Staging & Commits
- `git status`: Checks the status of the working directory and staging area (untracked, modified, or staged files).
- `git status --short`: Displays a concise status output with two-letter status flags.
- `git add <file>`: Stages modifications or new files for the next commit.
- `git add .`: Stages all changes across the repository.
- `git diff`: Shows unstaged changes between the working tree and the staging area (index).
- `git diff --staged`: Shows staged changes prepared for the next commit against `HEAD`.
- `git commit -m "<message>"`: Records staged snapshots into repository history with a meaningful, descriptive message.
- `git commit --amend`: Edits the most recent commit message or adds additional staged changes.

### 1.3 Branching & Integration
- `git branch`: Lists all local branches and indicates the currently active branch.
- `git branch <branch-name>`: Creates a new branch reference without switching to it.
- `git switch <branch-name>` or `git checkout <branch-name>`: Switches the working tree to the specified branch.
- `git switch -c <branch-name>`: Creates and immediately switches to a new branch.
- `git merge <branch-name>`: Integrates changes from the target branch into the current checked-out branch.
- `git merge --abort`: Aborts an in-progress merge conflict and restores the working tree to pre-merge state.
- `git branch -d <branch-name>`: Safely deletes a merged branch.

### 1.4 History, Inspection & Tagging
- `git log`: Displays full commit history including commit hash, author, timestamp, and message.
- `git log --oneline --graph --all`: Visualizes the branching and commit graph in compact form.
- `git show <commit/tag>`: Displays metadata and full diff patch of a specific commit or tag.
- `git tag -a v1.0 -m "Release v1.0"`: Creates an annotated release tag pointing to the current commit.
- `git tag`: Lists all tags in the repository.

### 1.5 Remote Collaboration & Synchronization
- `git push -u origin main`: Pushes local commits to the remote repository and sets up upstream tracking.
- `git push origin --tags`: Pushes all local annotated release tags to GitHub.
- `git fetch origin`: Downloads remote commits, branches, and tags without merging them into working branches.
- `git pull origin main`: Fetches remote updates and integrates them into the current local branch.

### 1.6 Undo, Recovery & Stashing
- `git restore --staged <file>`: Unstages a file while preserving changes in the working directory.
- `git restore <file>`: Discards unstaged modifications in the working tree, reverting to index state.
- `git stash push -m "<note>"`: Temporarily stashes modified and tracked working changes onto a stack.
- `git stash list`: Lists all stashed working states.
- `git stash pop`: Reapplies the most recent stashed changes back into the working directory.
- `git revert <commit-hash>`: Creates a new commit that inverts the changes of an earlier commit without rewriting history.

---

## 2. Merge Conflict Scenario & Resolution

### 2.1 Cause of the Merge Conflict
During feature development, two branches (`main` and `feature/conflict-demo`) made concurrent, conflicting edits to the exact same lines in `README.md` and exercise documentation:
- On branch `main`, the assignment status was committed as:
  ```markdown
  ### Status: Under Active Maintenance (Branch: main)
  - All unit tests verified for Red-Black Tree operations.
  ```
- On branch `feature/conflict-demo`, the status was simultaneously updated as:
  ```markdown
  ### Status: Feature Branch Integration (Branch: feature/conflict-demo)
  - All algorithmic complexity and unit tests finalized.
  ```

When running `git merge feature/conflict-demo` while on branch `main`, Git detected overlapping modifications and paused the merge, displaying:
```
Auto-merging README.md
CONFLICT (content): Merge conflict in README.md
Automatic merge failed; fix conflicts and then commit the result.
```

### 2.2 Conflict Markers Encountered
Opening `README.md` revealed standard Git conflict markers:
```markdown
<<<<<<< HEAD
### Status: Under Active Maintenance (Branch: main)
- All unit tests verified for Red-Black Tree operations.
=======
### Status: Feature Branch Integration (Branch: feature/conflict-demo)
- All algorithmic complexity and unit tests finalized.
>>>>>>> feature/conflict-demo
```

### 2.3 Step-by-Step Resolution Process
1. **Inspection**: Ran `git status` to locate unmerged files (`both modified: README.md`) and `git diff` to view conflicting segments.
2. **Reconciliation**: Manually edited `README.md` to remove markers (`<<<<<<<`, `=======`, `>>>>>>>`) and combined both updates into a unified, accurate section:
   ```markdown
   ### Status: Completed & Verified (Merged main & feature/conflict-demo)
   - All unit tests verified for Red-Black Tree operations.
   - All algorithmic complexity checks and execution tests finalized.
   ```
3. **Staging**: Marked the conflict as resolved using:
   ```bash
   git add README.md
   ```
4. **Verification**: Checked that `git status` showed all changes staged under `Changes to be committed`.
5. **Commit**: Finalized the merge with a descriptive commit message:
   ```bash
   git commit -m "Merge branch 'feature/conflict-demo' - resolve documentation conflict"
   ```
6. **Cleanup**: Verified repository history via `git log --oneline --graph -3` confirming the merge commit, and deleted the merged branch using:
   ```bash
   git branch -d feature/conflict-demo
   ```
