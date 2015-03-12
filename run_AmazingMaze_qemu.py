#!/usr/bin/env python
# coding=utf-8
import os
import sys

exe = '/Applications/Marmalade.app/Contents/s3e/bin/s3e'
if os.name == 'nt':
    exe += '.bat'

cmd = list(sys.argv)
cmd[0] = exe

cmd.append('-via:"/Users/xiaolilillytang/Desktop/AmazingMaze/build_amazingmaze_scons_arm/AmazingMaze_gcc_release.via"')
os.execvp(cmd[0], cmd)
