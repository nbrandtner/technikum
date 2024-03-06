#!/bin/bash
# KONF - Exercise Sheet 1
# by Niklas Brandtner 26.02.2024

#1
git checkout -b development

#2
git log-all

#3
echo "and another line" >> test.txt
git add test.txt
git status
git log-all

#4
git diff .

#5
git commit -m "2.5 Commit changes"
git log-all

#6
git reset --soft HEAD~1
git log-all

#7
git commit -m "2.5 Commit changes (again)"
git log-all

#8
touch .gitignore
echo "*.o" >> .gitignore
touch test.o
git add test.o

#9
# only textbased answer

#10
git checkout -b featureA
touch featureA.txt
echo "I am feature A" >> featureA.txt
git add .
git commit -m "Add featureA.txt" .
git log-all

#11
git stash
git checkout -b featureB
touch featureB.txt
echo "I am feature B" >> featureB.txt
git add .
git commit -m "Add featureB.txt" .
git log-all
git checkout main
git merge featureB
git log-all
git checkout featureA
git stash apply
git log-all

#12
echo "I am feature A and I am done" >> featureA.txt
git add .
git commit -m "Finish feature A"
git log-all
git checkout main
git merge featureA
git log-all

#13
git branch -d featureB
git branch -d featureA