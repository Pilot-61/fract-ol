# Fract'ol - Fractal Rendering Program
![Screenshot](https://github.com/mes-salh/fract-ol/raw/main/Screen%20Shot%202024-05-22%20at%206.38.32%20PM.png)

## Overview
Fract'ol is a fractal rendering program that displays Julia and Mandelbrot sets. The program supports infinite zoom, various color schemes, and smooth window management using the MiniLibX library.

## Features
- **Julia and Mandelbrot Sets:** Render these popular fractals.
- **Infinite Zoom:** Use the mouse wheel to zoom in and out infinitely (within computer limits).
- **Custom Julia Sets:** Create different Julia sets by passing parameters.
- **Command Line Parameters:** Specify fractal type and rendering options via command line.
- **Color Depth:** Display fractals with multiple colors to show depth and create psychedelic effects.
- **Smooth Window Management:** Handle window changes, minimize, and close events smoothly.
- **Clean Exit:** Pressing ESC or clicking the window's close button will exit the program cleanly.

## Installation
1. Ensure you have the necessary development tools and libraries installed, including MiniLibX.
2. Clone the repository:
    ```sh
    git clone <repository_url>
    ```
3. Navigate to the project directory:
    ```sh
    cd fractol
    ```
4. Compile the program:
    ```sh
    make
    ```

## Usage
Run the program with the desired fractal type:
    ```sh
    ./fractol <fractal_type> [additional_parameters]
    ```

## Examples

### Display the Mandelbrot set:

    ./fractol mandelbrot

### Display a Julia set with custom parameters:
    
    ./fractol julia <parameter1> <parameter2>
    
## Command Line Parameters
mandelbrot: Display the Mandelbrot set.
julia: Display the Julia set. Additional parameters can be passed to customize the Julia set. If no parameter or an invalid parameter is provided, the program will list available parameters and exit.
## Controls
Mouse Wheel: Zoom in and out.
ESC: Close the window and exit the program.
Window Close Button: Close the window and exit the program.
## Dependencies
MiniLibX
