INCFLAGS  = -I./src
INCFLAGS += -I$(VULKAN_SDK)/include
INCFLAGS += -I/usr/local/include

CFLAGS  = -std=c++17
CFLAGS += $(INCFLAGS)

LDFLAGS = -L$(VULKAN_SDK)/lib `pkg-config --static --libs glfw3` -lvulkan

ve: src/*.cpp src/*.hpp
	g++-11 $(CFLAGS) -o ve src/*.cpp $(LDFLAGS)
