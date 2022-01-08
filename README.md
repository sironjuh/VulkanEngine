# VulkanEngine

Minimalistic engine using Vulkan. I currently have only Mac so setup for different platforms might differ a bit.

I used [vulkan-tutorial.com](https://vulkan-tutorial.com/) as a starting point.

### Requirements
- [Vulkan SDK](https://vulkan.lunarg.com/)
- [GLFW](https://www.glfw.org/)
- [GLM](https://github.com/g-truc/glm)

### Installation

First, download `Vulkan SDK` and follow the installation instructions. On mac, you can install `glfw` and `glm` with `homebrew`

```
brew install glfw
brew install glm
```

### Building
Once you  havve everything installed (be sure you have VULKAN_SDK environment variable set), using the privded makefifile

```
make
./a.out
```
