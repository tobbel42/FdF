# FdF

## Task

FdF(`fil de fer` which stands for wireframe in French) is a 3D wireframe Viewer (macOS only).
It is the first graphics project in the 42 curriculum and is written purely in C.
We had to use a simple graphics library (for each pixel an RGBA value is set).
The program takes as input a map, which is then parsed, rendered and displayed.

![pyramide.fdf map](/images/pyramide.png)

## Bonus

For the bonus, I implemented key controls, which enables the user to rotate and move the wireframe around, and to zoom in and out.

![t2.fdf map](/images/t2.png)

Detailed instruction for the project can be found in the [`subject file`](/en.subject.pdf).

## Usage

download the git repository, then go into the directory
```
git clone git@github.com:tobbel42/FdF.git
cd FdF
```

to compile the program run

```
make
```

or for the bonus
```
make bonus
```

then run the program
```
./fdf test_maps/pylone.fdf
```

or the bonus 
```
./fdf_bonus test_maps\pylone.fdf
```

![pylone_bonus.fdf map](/images/pylone_bonus.png)

the test_maps folder contains additional example maps
have fun exploring :wink:

## Final Score

**123/100**