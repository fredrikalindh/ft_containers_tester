# ft_containers_tester

Tester for ft_containers.
To run this gtest has to be installed. Do this with the gtest_installer.sh
If it doesn't work you have to install cmake first: Do this with brew install cmake

To use the test place your hpp files in the includes folder and uncomment the 
files you have in ft.hpp. It is expected that the containers are names as in the 
subject in namespace ft with lowercase name as ft::vector.

To run the test
``make && ./unitTester`` to run the basic tests
``make bonus && ./unitTester`` to run the bonus tests 
``make all && ./unitTester`` to run the all tests 
``make ``container_name``&& ./unitTester`` to run the container_name test
``make stdlib && ./unitTester`` to run the tests with the STL containers


