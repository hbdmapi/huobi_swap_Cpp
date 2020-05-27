## Installlation

### Installation

*The SDK is compiled by C++ 11*.

编译器可以使用gcc也可以使用clang.

Currently, The SDK has the compatibility on linux system(centos 7 and ubuntu 18.04) only.

Later, macOS and windows.

#### Install CMake

Please make sure the CMake is installed on your OS.

If not, you can follow <https://cmake.org/install/> to install it.

The minimum required version of CMake is 2.8, but we suggest to use the lastest CMake version.

#### Install 3rd party

Please make sure the 3rd party libraries have been installed in your system. If not, please install them.

OpenSSL - <https://github.com/openssl/openssl>

curl - <https://github.com/curl/curl>

libwebsocket - <https://libwebsockets.org/git/libwebsockets/tree/?h=v3.1-stable>


#### 安装依赖包

ubuntu 18.04:
````
$ sudo apt install cmake
#openssl 1.1.1
$ sudo apt install openssl
$ sudo apt install libssl-dev
#curl
$ sudo apt install curl libcurl4-openssl-dev
#zip
$ sudo apt install zlib1g-dev
````

centos 7   

````
$ sudo yum install cmake
#openssl 1.0.2
$ sudo yum install openssl openssl-devel
#curl
$ sudo yum install libcurl libcurl-devel
#libwebsockets v3.1.0
$ sudo yum install epel-release
$ sudo yum install libwebsockets libwebsockets-devel
#zip
$ sudo yum install zlib zlib-devel

$ sudo yum install centos-release-scl-rh centos-release-scl scl-utils-build scl-utils
$ sudo yum check-update

#安装clang 最低3.4.2 最高5.0.1 此处使用5.0.1
$ sudo yum install devtoolset-7-llvm
$ echo "source /opt/rh/llvm-toolset-7/enable" >> $HOME/.bashrc
$ source $HOME/.bashrc
#安装gcc 最低4.9.2 最高7.3.1 此处使用7.3.1
$ sudo yum install devtoolset-7-toolchain
$ echo "source /opt/rh/devtoolset-7/enable" >> $HOME/.bashrc
$ source $HOME/.bashrc
````

macOS 10.14.5

````
#openssl 1.0.2
$ brew install openssl
#libwebsockets v3.1.0
$ brew install libwebsockets
#curl
$ brew install curl curl-openssl
#zlib
$ brew install zlib
#gtest
$ brew install --HEAD https://gist.githubusercontent.com/huobiapi/e81f3714d37c7d92c3e9e6b6566a4cbe/raw/39f1a42024cecb40d0436b03acd67c0abe6d9571/gtest.rb
````

从源码编译安装libwebsockets v3.1.0:

参考: <https://libwebsockets.org/>
````
$ git clone https://github.com/warmcat/libwebsockets.git
$ git reset --hard 89eedcaa94e1c8a97ea3af10642fd224bcea068f
$ cd libwebsockets
$ mkdir build
$ cd build
$ cmake ..
$ make
$ sudo make install
````

#### Build SDK

You should check the C++ 11 build environment.

To build the SDK, you should build the decnumber firstly.

``````
$ git clone https://github.com/HuobiRDCenter/libdecnumber.git
$ cd libdecnumber
$ mkdir build
$ cd build
#使用clang
$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_COMPILER_TYPE=CLANG
#使用gcc
$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_COMPILER_TYPE=GCC
$ make
$ sudo make install
``````

Then build the SDK library

```
$ git clone https://github.com/hbdmapi/huobi_swap_Cpp.git
$ cd huobi_swap_Cpp
$ mkdir build
$ cd build
#使用clang
$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_COMPILER_TYPE=CLANG
#使用gcc
$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_COMPILER_TYPE=GCC
$ make
$ sudo make install
```

#### Run example 

```
<In huobi_swap_Cpp folder>
$ cd examples
$ cd RequestContractInfo
$ mkdir build
$ cd build
#使用clang
$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_COMPILER_TYPE=CLANG
#使用gcc
$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_COMPILER_TYPE=GCC
$ make
```

