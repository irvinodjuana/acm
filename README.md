# acm
Solutions to Competitive Programming Practice Problems

## Scripts 

1. `setup.sh` - Sets up the workspace directory with .cpp files for each problem passed as an argument
2. `build.sh` - Compiles each of the problem files passed as an argument
3. `run.sh` - Runs the compiled executable for a given problem/file
4. `clean.sh` - Removes all compiled executables
5. `teardown.sh` - Renames the workspace directory and moves it to the archive directory

Examples: 

```shell
./setup.sh A B C D E F G

./build.sh A B

./run.sh A

./clean.sh

./teardown.sh
```