# PyGamer-AVI-Player

An AVI video player for the Adafruit PyGamer.

## Install

After downloading all the libraries, follow the modifications listed in [`src/main.cpp`](src/main.cpp) if you choose to use PlatformIO.

## FFmpeg command

We use Cinepak as the video codec and MP3 as the audio codec.

```cmd
ffmpeg -i INPUT.mp4 -c:a mp3 -c:v cinepak -q:v 10 -vf "fps=30,scale=iw*min(1\,if(gt(iw\,ih)\,160/iw\,(120*sar)/ih)):(floor((ow/dar)/4))*4" OUTPUT.avi
```
