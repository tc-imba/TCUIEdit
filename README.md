# TCUIEdit
A WE UI Editor Under QT 5.7.X
地图编辑器 —— UI 编辑器

Build under Clion (CMake 3.6)
使用 CLion 和 CMake 3.6 构建

Windows: mingw53_32
Linux: gcc_64


# Compiling

In CLion, you should set Working Directory to the base path of the project in Configuration and Build with the option `TCUIEdit_automoc`.
在 Clion 中，必须把工作路径设为项目路径，并使用 `TCUIEdit_automoc` 进行编译

After cloned, enter the command below
克隆后，在控制台输入以下命令

```
git update-index --assume-unchanged CMakeConfig.txt
```

Then, edit the file `CMakeConfig.txt` to config your QT Path.
然后编辑 `CMakeConfig.txt` 配置 QT 路径

## For Windows Users

You should add two Path variables (Qt and mingw home)
在系统环境变量中必须添加 Qt 和 mingw 的路径

For example, these two should be added:
比如，添加这两条路径：

```
D:\Qt\Tools\mingw530_32\bin
D:\Qt\5.7\mingw53_32\bin
```

Also, if you have some problem with git on the command line, check if you have the Path of git
同样，如果你在控制台使用 git 时出现问题，检查环境变量中是否有 git

```
C:\Program Files\Git\cmd
```

For those who don't know how to use CLion and CMake, a version with Visual Studio 2015 will be released later.
对于不使用 CLion 和 CMake 的用户，vs2015 版本会在以后推出

## For Linux Users

If you have some compile errors about `gl.h` or `glu.h`, it is because you haven't installed openGL on your system. Then you may install it through the command line (i.e. on Ubuntu):
如果你遇到一些关于 `gl.h` or `glu.h` 的编译错误，是因为你没有安装 openGL，你可以用控制台安装（Ubuntu 的命令如下）

```
sudo apt-get install build-essential
sudo apt-get install libgl1-mesa-dev
sudo apt-get install libglu1-mesa-dev
sudo apt-get install freeglut3-dev
```

## For MacOS Users

The official guide of compilation on MacOS with be released later.
MacOS 编译的官方指南将在以后推出