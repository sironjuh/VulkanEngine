CFLAGS = -std=c++17 -I. -I$(VULKAN_SDK_PATH)/include
LDFLAGS = -L$(VULKAN_SDK_PATH)/lib `pkg-config --static --libs glfw3` -lvulkan

a.out: main.cpp
	g++ $(CFLAGS) -o a.out main.cpp $(LDFLAGS)
	