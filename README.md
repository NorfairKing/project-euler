# Project Euler Solutions: Norfair
EDEN driven project euler solutions

For more info on EDEN, look here: https://github.com/NorfairKing/eden.


### DISCLAIMER

This repository contains spoilers.
If you don't want to be spoiled, don't look at the code (or the writeups).


### Contributors

- Tom Sydney Kerckhove ![norfair badge](https://projecteuler.net/profile/Norfair.png)
- Michael Kirsche


### How to add a solution

Solutions are in `<problem>/<language>`.
After creating your solution, make sure it builds with `eden build solution <problem> <language>`.
Make sure you add a test and run it with `eden test solution <problem> <language>`.
A test may be just an `output.txt` file but usually some kind of input is required as well. Put it in `input.txt`.

Please run `eden test all` to ensure that everything is in order before sending a pull request.


### Clone submodules:

```
$ git submodule update --init --recursive
```


### Dependencies

#### Publishing

- latexmk
- minted


### Dependencies

#### Java

- `javac`
- `java`


#### Scala

- `scalac`
- `scala`


#### Rust

- `rustc`
- `cargo`


#### C/C++

- `gcc`
- `g++`
- library `libgtest-dev`


#### Haskell

- `ghc`
- library `memoize`


#### Python 2/3

- `python2`
- `python3`
