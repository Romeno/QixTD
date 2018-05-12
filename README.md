# General
There are several games in this repository none of which are finished, playable and most are just stubs. Some may even not compile.

# QixTD
The main game project of my "game pack" repository by now which I am currently developping. 
The game supposed to be with mechanics of [Qix/Xonix](https://www.youtube.com/watch?v=Wvzyd0OZg1I) and tower controlling, monster fighting features.


# Installation

1. Clone
2. Define ROMENO_BUNLDE env variable which should point to parent directory of all dependecies for the project.
3. Setup dependencies as below
4. Open QixTD.sln in Visual Studio (developped on 2015) and build.

### If starting new project
1. Add Additional Include directories and Additional Library directories as in QixTD
2. Add library dependencies: Box2D.lib;SDL2_ttf.lib;glew32sd.lib;P7x32d.lib;Ws2_32.lib;SDL2.lib;SDL2_image.lib;SDL2main.lib;


## Dependencies

### glew
Glew is unsued by the moment (all drawing is done by SDL default implementation) but it is included in the project. 

If including glew we need to build it.

When build remove glew.rc resouce file from project and need to include this file into QixTD static library project for link to complete

Latest version glew v2.1

### P7
There was a need to build P7 but I forgot why. You can use [binaries](http://www.baical.net/downloads.html) provided by the author. I dont know if point listed below is actually relevant
1) When build remove P7.rc resouce file from project and need to include this file into QixTD static library project for link to complete

Developed on P7 v4.2

### SDL2

As far as I remember I built SDL from source.

#### SDL2_image

Just used binaries provided by author.

#### SDL2_ttf

Just used binaries provided by author.

### Box2d

Dont actually remember, just binaries mb?

### glm

glm is just heades library so no building needed.
