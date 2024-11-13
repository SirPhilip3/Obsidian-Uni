---
publish: true
---
__Git__ is a __VCS__ (Version Control System)

__VCS__ have usually a central server where source code is shared, eache changes to the source code needs to be committed locally, pushed from the server and pulled from the server

__GitHub__ is a hosting provider for software development and version control using __git__

__pull__ needs to occur before any __push__, in order to __push__ changes to the most recent version of the source code, this can result in some conflict, in this case a manual __merge__ is needed

__git__ commands:
+ **clone** : clones a repository into a new directory
+ **add** : add files to the repository
+ **commit** : record changes to the repository
+ **push** : update remote source code with committed changes
+ **pull** : fetch and integrate  the source code from remote origin
+ __-m__ : indicates adding a message after a commit

Configuring __git__:
+ git config –global user.email "myemail.unive.it''
+ git config –global user.name "Name Surname"

Initialize a repository :
1. Create a new repository on GitHub
2. Create a new local directory 
3. Execute `git init` in the new local directory
4. Execute `git remote add origin <GitHub repo url>`

Clone a repository:
	`git clone <URL>`

Add files to a repository:
	`git add <filename>`

Commit changes:
	`git commit -m "message"`

Push changes to the remote repository:
	`git push origin main` 
	pushes origin to the main branch

Pull changes from the remote repository:
	`git pull origin main` 
	pulls origin from the main branch

