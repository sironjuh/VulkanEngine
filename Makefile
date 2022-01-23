INCFLAGS  = -I./src
INCFLAGS += -I$(VULKAN_SDK)/include
INCFLAGS += -I/usr/local/include

CFLAGS  = -std=c++17
CFLAGS += -Wall
CFLAGS += -O2
CFLAGS += $(INCFLAGS)

LDFLAGS  = -L$(VULKAN_SDK)/lib -lvulkan
LDFLAGS += `pkg-config --static --libs glfw3`

SRC = $(shell find src -name "*.cpp")

ve: src/*.cpp src/*.hpp
	g++-11 $(CFLAGS) -o ve $(SRC) $(LDFLAGS)
