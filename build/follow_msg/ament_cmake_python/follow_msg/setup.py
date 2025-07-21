from setuptools import find_packages
from setuptools import setup

setup(
    name='follow_msg',
    version='0.0.0',
    packages=find_packages(
        include=('follow_msg', 'follow_msg.*')),
)
