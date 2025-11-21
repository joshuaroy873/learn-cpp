Repo containing non-AI ~~Vim-typed~~ C++ code written to solve competitive programming problems.

~~*Reason*: While solving Leetcode problems, I noticed myself googling syntaxes so much that it wasn't improving my coding skills.~~

`buildCpp.sh` automates building, execution and deleting execulable for cpp files.
- Usage: Run `./buildCpp.sh <source-file.cpp>` to compile, execute, and automatically remove the generated executable.
    - `#include<bits/stdc++.h>` usage incorporated: `-I` flag in `g++ -I. "$INPUT_FILE" -o "$EXECUTABLE_NAME"` adds pwd to search path.
- First time: Make `buildCpp.sh` executable with `chmod +x buildCpp.sh`.


Practice problems:
- [~~Geekforgeeks~~](https://www.geeksforgeeks.org/cpp/cpp-exercises/)
- **Migrated completely to:** [Codeforces](https://codeforces.com/)
