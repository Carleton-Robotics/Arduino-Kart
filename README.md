# Arduino-Kart

## How do I write code for this project?
### First time setup
* Clone this repository
* `cd KartControl`
* Install `arduino-cli` and add to path (follow instructions on https://github.com/arduino/arduino-cli)
* `arduino-cli core install arduino:avr`
* Install the following libs:
    ```
    arduino-cli lib install MCP45HVX1
    arduino-cli lib install "SparkFun u-blox GNSS Arduino Library"
    arduino-cli lib install "Adafruit BluefruitLE nRF51"
    arduino-cli lib install SD
    arduino-cli lib install LinkedList
    arduino-cli lib install "Adafruit HMC5883 Unified"
    ```
    
### Before you start actually writing some new code
* `git pull`
  * This makes sure that you have the latest version of all the code
  * If it says something about a merge conflict, you'll need to fix that before you proceed. See the `Merge conflicts` section below, or use Google
* `git branch`
  * This prints out all the current local branches ([here's an explanation of what branches are](https://www.atlassian.com/git/tutorials/using-branches)). The branch you are currently on is marked with a `*`
* `git checkout main`
  * You only need to run this if you aren't currently on the `main` branch
  * We need to be on `main` because we're about to make a new branch, and we want all of our new branches to be based on `main`
* For every change you make, you will need a new branch
  * Why? Because this will allow us to review code before it becomes part of the main branch.
* To make a branch: choose a short branch name (less than 5 words) separated by dashes, starting with your Carleton username, and run this:
     ```
     git checkout -b <branch name>
     # for example:
     git checkout -b zleisher-add-vector-class
     git checkout -b zleisher-fix-pid-bug
     # the -b option creates a new branch and checks it out
     ```
* Now you can write code!

### Writing code
* Make whatever changes you need, following these general guidelines:
  * Make sure that the files you are working on aren't being edited by someone else (otherwise merge conflicts will happen!)
  * Use a code formatter (Visual Studio and CLion should have one)
* You should periodically commit your work. Committing is like a more advanced `Ctrl+S`. It allows you to easily keep track of and share the work you've done. I like to do this when:
  * I am done for the day and want to save my work
  * I want someone else to take a look at the code remotely
  * I am done working on a particular feature, class or file
#### How do I commit my work?
* `git status`
  * This will show you all the files you've worked on
* `git add <file name>` for each file you want to include in the commit
* `git commit -m"<commit message here>"`
  * This creates a commit with the specified message between the quotation marks. Use a one sentence, highly descriptive message
* Making commits doesn't upload them to the repository at Github.com yet. To do that, you have to `push`
#### How do I push my work?
* If this is your first time pushing commits on this branch, run `git push -u origin <branch name>`, where `<branch name>` is the name of the current branch
* Otherwise, `git push` is fine
* Once you've pushed your code, it is now viewable by everyone on the Github repository. However, it is still not on the `main` branch, so it has not yet been accepted as part of the codebase. Once per branch you create, to get the code reviewed and accepted into the `main` branch, you have to make a pull request
#### How do I make a pull request?
* Go to the main page of the Github repository
* Click where it says the number of branches:

  ![image](https://user-images.githubusercontent.com/25469876/196593337-a579550b-5536-454b-b026-dfe9dffb8d62.png)

* Click where it says 'Add pull request' next to your branch:

  ![image](https://user-images.githubusercontent.com/25469876/196593607-c82c8077-62e4-4a51-962b-ef785c6767a9.png)

* Describe the pull request and select at least one reviewer on the right
* Click on 'Create pull request'
### How do I actually compile and run the code?
* Plug in Arduino, run `arduino-cli board list` to find port name of connected board
* `arduino-cli compile && arduino-cli upload --fqbn arduino:avr:mega -p <port name> && arduino-cli monitor --config baudrate=115200 -p <port name>`, replacing `<port name>` with the name of the port that it is connected to. This will compile and upload the code to the Arduino, then watch the serial connection to get terminal output
