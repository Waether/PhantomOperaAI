# Phantom Opera AI
An C++ AI made to work with [nlehir's](https://github.com/nlehir/phantom_opera.git) python server

## Prerequisites

* Linux (tested on Ubuntu 18.04) - Should be compatible with others Linux based OS
* Windows (tested on Windows 10)
* Python 3.6 You need this version specifically for the server to work
* CMake (tested with 3.5)

## How To Use

You first need to clone both our repository and [nlehir's](https://github.com/nlehir/phantom_opera.git)

```
#> git clone https://github.com/nlehir/phantom_opera.git
#> git clone https://github.com/Waether/PhantomOperaAI.git
```

You then need to compile the C++ code using CMake
```
#> cd PhantomOperaAI
#> mkdir build
#> cd build
#> cmake ..
#> make
#> cd ..
```

You can then start one server and two clients
The Inspector should be launched first
The Ghost should be launched second
```
#> python3.6 server.py
#> ./PhantomOperaAI -i
#> ./PhantomOperaAI -g
```


## TODO
* Need to test building using MacOS

## Authors

* **BLAviou** - [BLAviou](https://github.com/BLAviou)
* **Nathan Hautbois** - [Waether](https://github.com/Waether)
