test2.o .d/test2.d : test2.cpp
test2.bin: test2.o
	$(CXX) $(CXXFLAGS) $(LIBARYFLAGS) -o $@ $^
