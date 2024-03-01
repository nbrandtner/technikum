#!/bin/bash
# KONF - Exercise Sheet 1
# by Niklas Brandtner 26.02.2024

mkdir konf-exercise1
cd konf-exercise1

# 1. Initialize Git Repository
git init

# 2. Set up Global Configuration
git config --global user.name "nbrandtner"
git config --global user.email "nbrandtner@gmx.at"
git config --global --list --show-origin

# 3. Create a Text File
touch test.txt
echo "Hello World!" > test.txt
cat test.txt

# 4. Check Status
git status

# 5. Add File to Repository
git add test.txt
git commit -m "Add test.txt with 'Hello World!"

# 6. Find SHA-1 of Blob Object
SHA1_blob=$(git hash-object test.txt)

# 7. Output Contents via SHA1
git cat-file -p $SHA1_blob

# 8. Find SHA-1 of "Hello World!"
SHA1_hello=$(echo -n "Hello World!" | git hash-object --stdin)

# 9. Save "Hello World!" in Repository
echo -n "Hello World!" | git hash-object -w --stdin

# 10. Create First Commit Object
tree_sha1=$(git write-tree)
commit_sha1=$(echo 'This is a commit object' | git commit-tree $tree_sha1)
git show $commit_sha1

# 11. Configure Alias for History Output
git config --global alias.lol "log --graph --decorate --oneline --all"

# 12. Output History with Alias
git lol

# 13. Create Another File and Commit
touch another_test.txt
git add another_test.txt
git commit -m "Add another_test.txt"

# 14. Modify History to Add Forgotten File
touch forgotten_test.txt
git add forgotten_test.txt
git commit --amend --no-edit

# 15. Delete and Restore File
git rm another_test.txt
git checkout HEAD -- another_test.txt

# 16. Modify Files and Commit Changes
echo -e "\n again!" >> test.txt
git status
git add test.txt
git commit -m "Modify test.txt"
git log

# 17. Checkout Previous Version
penultimate_commit_hash=$(git log --oneline -n 2 | tail -n 1 | cut -d ' ' -f 1) # get hash of penultimate commit by cutting the first word of the second line of the log
git checkout $penultimate_commit_hash

# 18. View History Again
git lol

# 19. Go Back to Main
git checkout master

# 20. Delete Repository
cd ..
rm -rf konf-exercise1
```