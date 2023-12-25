<h1 align="center">
	FDF
</h1>

<p align="center">
  <b><i>Visualizing maps in 3D space</i></b>
</p>

---
<img width="1478" alt="Martian Landscape" src="https://github.com/kbly538/FdF/assets/4437722/cf29280b-14ee-41b1-9f18-bed07b96484f">
<img width="1478" alt="Ekran Resmi 2023-12-25 02 27 25" src="https://github.com/kbly538/FdF/assets/4437722/7463d3ff-4de4-4353-bff1-ff9d842c40c9">
<img width="1434" alt="Ekran Resmi 2023-12-25 02 29 01" src="https://github.com/kbly538/FdF/assets/4437722/47e9d8b1-0559-433a-9b57-52db0f7299ad">

## About

Designed to deepen the understanding of computer graphics leveraging MiniLibX graphics library, FdF is a 3D wireframe renderer. It serves as an educational tool, offering hands-on experience in transforming and projecting 3D objects onto a 2D screen. The project is meticulously structured to cover key concepts in graphics, including projections, rotations, and color representation.

## Requirements

- **Operating System:** Linux or macOS
- **Libraries:**
  - ft_printf(Custom library that imitates printf)
  - libft (Custom library with various utility functions)
  - [MiniLibX MacOS](https://github.com/dannywillems/minilibx-mac-osx) (Minimalist graphics library for MacOS)
  - [MiniLibX Linux](https://github.com/42Paris/minilibx-linux) (Minimalist graphics library for Linux)

## Installation

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/kbly538/FdF.git
   cd FdF
2. **Build the Project**
   ```bash
   make
3. **Run the Program**
   ```bash
   ./fdf [map_file]

4. **Example Map File**

   ```txt
   0 0 0 0 0
   0 9 9 7 0
   0 0 6 0 0

Each number represents a point in space:<br>
• The horizontal position corresponds to its **axis**.<br>
• The vertical position corresponds to its **ordinate**.<br>
• The value corresponds to its **altitude**.

Replace `[map_file]` with the path to your desired map file.


## Features

- **3D Wireframe Rendering:** FdF employs 3D wireframe rendering to visualize maps.
- **Projections:** Supports various projections, including isometric and parallel projections.
- **Coloring:** Maps can be colored based on height or custom palettes.
- **User Controls:** Interactive controls for zooming, panning, and rotating the view.
- **Information Screen:** Displays real-time information about rendering, angles, and more.
- **Dynamic Updates:** Real-time updates and rendering with keyboard and mouse controls.
- **Map Loading:** Supports loading maps from file for dynamic rendering.
- **Auto-Rotation:** Option for automatic rotation of the map.
---
### Controller Schema
#### Mouse Controls
- **`Hold RMB and drag:`** Panning the 3D scene. (After activating Free Projection)
- **`Mouse Wheel:`** Zoom in and out.
- **`Space + RMB and drag:`** Reset the view to default.

#### Keyboard Controls
- **`1, 2, 3 ,4:`** Isometric, Parallel, Free, Topdown respectively.
- **`Q, A:`** Rotate around X axis. (Free Projection)
- **`W, S:`** Rotate around Y axis. (Free Projection)
- **`E, D:`** Rotate around Z axis. (Free Projection)
- **`Z, X:`** Change height multiplier
- **`Enter:`** Toggle auto-rotation. (Free Projection)
- **`ESC:`** Close the program.

