include ../Makefile.common

OBJECTS = BinaryReader.o BinaryStreamReader.o BinaryStreamWriter.o BinaryWriter.o BufferedStream.o CodeFormatter.o \
Component.o Container.o FileStream.o InitDone.o Json.o Log.o MappedInputFile.o MemoryReader.o MemoryStream.o \
MemoryWriter.o Mutex.o Path.o Prime.o Process.o ProcessImpl.o Random.o Sha1.o Socket.o SocketFwd.o Stream.o \
SynchronizedQueue.o System.o TextUtils.o Time.o Unicode.o Util.o Uuid.o

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
../../lib/libsngutil.a: $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

clean:
	rm -f *.o
	rm -f ../../lib/libsngutil.a
