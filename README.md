# ASCIIart
It is a C program which takes in .pgm image files (a text-based image format to store black and white images) and converts them into ASCII art,  by displaying the image using ASCII characters.

All the .pgm files in this repo may be used to test the program.

To use any of your own image:
1) Convert it to black and white using any of the tools.
2) Scale it down to a reasonable size of a width of 100 pixels (height doesn't matter as much).
3) Upload this image to chatGPT and run the following prompt "Convert this image to .pgm p2 format while retaining resolution".
4) Download the output image, and store it in the same folder in which main.c is stored.
5) Run the program and enter "ImageName.pgm", press enter to see the output image.
6) Inside the VS Code termianl you may not be able to see the image properly if the text size is too much, hence reduce it using:
   Ctrl + '-' on windows
   Command + '-' on mac

7) The displayed image is also stored in text format as "ascii_art.txt" in the same folder after running the program.
