CFLAGS = -std=c++17 -I. -I$(VULKAN_SDK)/include -I/usr/local/include
LDFLAGS = -L$(VULKAN_SDK)/lib `pkg-config --static --libs glfw3` -lvulkan

a.out: *.cpp *.hpp
	g++-11 $(CFLAGS) -o a.out *.cpp $(LDFLAGS)
