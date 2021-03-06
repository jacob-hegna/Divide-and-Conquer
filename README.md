# Divide and Conquer
Divide and Conquer is a single-player arcade game with short play sessions and addicting gameplay.

It is uses its own engine, and uses OpenGL for rendering.

## Copyright and License
Divide and Conquer is Copyright 2013 Jacob Hegna.

This file is a part of Divide and Conquer.

Divide and Conquer is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.

## Building are running on Linux
Clone the repo:

```
git clone https://github.com/jacob-hegna/Divide-and-Conquer
```

Move to the game folder and build.

```
cd Divide-and-Conquer
make
```

## Controls
'wasd' moves the hero

'q' divides the hero

'1..9' switches the gun that the hero has equipped

left click to shoot

There is also a way to play with a gamepad.  If you are on a system where the controller is recognised (ie a ps3 controller on linux), then simply go into settings.xml and change the input flag to 'joystick'.

## Dependencies
To build Divide-and-Conquer, you will need the OpenGL headers/libs and the glfw3 headers/libs.  You will also need the OGLFT font rendering library.  RapidXML is used, but it is included in the project

## Settings
Settings are stored in xml within a file called settings.xml.  You can enable fullscreen, change the window size, and change the settings of various weapons.  You can also edit the settings in game, by going to the pause menu and then clicking settings.

settings.xml is created the first time you run Divide and Conquer
