# Ray Tracer

## 📌 Project Overview
This project implements a basic **Ray Tracer** that renders a scene containing a plane and multiple spheres. The ray tracing algorithm calculates intersections between rays and objects in the scene to determine the final color at each pixel.

## ⚙️ Compilation & Run Instructions
### Prerequisites
Make sure you have the following installed:
- **C++ Compiler** (GCC, Clang, or MSVC)
- **CMake** (Optional but recommended)
- **GLM** (OpenGL Mathematics Library)
- **SDL2** (For displaying the rendered image, if applicable)

### 🔧 Compilation
#### Using g++ (Linux/macOS)
```sh
g++ -o raytracer main.cpp Camera.cpp Scene.cpp Sphere.cpp Plane.cpp Ray.cpp -std=c++17 -I./include -lSDL2
```
#### Using Visual Studio (Windows)
1. Open the solution file in Visual Studio.
2. Build the project using `Ctrl + Shift + B`.

#### Using CMake
```sh
mkdir build && cd build
cmake ..
make
```

### ▶️ Running the Program
```sh
./raytracer
```

## 📦 Additional Libraries
This project requires:
- **GLM**: Math operations for ray calculations.
- **SDL2** (optional): Used to display the final rendered image.

## 🎯 Features
- **Perspective Camera**: Defines rays based on image resolution and view frustum.
- **Ray-Object Intersection**:
  - Plane (y = -2)
  - Spheres at predefined positions
- **Shading (Phong Model)**: Basic shading using ambient, diffuse, and specular components.

## 🚀 Scene Description
- **Plane**: y = -2
- **Spheres**:
  - **S1**: Center (-4, 0, -7), Radius 1
  - **S2**: Center (0, 0, -7), Radius 2
  - **S3**: Center (4, 0, -7), Radius 1
- **Camera**: Located at (0,0,0), looking along -w direction.


