# VulkanEngine

Minimalistic engine using Vulkan. I currently have only Mac so setup for different platforms might differ a bit. I used [vulkan-tutorial.com](https://vulkan-tutorial.com/) as a starting point.

### Requirements
- [Vulkan SDK](https://vulkan.lunarg.com/)
- [GLFW](https://www.glfw.org/)
- [GLM](https://github.com/g-truc/glm)
- [GCC](https://gcc.gnu.org/)

### Installation

First, download `Vulkan SDK` and follow the installation instructions. On mac, you can install `glfw` and `glm` with `homebrew`

```
brew install glfw
brew install glm
```

MacOS by default is using `clang` compiler. To switch to `gcc`

```
brew install gcc
```

And use `g++-11` to compile with `gcc` instead.

### Building
Once you have everything installed (be sure you have VULKAN_SDK environment variable set), using the provided makefile

```
make
./ve
```
