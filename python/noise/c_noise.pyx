cdef extern from 'noise.h' namespace 'noise::module':
     cdef cppclass Perlin:
          Perlin()
          double GetValue(double x, double y, double z)

cdef class Noise_Module_Perlin:
     cdef Perlin *thisptr
     def __cinit__(self):
         self.thisptr = new Perlin()
     def __dealloc__(self):
         del self.thisptr

     def GetValue(self, x, y, z):
         return self.thisptr.GetValue(x, y, z)