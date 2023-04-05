# 16.1 Drogen

## 1、安装

`vcpkg install drogon[ctl]:x64-windows`

配置环境变量

![](http://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/20221125141641.png)

> 如果不安装ctl，在tools文件夹里不会出现drogen


## 2、快速开始

创建项目

`drogon_ctl create project your_project_name`

项目目录

├── build                         构建文件夹
├── CMakeLists.txt                工程的cmake配置文件
├── config.json                   drogon应用的配置文件
├── controllers                   存放控制器文件的目录
├── filters                       存放过滤器文件的目录
├── main.cc                       主程序
├── models                        数据库模型文件的目录
│   └── model.json
└── views                         存放视图csp文件的目录

构建
在build文件夹下cmake ..

![](http://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/20221125172514.png)

使用vs打开，将debug改为release，否则会报错

![](http://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/20221125172630.png)


![](http://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/20221125172437.png)

