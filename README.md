# OpenGL Mini Project
# Title: A day in Hogwarts

This is a small 2D project developed using the glut, glu and gl libraries of OpenGl in C. 
A character appearing to be Harry Potter is able to walk left and right on the press of left and right arrow, respectively.
It is also possible to fly up and down to collect objects, called as Snitch in the Harry Potter world, using the up and down arrow keys, respectively.
Points are awarded each time a snitch is caught, and a maximum of 3 misses are allowed for collecting the snitch before the game ends.
Have fun playing!

----

Instructions to run on Mac: 

```
brew install glfw3
brew install glew
g++ hogwarts.c -L/opt/homebrew/Cellar/glfw/3.3.7/lib/ -lglfw -L/opt/homebrew/Cellar/glew/2.2.0_1/lib -lGLEW -framework GLUT -framework OpenGL -v
```

Note: unfortunately there seems to be some bug when trying to capture the snitch