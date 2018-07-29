# Web Assembly Test Project

This project is testing out some of the various features of webassebly. Currently it builds an application which uses SDL to bounce a rectangle around the screen, it's sort of a clone of a popular screen saver.

To build the project you must have the emscripten toolchain available. As long as that requirement is met, issuing a make in the top level directory should be all you need to do to build it. The output from the build will be placed in the bin folder.

An easy way to run the project is to use the simple python web server. In your shell go to the bin directory and run "python -m SimpleHTTPServer 8080". The open a browser and go to http://localhost:8080/ . Also, the app looks a lot better if you click the fullscreen button at the top of the page.
