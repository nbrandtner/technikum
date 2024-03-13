# KONF - Exercise Sheet 3

#### by Niklas Brandtner 11.03.2024

1. **Remote Repository**
   Set up a repository at GitHub or the GitLab server of the FH Technikum Wien - make sure it is not empty (e.g. have README generated).
   - ![image-20240311120937132](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311120937132.png)
   - created a readme with a README
2. **Cloning**
   Clone the repository from GitHub/GitLab to get a local copy of it - what commands do you use for that? What do you notice in terms of history? Research the details and describe your findings here!
   - ![image-20240311121414974](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311121414974.png)
   - `git clone <link>` to clone a repository 
   - ![image-20240311121925188](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311121925188.png)
   - the history shows us the initial commit created when initiating the repository, `5f22acc` is the commit hash that is used to identify the exact commit
   - HEAD points to main here, so this is the branch where changes are going to be made
3. **Add Remote**
   In addition to this, set up a new repository locally in another directory and connect it to the remote repository on GitLab and synchronize! Describe the commands for this!
   - ![image-20240311122824648](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311122824648.png)
   - Initiate new repo and add remote repo again
   - ![image-20240311122852428](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311122852428.png)
   - `git fetch` and `git merge` to synchronize all changes from the remote to the local repo
4. **New files**
   Now create new files in both repositories with different names, commit and synchronize each with the remote repository - what do you notice? What commands are you using? Describe your commands.
   - First Repo:
   - create new file
   - add and commit it
   - show log
   - ![image-20240311123925484](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311123925484.png)
   - Second Repo:
   - create new file in second repo
   - add and commit it
   - show log
   - ![image-20240311123900355](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311123900355.png)
   - Repo 1:
   - push repo 1 changes
   - ![image-20240311124017917](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311124017917.png)
   - Repo 2:
   - pull repo 1 changes in repo 2 and show log
   - ![](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311124239866.png)
   - push repo 2 changes
   - ![image-20240311124309522](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311124309522.png)
   - Repo 1:
   - pull repo 2 changes to repo 1 and show log
   - ![image-20240311124346483](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311124346483.png)
5. **Conflict!**
   Now edit the same file in the same line in both repositories, creating a conflict. Synchronize again and describe your new commands and findings!
   - Change the content of newFile in both repos, then push in one of them and pull in the other, the pull will result in this conflict:
   - ![image-20240311134604831](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311134604831.png)
   - ![image-20240311135929053](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311135929053.png)
   - now edit the newFile in a text editor to change to wanted changes
   - ![image-20240311140015238](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311140015238.png)
   - second repo:
   - ![image-20240311140042150](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311140042150.png)
   - now both repos have the same content and the conflict is resolved
6. **Tagging**
   In one of the two repositories you have now completed a new version. Create a tag with version 1.0.0 and synchronize with the remote repository! Which commands do you use and which options do they offer? Synchronize also the second repository so that you also get the tag.
   - ![image-20240311141506811](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311141506811.png)
   - create tag and push it to origin repo
   - ![image-20240311141559287](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311141559287.png)
   - pull other repo and verify the tag is there
7. **Two Features**
   Now create different feature branches in each repository and simulate the development of two features from different developers. Make sure that only the new version with integrated features lands on the remote repository! Which commands do you use?
   - ![image-20240311185221644](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311185221644.png)
   - create and push feature 1
   - ![image-20240311185349570](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311185349570.png)
   - do the same at the 2nd repo with feature2
   - ![image-20240311185513565](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311185513565.png)
   - merge both features into 2nd repo
   - ![image-20240311185534478](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311185534478.png)
   - merge both features into first repo
   - ![image-20240311185749625](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311185749625.png)
8. **Major and Minor**
   Create your own deployment branch and create the new versions including tags in this branch. Again, simulate the development of new features for new minor versions (at least 2). The deployment branch should contain the new version - the main/master branch will be reserved for major versions in the future. Finally, create a new major version and synchronize both remote repositories.
   - ![image-20240311192459968](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311192459968.png)
   - add 1.1.0 feature
   - ![image-20240311192539077](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311192539077.png)
   - add 1.2.0 feature
   - ![image-20240311192617984](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311192617984.png)
   - pull 1.1.0 and push 1.2.0
   - ![image-20240311193043428](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311193043428.png)
   - merge repo 2
   - ![image-20240311193354338](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311193354338.png)
   - pull origin from repo 1 and then merge into main and push version 2.0.0
   - ![image-20240311193506032](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311193506032.png)
   - pull all changes on 2nd repo and confirm all tags and files are there
   - ![image-20240311193550735](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240311193550735.png)
   - log

