# FastLSH-Lib
C++ library version of FastLSH. It have been tested on Ubuntu 14.04, 16.04

## Requirement 
* Hadoop >= 2.7.1  
    find installation guide [here](http://hadoop.apache.org/#Download+Hadoop)
* Memcached >= 1.4.34  
    `sudo apt-get update`  
    `sudo apt-get install mysql-server php5-mysql php5 php5-memcached memcached`  
* Redis >= 3.2  
    find installation guide [here](https://www.digitalocean.com/community/tutorials/how-to-install-and-configure-redis-on-ubuntu-16-04)
* OpenMP >= 4.5  
    OpenMP is defaultly in major compilers, you can find related information [here](http://www.openmp.org/resources/openmp-compilers/)
    
## Build
    cmake .  
    make
## To Use
After build, you can find the `libFastLSH.a` in your directory.  
Move the `./include` directory and `libFastLSH.a` into your project and link them in your source code and makefile.  
You can find an example project in `./example` directory

## Example

## Attention

## Documentation



