# Steps to install GCC compiler

1. The Project is built on C,to run code in any environment it requires a gcc compier.
2. Click [here](https://sourceforge.net/projects/mingw-w64/) to get gcc compier,and download one required by Host OS.
3. Add path of gcc directory to “System Environment Path Variables”
4. To check installation of gcc in system type "gcc --version" in cmd.

# Instruction for Installation

1. Clone GitHub repository link of project given here: [Contact Registry](https://github.com/GENESIS2021Q1/sdlc2-team-14.git)
2. Under project open 3_Implementation folder
3. The code works in both linux and windows environment hence,It could be said that implementation is OS INDEPENDENT.
   - Windows : Click Win+R key, type cmd or search for cmd in Start Menu and redirect to 3_Implementation directory using cd command.
   - Linux   : Open terminal and redirect redirect to 3_Implementation directory using cd command.

# Makefile

[Makefile](https://github.com/GENESIS2021Q1/sdlc2-team-14/blob/main/3_Implementation/Makefile) created reduces the tedious process of integration in multifile programming via a single file which focuses on integration and exection of project.


make command         | Description
-------------------- | -----------------------------------------
`make run`           | Deploys the actual implementation.
`make test`          | Performs unittesting.
`make coverageCheck` | Checks for code coverage by design.
`make cppcheck`      | Static code analysis.
`make valgrind`      | Dynamic code analysis.
`make cppcheck`      | Removes directories which aren't required for execution
