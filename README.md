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
Copy the `./include` directory and `libFastLSH.a` into your project and link them in your source code and makefile.  
You can find an example project in `./example` directory

## Example
An example project is in `./example`

    #include "LSH.h"
    int main() {

    //new object of LSH
    LSH mlsh(1000,1000,56,200,1,1.2,100);

    //read from file		
    mlsh.loadSetQ("./dataset/dataset1000NoIndex.csv",0);
    mlsh.loadSetN("./dataset/dataset1000NoIndex.csv",0);

    mlsh.setComputeMode(1);
    mlsh.setThreadMode(1);

    mlsh.reportStatus();

    vector2D candidate = mlsh.getCandidateSet();

    // you can put your code here and use the candidate in the next step

    return 0;
    }

## Attention
The most common error during runtime is  
   `  Environment variable CLASSPATH not set!`   
   `  getJNIEnv: getGlobalJNIEnv failed`  
follow instruction in this [link](http://archive.cloudera.com/cdh/3/hadoop/libhdfs.html#Common+Problems) -- common problems section will most likely solve the problem

## Documentation



