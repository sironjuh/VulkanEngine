CFLAGS = -std=c++17 -I. -I$(VULKAN_SDK)/include
LDFLAGS = -L$(VULKAN_SDK)/lib `pkg-config --static --libs glfw3` -lvulkan

a.out: main.cpp
	clang $(CFLAGS) -o a.out main.cpp $(LDFLAGS)
