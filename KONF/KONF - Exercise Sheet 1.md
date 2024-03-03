# KONF - Exercise Sheet 1

#### by Niklas Brandtner 26.02.2024

## Instructions:

1. **Install the Git Bash**
   We are only working on the git bash to learn the commands. All GUI tools are handy and easy to use but without understanding what exactly is going on in the background, even the best tool won't help. For installation instructions, see Moodle.

   - Git Bash was already installed but usually go to Git Website -> Download Setup -> Go Through Setup -> add `C:\Program Files\Git\cmd` to PATH in environment variables :heavy_check_mark:

2. **The first repository**
   Create the first repository in a folder of your choice. What is the command for it? What are the options? What exactly happens in the process?

   - ![image-20240226012359924](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240226012359924.png)
   - `git init` A new Git Repository will be created in the specified folder (current active folder if not specified)
   - Options of `git init`:
     - --quiet Only print error and warning messages; all other output will be suppressed.
     - --bare Create a bare repository. If `GIT_DIR` environment is not set, it is set to the current working directory
   - Process of `git init`:
     - Git checks for an existing `.git` directory. If found, it aborts to prevent overwriting.
     - If no `.git` directory exists, Git creates one.
     - Git initializes necessary configuration files within `.git`.
     - The specified folder becomes the repository's root directory.
     - The repository is ready for use; you can start managing files and commits.

3. **Global config**
   To set up your name and email address once, configure it via git config. What is the full command? What options are there? Where are global settings stored in Git?

   - `git config --global user.name "Your Name" --global user.email "your.email@example.com"` 
   - Options:
     - ``--global`: sets the configuration globally. Without this, the configuration will only be set for the current repository.
   - Where are global settings stored in Git?
     - On Unix-like systems (such as Linux and macOS), the global configuration file is typically located at `~/.gitconfig` or `~/.config/git/config`.
     - On Windows, it's usually located at `C:\Users\YourUsername\.gitconfig`.
     - or check the location with `git config --global --list --show-origin`
     - ![image-20240226021538569](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240226021538569.png)

4. **Text file**
   Create a text file and write into it.

   - ![image-20240226021739955](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240226021739955.png)

5. **Status**
   On the Git Bash, check the status. What is the command for this? What result do you get and how do you interpret it?

   - ![image-20240226021853171](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240226021853171.png)
   - `git status`
   - Your branch and how it compares to its remote counterpart, if applicable.
   - Changes not staged for commit: Modified files that have been changed since they were last staged.
   - Changes to be committed: Files that are staged and ready to be committed.
   - Untracked files: Files that are in your working directory but not yet staged for commit.
   - Unmerged paths: Files with conflicts that need to be resolved due to merge conflicts.

6. **Put file in the repository**
   Now add this file to your created repository. What are the commands for doing this? What steps are necessary and what results do you get? How do you interpret the output? Where does Git store the files?

   - To add this file use `git add *file-name*` then `git commit -m "Your commit message"` to commit it to the repository

   - `git add <file_name>`: This command stages the specified file for the next commit. You can also use `git add .` to stage all modified and new files in the current directory and its subdirectories.

   - `git commit -m "Your commit message"`: This command commits the staged changes to the repository with a descriptive message explaining the changes made in this commit.

   - After executing these commands, Git stores the committed files and their snapshots in the repository's object database, which is located in the `.git` directory of your repository.

     The output of these commands typically includes messages indicating the result of the operations:

     - When you run `git add`, it doesn't produce any output unless there's an error.
     - When you run `git commit`, Git will display information about the commit, including the files changed, the number of insertions and deletions, and the commit message.

   - ![image-20240226024511453](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240226024511453.png)

7. **SHA1**
   You have now created Git Objects. Which ones (according to the Data Model) and where are they located? How can you find the SHA1 key of the blob object? What is the command for this?

   - **Blob objects**: These represent the content of each file in the repository at the time of the commit. Blob objects are stored in the `.git/objects` directory, hashed based on their content, and identified by their SHA-1 hash.
   - **Tree objects**: These represent the directory structure and the list of files and their corresponding blob object references at the time of the commit. Tree objects are also stored in the `.git/objects` directory and identified by their SHA-1 hash.
   - **Commit objects**: These represent a snapshot of the repository at a given point in time, including a reference to a tree object that represents the top-level directory structure, parent commit(s) if applicable, author and committer information, and a commit message. Commit objects are stored in the `.git/objects` directory and identified by their SHA-1 hash.
   - To find the SHA-1 key of a blob object, you can use the following command:
     - `git hash-object <file_name>`
     - This command calculates the SHA-1 hash of the content of the specified file without adding it to the repository. It's important to note that this command calculates the hash without considering any metadata such as filename or timestamp. It only calculates the hash of the content itself.
     - ![image-20240226025623085](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240226025623085.png)

8. **Search and output via SHA1**
   How can you output the contents of the file only by specifying the SHA1 key? What is the command and what options does it provide?

   - To output the contents of a file in Git by specifying its SHA-1 hash, you can use the following command:
   - `git cat-file -p <SHA-1>` where SHA-1 is the hash of the object you want to output
   - `-p`: This option tells Git to output the contents of the specified object.
   - By default, `git cat-file` interprets the specified SHA-1 as a commit object. However, you can specify the type of object explicitly using the `-t` option followed by the desired object type (so `-t blob` for blob objects).
   - ![image-20240226030333754](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240226030333754.png)

9. **SHA1 Hello World**
   What is the SHA1 key of the text "Hello World!"? Do not create a separate file for this! What is the command for this?

   - We can find the SHA1 Key of the "Hello World!" text by using the following command: 
     `echo -n "Hello World!" | git hash-object --stdin`
   - ![image-20240226030726331](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240226030726331.png)

10. **Save Hello World**
    Save the text "Hello World!" in the repository without creating a file for it.

    - `echo -n "Hello World!" | git hash-object -w --stdin`
    - ![image-20240226031522038](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240226031522038.png)
    - This stores the text in a blob object in the git repo and you can access the content with the hash it gives you. 

11. **Blobs**
    You have now created the first 2 blob objects in the repository Now create the first commit object. Which command do you use for it? What options does it offer? Where are commit objects stored?

    - `git write-tree` to get tree-sha1 key
    - `echo '<Your Message>' | git commit-tree <tree-sha1-key>` to commit a message onto the repository
    - `git show <commit-sha1-key> ` to see changes on git
    - ![image-20240228152933279](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240228152933279.png)

12. **History output**
    In order to be able to display the history on the screen, you must use this 
    Enter command: git log --graph --decorate --oneline -all
    Since we don't want to type this long command every time, we will configure ourselves an alias (git lol). What command do you enter for this?

    - We can create an alias globally or locally (for the current git repo) with 

    - ```basic
      - git config --global alias.<alias-shortcut> <git command>
      or
      - git config alias.<alias-shortcut> "longer git command with --options"
      ```

    - ![image-20240228153857346](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240228153857346.png)

13. **History**
    With git lol we can now output the history at any time. What does the history look like?

    - already shown above ^
    - "1406498" which is the commit-sha1-hash
    - "(HEAD -> master)" which means that the HEAD branch is currently pointing to the master branch, meaning we're currently working on the master branch
    - "Add test.txt" which is the commit message of the commit

14. **New file**
    Create another file and add it to the repository. Also create a new version of your repository.

    - ![image-20240228161119821](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240228161119821.png)
    - Created a new text-file and added/committed it to the repository
    - ![image-20240228161457450](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240228161457450.png)
    - I changed the content of test.txt and another_test.txt, added them and committed them to the repo, therefore creating a new version of the repository.

15. **Commit object**
    Oops, now you have forgotten a file. Create a third text file and add this file to the repository. But make sure that this file still goes into the same version of the history. What command do you use to do this? Does git create a new commit object? If so, why?

    - ![image-20240228162021956](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240228162021956.png)
    - We can use `git commit --amend` to add a forgotten file to a previous commit
    - `--no-edit` tells Git not to open the commit message editor, keeping the commit message unchanged.

    - By using `git commit --amend`, Git creates a new commit object, even though the changes are being added to the previous commit. This is because every commit in Git is immutable. When you amend a commit, you're effectively creating a new commit object with the updated changes, and Git updates the reference of the branch to point to this new commit object instead of the old one. 

16. **Delete**
    Delete a file and then restore it. What command do you use for this? From where is the file restored?

    - ![image-20240228162457190](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240228162457190.png)
    - Git retrieves the contents of the specified file from the latest commit (HEAD) and restores it to the working directory.

17. **Modify files**
    Modify the contents of the first file. Display the status in Git. What does the output look like and how do you interpret it? How do you commit the changes? What happens in the repository?

    - ![image-20240228163543256](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240228163543256.png)
    - The output indicates which files have been modified and staged for commit, and which files are untracked.
    - committing the changes is just a `git add .` and `git commit -m "Commit Message"` again.
    - In summary, by modifying a file, staging the changes, and committing them, you're updating the history of your Git repository. Each commit represents a snapshot of your project's state at a specific point in time, allowing you to track changes and collaborate with others effectively.

18. **Checkout**
    Look at the history and try to go back to the penultimate version. Now look at the history again. What does HEAD mean? What is main/master? What other options does the command you just used offer?

    - **HEAD**:

      - `HEAD` is a reference to the current commit you have checked out.

    - **Main/Master**:

      - `main` or `master` is the default branch in a Git repository. It typically represents the main line of development.
      - These branches serve as the starting point for development and typically contain the most stable version of the project.

    - **Checkout**

      - ![image-20240228173346942](C:\Users\nbran\AppData\Roaming\Typora\typora-user-images\image-20240228173346942.png)
      - Here we can see that the HEAD gets updated once we checkout an older commit. 

    - Other Options of Checkout:

      - **Create and switch to a new branch**:

        ```bash
        git checkout -b <new_branch>
        ```

        This option creates a new branch with the given name and immediately switches to it.

      - **Restore files from the staging area**:

        ```bash
        git checkout -- <file_path>
        ```

        This option restores the specified file(s) from the staging area to your working directory, effectively undoing any changes made since the last commit.

      - **Restore files from a specific commit**:

        ```bash
        git checkout <commit_hash> -- <file_path>
        ```

        This option restores the specified file(s) from the given commit to your working directory. It's useful for inspecting or reverting changes made in past commits.

      - **Create a new branch from a specific commit**:

        ```bash
        git checkout -b <new_branch> <commit_hash>
        ```

        This option creates a new branch starting from the specified commit and switches to it. It's useful for creating branches to work on specific features or bug fixes.

      - **Create a detached HEAD state**:

        ```bash
        git checkout <commit_hash>
        ```

        This option checks out a specific commit without creating or switching to a branch, leaving you in a "detached HEAD" state. It's useful for inspecting historical commits or testing changes without affecting existing branches.

      - **Interactively restore changes with patch mode**:

        ```bash
        git checkout -p
        ```

        This option enters interactive mode, allowing you to selectively restore changes from the specified file(s) using the patch mode.