# uriel
Fetches Bibles verses from your terminal. Displays a single specified verse, or an entire chapter if the verse is not provided.

## Installation

To build: run `make`. This will compile the program, create a bin/ directory in the repository, and place the binary in it.

To install to path: run `make install`. This will compile the program and place it in `/usr/local/bin`.

To uninstall from path: run `make uninstall`. This will remove the binary and relevant data files from your path if they exist.

## Usage

`uriel` takes two different commands, either with a verse provided or without. To display a specific verse, use the command `uriel [book] [chapter]:[verse]`.

For example, `uriel genesis 1:1` would return:

*In the beginning God created the heaven and the earth.*

If the verse is omitted from the command, i.e. `uriel genesis 1`, it will instead return the entire chapter. Be wary this may not display correctly on your terminal if the chapter is longer than your line limit.