# miniRT

## Table of Contents
1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Usage](#usage)

## Introduction
miniRT is a simple ray tracing program that renders 3D scenes using the Ray Tracing technique. It is written in C and uses the MiniLibX library to display the rendered image on the screen. The program supports rendering spheres, planes, cylinders, and cones with different materials and light sources.

### Ray Tracing
miniRT implements a full Whitted-style ray tracing algorithm with Blinn-Phong illumination with the following features:
- Rendering of spheres, planes, cylinders, and cones,
- Moving camera with rotation and translation,
- Multiple light sources with different colors and intensities,
- Blinn-Phong shading model with shadows and reflections,
- Metal, dielectric, and diffuse materials with different properties,
- Anti-aliasing with super-sampling,
- Multi-threading with a thread pool,
- BMP image saving,
- Color disruption, checkered pattern,
- Texture and normal mapping with UV coordinates.

### Scene Description
The scene is described in a simple text file with the `.rt` extension. These files provide a description of the scene, including the camera, light sources, and objects. The following is an example of a simple scene description:
```
# Camera
C	0,0.5,1.5		0,0,0		80

# Light
A					0.3				255,255,255
l	0,1.4,-0.5		0.3				255,255,255
l	0,1.4,0.5		0.3				255,255,255

# World
pl	0,0,0		0,1000,0			255,0,0			m:plastic
pl	1,0,0		-1,0,0			0,255,0			m:metallic
pl	-1,0,0		1,0,0			0,0,255
pl 0,0,-1		0,0,1			240,240,240		m:metallic t:assets/textures/metal.bmp n:assets/textures/metal_normal.bmp
pl 0,0,2		0,0,-1			240,240,240
pl 0,1.5,0		0,-1,0			0,0,0

sp 0.9,0.1,-0.5			0.2		255,255,255		 m:dielectric
sp 0.5,0.65,-0.6		0.25	0,255,255
```

### File Structure

- Ambient lighting:
	- `A` - Identifier,
	- `0.3` - Ambient lighting ratio in range [0.0, 1.0],
	- `255,255,255` - RGB color of the ambient light.
- Camera:
	- `C` - Identifier,
	- `0,0.5,1.5` - Camera position (x, y, z),
	- `0,0,0` - Camera orientation (x, y, z) in range [-1.0, 1.0],
	- `80` - Field of view angle in degrees [0, 180].
- Light source:
	- `l` - Identifier,
	- `0,1.4,-0.5` - Light position (x, y, z),
	- `0.3` - Light intensity in range [0.0, 1.0],
	- `255,255,255` - RGB color of the light.
- Plane:
	- `pl` - Identifier,
	- `0,0,0` - Plane position (x, y, z),
	- `0,1000,0` - Plane normal (x, y, z),
	- `255,0,0` - RGB color of the plane.
- Sphere:
	- `sp` - Identifier,
	- `0.9,0.1,-0.5` - Sphere position (x, y, z),
	- `0.2` - Sphere radius,
	- `255,255,255` - RGB color of the sphere.
- Cylinder:
	- `cy` - Identifier,
	- `0.5,0.65,-0.6` - Cylinder position (x, y, z),
	- `0,1,0` - Cylinder orientation (x, y, z) in range [-1.0, 1.0],
	- `0.25` - Cylinder diameter,
	- `0.5` - Cylinder height,
	- `255,255,255` - RGB color of the cylinder.
- Cone:
	- `cn` - Identifier,
	- `0.5,0.65,-0.6` - Cone position (x, y, z),
	- `0,1,0` - Cone orientation (x, y, z) in range [-1.0, 1.0],
	- `0.25` - Cone diameter,
	- `0.5` - Cone height,
	- `255,255,255` - RGB color of the cone.

Additionally you can specify the the material of the object with the following parameters:
	- `m:` - Material identifier,
	- `plastic` - Plastic material,
	- `metallic` - Metallic material,
	- `dielectric` - Dielectric material.

You can also specify the texture and normal map of the object with the following parameters (only for planes and spheres):
	- `t:` - Texture identifier,
	- `assets/textures/metal.bmp` - Path to the texture file,
	- `n:` - Normal map identifier,
	- `assets/textures/metal_normal.bmp` - Path to the normal map file.

## Installation
To install miniRT on linux, you need following dependencies:
```bash
sudo apt-get update
sudo apt-get install build-essential -y
sudo apt-get install libreadline-dev -y
sudo apt-get install xorg -y
sudo apt-get install libxext-dev -y
```
Then you can clone the repository and compile the program:
```bash
git clone https://github.com/KarenDanielyan/miniRT.git
cd miniRT
make
```
## Usage
To run the program, you need to provide a scene description file with the `.rt` extension. You can find some example scenes in the `scenes` directory. To render a scene, run the following command:
```bash
./miniRT scenes/test.rt
```
You can also save the rendered image to a BMP file by pressing the `s` key after the render is finished.
