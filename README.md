# Sawwave
A VERY simple commandline game writing a saw wave to the DAC, you must guess the note.

First Download/Install the portaudio library,
On a mac terminal just `cd` into the folder and run `./configure && make` 
and then run   `make install`

To build for macos you can run the command 
`gcc main.c /usr/local/lib/libportaudio.a -framework CoreAudio -framework CoreServices -framework AudioToolbox -framework AudioUnit`  (this is what i usualy use)

Or you can use
`gcc main.c -L/usr/local/lib/  -lportaudio` (this is one that i have only tested on an m1 mac)

video of it being compiled and played here https://youtu.be/E6KgmggWA9E

Tested on all macos' from the m1 mac all the way down to 10.4 ppc's ;)

