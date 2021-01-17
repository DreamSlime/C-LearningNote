# Samba共享服务器



##### Ubuntu：

**安装samba服务器：**

确认安装： dpkg -l | grep samba
安装：sudo apt-get instsall samba samba-common
卸载：sudo apt-get autoremove samba

**Samba服务器配置：**

sudo vim /etc/samba/smb.conf
在文件末尾添加：

~~~shell
[Share]
comment = This is samba dir
path = /home/用户名 #这里改成用户名，即选择home目录下用户名文件夹作为samba的目录
writable = yes
browseable = yes
~~~

增加samba用户,终端输入

~~~shell
smbpasswd -a 用户名
~~~

**启动和关闭：**

启动Samba服务器： sudo service smbd start
关闭samba服务器：  sudo service smbd stop

 通过在linux终端下输入 ifconfig

![image-20210113002623004](picture\ip地址.png)

即可查看本机的局域网内的ip。
在window上判断确定能ping同该ip后，即可在

![image-20210113003244820](picture\打开samba服务器.png)

这个地方输入\\\\192.168.XXX.XXX即可访问slime文件夹下的文件系统。并且可以实现增删改操作。

**设置开机自启：**

~~~shell
sudo systemctl enable 服务名
~~~

常用的服务命令：

>- 打开服务:sudo systemctl start foobar
>- 关闭服务:sudo systemctl stop foobar
>- 重启服务:sudo systemctl restart foobar
>- 不中断正常功能下重新加载服务:sudo systemctl reload foobar
>- 设置服务的开机自启动:sudo systemctl enable foobar
>- 关闭服务的开机自启动:sudo systemctl disable foobar
>- 查看活跃的单元:systemctl list-units
>- 查看某个服务的状态:systemctl status foobar
>- 查看已启动的服务列表： systemctl list-unit-files|grep enabled
>- 查看启动失败的服务列表：systemctl --failed