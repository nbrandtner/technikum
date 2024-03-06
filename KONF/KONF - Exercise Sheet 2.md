# KONF - Exercise Sheet 2

#### by Niklas Brandtner 6.03.2024

1. **Branching**
   Working in the master/main branch is considered a faux pas in the community. For this reason, create a development branch and check it out. Which 2 command sequences can you use for it? What options do these commands offer?

   - ```bash
     git branch development     # Create a development branch
     git checkout development   # Switch to the development branch
     ```

   - You could also use `git checkout -b development` to create and check out the new branch

2. **Documentation**
   Note in your presentation what specifically happened. What does the history look like now? What happened with HEAD?

   - ![image-20240306082955399](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240306082955399.png)
   - `HEAD` now points to the "development" branch, indicating that this is the currently checked-out branch.

3. **Changes**
   In the first exercise sheet, you have already added a few files. Now change a file in the Development Branch and add these changes to the Staging Area. What does the status look like now? Has the history changed?

   - ![image-20240306084348848](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240306084348848.png)
   - Status tells us `On branch development`
   - ![image-20240306183708213](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240306183708213.png)
   - History hasn't changed
   
4. **Diff**
   Run the git diff command - what does the output look like and how do you interpret it?

   - ![image-20240306183920784](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240306183920784.png)
   - here we see a possible output by `git diff` we can see what files the command has found changes in. It also shows the exact changes.
   
5. **Commit**
   Commit your changes. What does the history look like now and how do you interpret the result?

   - ![image-20240306184425019](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240306184425019.png)
   - the new commit gets added to the log...
   
6. **Accidentally Committed?**
   If you commit once by mistake there is a way to undo the commit. Describe the command. The history should look like before the commit! Which options does the command offer (especially `--soft` and `--hard`)?

   - ![image-20240306185013919](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240306185013919.png)
   
   - `git reset moves HEAD` pointer back by one commit
   -  `git reset –soft HEAD~1` undoes the last commit but leaves modified files in staging area
   - `git reset –hard HEAD~1` undoes the last commit, unstages the changes, and reverts working directory back to previous commit
   
7. **Changes 2**
   Now make changes in the development branch again and commit them.

   - Since I've used --soft in my example i dont need to do changes again because the previous changes are back to the staging area:
   - ![image-20240306185225115](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240306185225115.png)
   
8. **.gitignore**
   Add a .gitignore file to the root directory of your workspace and populate it so that files with the extension .o are not included in the repository. (Note: .o files, i.e. object files, are created by the compiler and can be created again at any time and are therefore not necessarily subject to version control) Now create an .o file and try to add it to the repository.

   - ![image-20240306185401589](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240306185401589.png)
   - <img src="C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240306185411393.png" alt="image-20240306185411393" style="zoom:80%;" />
   - ![image-20240306185449388](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240306185449388.png)

9. **.git directory**
   Venture into the .git directory and browse a bit. What do you notice?

   - ![image-20240306185803935](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240306185803935.png)
   - .gitignore is hidden by default
   - HEAD contains a reference to the branch or commit that is currently being checked out
   - config holds your configurations for this repo
   - index stores staging area
   - the ref folder stores references to the branches, remotes and tags of the repo
   - objects stores all kinds of git objects

10. **Feature Branches**
    Imagine Customer A calls and urgently needs a feature A. You get right to work and create a feature branch "featureA", develop a file FeatureA and populate it. Commit the changes. What does the history look like now?

    - ![image-20240306190406583](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240306190406583.png)
    - ![image-20240306191644333](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240306191644333.png)
    - ![image-20240306191705635](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240306191705635.png)
    - We can see the difference in branches and the new commit

11. **Hotfix**
    Now customer B calls, complaining about an error. He cannot continue working. However, you are not done with FeatureA yet. Is this a problem? How do you go about delivering a hotfix quickly? How does this affect your developments in FeatureA? Do you deliver a hotfix to customer B? Remember that only master/main commits are delivered, or commits in their own deploy branches. Document your command sequence and history.

    - If FeatureA is not as urgent as the hotfix then I'd stash the changes made to Feature A and begin working on the Hotfix for Customer B on their Branch.
    - `git stash` to stash away unfinished changes without committing them
    - `git checkout featureB`
    - `<develop hotfix>`
    - `git add .`
    - `git commit -m "deliver hotfix customer b" .`
    - `git checkout main`
    - `git merge featureB` 
    - `git checkout featureA`
    - `git stash apply` to get changes back to Working Dir

12. **Finish Feature A**
    We now simulate that you complete featureA, i.e. you modify the featureA file again and check it in. Now merge the hotfix from 11 and featureA in such a way that you can deliver featureA including hotfix to customer B. Document the command sequence.

    - After everything in step 11 you only have to finish developing featureA and then use:
    - `git checkout main`
    - `git merge featureA` to merge the featureA branch with the main branch

13. **Branch deletion**
    After completion and merging with the master branch, delete the featureA branch. What is the command to do this? What options does it provide?

    - `git branch -d featureA` or `git branch -D featureA`
    - -d for merged branches
    - -D for unmerged branches