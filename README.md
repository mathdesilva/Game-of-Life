# Conway's Game of Life

A Programming Language project to make a Conway's Game of Life using C++. The main goal with this project is to learn more about classes, dynamic allocation and others C++ features.

## How to use:
Run the project using `./life [<options>] <input_file_dir>`:
* **--help or -h**: Prints a help text.
* **--imgdir < path >**: Specify directory where output images are written to.
* **--maxgen < num >**: Maximum number of generations to simulate.
* **--fps < num >**: Number of generations presented per second. Default = 2.
* **--blocksize < num >**: Pixel size of a cell. Default = 10.
* **--bkgcolor < color >**: Color name for the background. Default = GREEN.
* **--alivecolor < color >**: Color name for representing alive cells. Default = BLUE.
* **--outfile < filename >**: Write the text representation of the simulation to the given filename.
* **--rule < code >**: Specify evolution rule using B-/S- code, B for born and S for survives. Default = B3/S23.

## Dependencies:
* `g++`
* `makefile`
* `cmake`

## How to compile:
To compile the project, first you need to clone the repository with

```bash
git clone https://github.com/matheusmas132/Game-of-Life.git
```

or download the project manualy.

Go to project directory and use

```bash
mkdir build
cd build
cmake ../
make
```

## Authorship
Program developed by [Matheus de Andrade](https://github.com/matheusmas132) and [Felipe Medeiros](https://github.com/felipecolares22), 2019.1

&copy; IMD/UFRN 2019.