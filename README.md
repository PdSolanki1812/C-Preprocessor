# C Preprocessor

This is a small project I made in C. It works like a mini version of the actual C preprocessor (the step that runs before your code compiles). It takes a `.c` file and does three things to it:

1. Removes comments
2. Replaces a macro defined with `#define`
3. Adds the header file's content directly into your code

It edits the file directly. There's no separate output file.

## Files in this project

- **main.c** – Where the program starts. It takes the file name you give it and runs the three functions one after another.
- **header.h** – Has the common includes (`stdio.h`, `string.h`, `stdlib.h`) and the function declarations used across the project.
- **functions.c** – The actual logic for removing comments, replacing macros, and adding header files.
- **count_word_in_file.c** – A small function I wrote to count how many times a word shows up in a file. It's not connected to `main.c` right now, so it won't run unless you add it in yourself.

## How to run it

Compile:
```
gcc main.c functions.c -o preprocessor
```

Run it on any C file:
```
./preprocessor file.c
```

It changes `file.c` directly. While running, it also creates a file called `txt.txt` in the same folder. That's just used as a scratch file, and it stays there after the program finishes.

## What each function does

**comment_remove(file)**
Goes through the file character by character. When it finds `//`, it turns everything after it till the end of the line into spaces. Same idea for `/* */`, everything inside becomes spaces. This way the file length and line numbers stay the same.

**macro_substitute(file)**
Finds a `#define` line, picks up the two words after it, and replaces one with the other in the file.

A couple of things to know:
- If there's more than one `#define`, only the last one gets used. The earlier ones get ignored.
- It actually replaces the value with the name, not the name with the value. So for `#define PI 3.14`, it replaces `3.14` with `PI`, which is the opposite of how `#define` normally works. Might be a bug, haven't fixed it yet.

**replace_word(file, new, old)**
A helper function that swaps every occurrence of `old` with `new` in the file. Used inside `macro_substitute`.

**header_include(file)**
Finds a `#include<header.h>` line (only works with `< >`, not `" "`), removes that line, then opens the matching header file from `/usr/include/` and pastes its content at the top of your file.

Same issue as `macro_substitute`: if there's more than one `#include` line, only the last one's content actually gets added in.

**count_word_file(file, word)**
Counts how many times a word appears in a file. This one is separate and not linked to the rest of the project yet.

## Things I still need to fix

- Only handles one `#define` and one `#include` per file
- Macro replace direction is backwards (replaces value with name instead of name with value)
- header_include only works for system headers in `/usr/include/`, not custom local headers
- Not much error handling overall

I made this mainly to understand how a preprocessor works under the hood, not to fully replace the real `cpp`.
