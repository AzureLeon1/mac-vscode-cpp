# Mac vscode 配置 C/C++ 编译环境

> 2020.2.1 第一次尝试

Code runner插件可以运行，但无法进行调试

官网配置教程：https://code.visualstudio.com/docs/cpp/config-clang-mac

首先配置setting.json，配置编译相关的设置。

再配置launch.json，配置启动调试相关的设置。

先后尝试用 g++ 和 clang 作为编译器配置setting.json，都遇到了同一个问题。

![](http://img.cdn.leonwang.top/20200201185717.png)

**提示command not found**，但实际上zsh的环境变量中是有 g++ 和 clang++ 的。



> 再次尝试

发现vscode的设置里面有这样两条：

```json
"terminal.integrated.env.osx": {
		"PATH": ""
    },
"terminal.integrated.inheritEnv": false,
```

这两条导致vscode的集成终端环境变量是空。

这两条设置是当初因为vscode的终端内的python版本总是默认2.7，而不是iTerm中默认的python3.6。唉，当初为了解决一个问题为后来的问题埋下了坑。

但是现在python插件自动提示完成相关设置，能够同时解决python版本和环境变量的问题。

现在编译没问题了。

**但是现在遇到第二个问题：断点不停**

是因为mac os版本更新导致的问题，可以通过安装插件并重新创建launch.json解决。

解决方案：https://blog.csdn.net/mgsky1/article/details/103825710

实在是下载不动，以后再按照上面的解决方案试试吧。。。



> 第三次

终于下载好了，是vpn网络的问题

大功告成

使用方法：

cmd+shift+B：编译

F5：启动调试

control+F5：非调试方式启动



> 改进

在launch.json中配置pretask为编译任务，可以省去手动执行编译的步骤

直接F5启动，会先重新编译，然后启动调试

缺点的话是每次启动都会重新编译一次，不过编译也很快，问题不大



配置使用clang++进行编译。因为配置这些东西主要是为保研机试准备进行刷题，而大多数高校机试环境可能比较旧，为了适应机试环境，所以编译参数设置为使用c++11标准。

