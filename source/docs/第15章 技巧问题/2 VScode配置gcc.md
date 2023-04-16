# 15.2 VScode配置gcc

## 1.1 下载gcc
https://github.com/niXman/mingw-builds-binaries/releases

## 1.2 配置环境变量bin目录

## 1.3 vscode安装c/c++插件

调试运行会生成c_cpp_properties.json和tasks.json文件

## 1.4 vscode调用终端

添加launch.json文件
externalConsole为true会调用终端

```
{

    // Use IntelliSense to learn about possible attributes.

    // Hover to view descriptions of existing attributes.

    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387

    "version": "0.2.0",

    "configurations": [

  

        {

            "name": "(gdb) Launch",

            "preLaunchTask": "g++.exe build active file",//调试前执行的任务，就是之前配置的tasks.json中的label字段

            "type": "cppdbg",//配置类型，只能为cppdbg

            "request": "launch",//请求配置类型，可以为launch（启动）或attach（附加）

            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",//调试程序的路径名称

            "args": [],//调试传递参数

            "stopAtEntry": false,

            "cwd": "${workspaceFolder}",

            "environment": [],

            "externalConsole": true,//true显示外置的控制台窗口，false显示内置终端

            "MIMode": "gdb",

            "miDebuggerPath": "D:\\MinGw64\\bin\\gdb.exe",

            "setupCommands": [

                {

                    "description": "Enable pretty-printing for gdb",

                    "text": "-enable-pretty-printing",

                    "ignoreFailures": true

                }

            ]

        }

    ]

}
```


## 1.5 include包含出错

vscode默认编译器是vs，使用gcc需要更改配置

![image.png](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/202302140821922.png)

输入下面代码查看路径
```bash
g++ -v -E -x c++ -
```
![image.png](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/202302140822171.png)

![image.png](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/202302140821261.png)
