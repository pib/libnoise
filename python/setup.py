from Cython.Distutils import build_ext
from setuptools import setup, find_packages
from distutils.extension import Extension

ext_modules = [Extension(
        'noise.c_noise',
        ['noise/c_noise.pyx'],
        language="c++",
        include_dirs=['../src'],
        libraries=['noise'],
        extra_link_args=['-L../src/.libs'],
        )]

setup(
    name = 'noise',
    packages = find_packages(),
    cmdclass = {'build_ext': build_ext},
    ext_modules = ext_modules,
)
