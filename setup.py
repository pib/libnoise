from setuptools import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension(
        'c_noise',
        ['python/c_noise.pyx'],
        language="c++",
        include_dirs=['src'],
        libraries=['noise'],
        extra_link_args=['-Lsrc/.libs'],
        )]

setup(
    name = 'Python libnoise wrapper',
    cmdclass = {'build_ext': build_ext},
    ext_modules = ext_modules,
    setup_requires = ['setuptools_cython'],
)
