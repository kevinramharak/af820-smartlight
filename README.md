# af820-smartlight
C++ implementation to control an af820 smartlight with a command line application

## Description
This is a simple C++ application i made that mostly just defines the byte protocol the smartbulb uses.  
Btw note that this smartbulb sends packets to some remote server based in the US.  
This remote server also hosts an empty chinese forum. Thats what you get from buying cheap stuff in china i guess.  
It might be just an harmless service that the bulb use, but do note that the bulb sends your WiFi SSID and Pass in plain text trough UDP packets.  
check [af820smartlight](https://gitlab.com/iot/af820smartlight "Cool info") for more information about the protocol. Its also a cool MQQT implementation. 

## How
To get it to work you can see `example/normal.main.cpp`  
You should change the following
```cpp
// define connection info
// the port should not be changed
const uint16_t port = 5880;
const char ip[15] = "0.0.0.0"; // this works for the specific ip of the smart light, if that wont work for whatever reason
                               // then broadcast should work -- 255.255.255.255 or 0.0.0.0
```
If you can get it to compile you should just execute the compiled binary to get the usage.
