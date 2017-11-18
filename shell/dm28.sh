#!/bin/bash

echo 获取字符h在第一个字段中的位置
gawk '{print index($1, "h")}' str.txt
echo

echo 获取长度
gawk '{print length($0)}' str.txt
echo

echo 将字符转换为大写字符
gawk '{print toupper($2)}' str.txt
