# Sawwave
A VERY simple commandline game writing a saw wave to the DAC, you must guess the note.

First Download/Install the portaudio library,
On a mac terminal  `cd` into the folder, run `./configure && make` and then  `make install`

To build for macos you can run the command 
`gcc main.c /usr/local/lib/libportaudio.a -framework CoreAudio -framework CoreServices -framework AudioToolbox -framework AudioUnit`  (recommended)
Or 
`gcc main.c -L/usr/local/lib/  -lportaudio` ( on most v19 portaudio)

Video of it being compiled and played here https://youtu.be/E6KgmggWA9E

Tested on all macos' from the m1 mac all the way down to 10.4 ppc's ;)

