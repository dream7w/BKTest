/*==========================================
  @Author      : zabambo
  @File        : src/db_mysql.cc
  @Encoding    : utf-8
  @Create      : 2014-06-21 15:43:07
  @Modified    : 2014-06-21 15:45:08
  @Description : 
==========================================*/
/*
与MySQL交互时，应用程序应使用该一般性原则：
1.    通过调用mysql_library_init()，初始化MySQL库。库可以是mysqlclient C客户端库，或mysqld嵌入式服务器库，具体情况取决于应用程序是否与“-libmysqlclient”或“-libmysqld”标志链接。
2.    通过调用mysql_init()初始化连接处理程序，并通过调用mysql_real_connect()连接到服务器。
3.    发出SQL语句并处理其结果。（在下面的讨论中，详细介绍了使用它的方法）。
4.    通过调用mysql_close()，关闭与MySQL服务器的连接。
5.    通过调用mysql_library_end()，结束MySQL库的使用。
*/



#include "db_mysql.h"


