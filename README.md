Phalcon++ Framework
===================

Phalcon++ is copy from Phalcon7, Use C++ rewrite it.

### Linux/Unix/Mac

On a Unix-based platform you can easily compile and install the extension from sources.

编译安装（Compilation）
-----------------------

下载源码（Download sources）

```shell
git clone https://github.com/dreamsxin/cpphalcon.git
# git submodule update --init --recursive
```

编译安装 PHP-CPP
```shell
cd DependentExtensions/PHP-CPP/
make && sudo make install
```

编译安装 Phalcon++
```shell
make clean
make && sudo make install
```

测试
```shell
php --ri phalcon++
```

参与项目规则
------------
参照 Phalcon7 功能，头文件需要加入类以及方法的注释。
遇到变量名或方法名是 C++　关键字的添加前缀下划线`_`。


代码风格（Source formatter）
---------------------------
- Style: Linux
- Indentation size(in spaces): 4
- Use TABs instead of spaces
- Indent namespaces