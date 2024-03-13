#!/bin/bash

# Task 1: Set up remote repository
# (Already done on GitHub/GitLab)

# Task 2: Cloning
git clone <repository_link>

# Task 3: Add Remote
git init
git remote add origin <repository_link>
git fetch
git merge origin/main

# Task 4: New files
# First Repository
touch newFile1.txt
git add newFile1.txt
git commit -m "Add newFile1.txt"
git push origin main

# Second Repository
cd ..
mkdir second_repo
cd second_repo
git init
git remote add origin <repository_link>
git fetch
git merge origin/main
touch newFile2.txt
git add newFile2.txt
git commit -m "Add newFile2.txt"
git push origin main
cd ..

# Task 5: Conflict
# Simulate conflict manually

# Task 6: Tagging
# In one of the repositories, let's say the first one
cd first_repo
git tag -a v1.0.0 -m "Version 1.0.0"
git push origin v1.0.0
cd ..
# Pull changes in the second repository to get the tag

# Task 7: Two Features
# Create and push feature branches in both repositories

# First Repository
git checkout -b feature1
# Make changes, commit
git push origin feature1

# Second Repository
cd second_repo
git checkout -b feature2
# Make changes, commit
git push origin feature2
cd ..

# Merge feature branches into main/master in both repositories

# Task 8: Major and Minor
# Create and push deployment branch in both repositories

# First Repository
git checkout -b deployment
# Add features for minor versions
# Commit, push
git push origin deployment

# Second Repository
cd second_repo
git checkout -b deployment
# Add features for minor versions
# Commit, push
git push origin deployment
cd ..

# Merge deployment branch into main/master and tag a major version in both repositories

# First Repository
git checkout main
git merge deployment
git tag -a v2.0.0 -m "Version 2.0.0"
git push origin main --tags

# Second Repository
cd second_repo
git checkout main
git merge deployment
git tag -a v2.0.0 -m "Version 2.0.0"
git push origin main --tags