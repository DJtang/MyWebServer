# MyWebServer

## Introduction

linux下高并发c++http服务器，经过webbench压力测试，可以达到30000多的QPS

## Envoirment

- OS: Ubuntu 16.04 
- C++版本：14
- Mysql：ver 14.14 Distrib 5.7.33, for Linux

## Technical points

- 利用io复用技术Epoll以及线程池实现多进程多线程的Reactor并发模型；
- 利用正则与状态机解析HTTP请求报文，实现处理静态资源的请求；
- 利用标准库容器，实现自动增长的缓冲区；
- 基于最小堆实现定时器，实现心跳机制，清除超时非活动连接
- 利用RAII机制实现数据库连接池，减少数据库连接建立与关闭的开销

## Business functions

- 登录和注册
- 播放视频
- 查看图片
- 文件上传 （只能上传小文件)

## Model

![网络模型](https://cdn.jsdelivr.net/gh/DJtang/picx_ima@main/网络模型.204t2i64owg0.webp)

## TODO

- 静态文件预先加载进入内存，加快访问
- 快速路由
- 大文件的上传

## Reference

- Linux高性能服务器编程 游双著
- Linux多线程服务端编程---使用muduo C++网络库  陈硕著 
-  [TinyWebServer]( https://github.com/qinguoyi/TinyWebServer)
