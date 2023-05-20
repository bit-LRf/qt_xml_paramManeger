#include "xmlcore.h"

//每次使用本案例前请删除所有子节点（参数）
int main(int argc, char *argv[])
{
    //加载
    std::string fileName = "xmlParamExample.xml";
    xmlCore m_xmlCore(fileName);

    //加载一个案例，使用这个会使重复参数检查失效（如果案例文件和打开的文件同名的话）
    m_xmlCore.xmlExample();

    //写入参数int
    int a = 100;

    m_xmlCore.xmlWrite("a",a);

    //写入参数double
    double b = 0.1;

    m_xmlCore.xmlWrite("b",b);

    //写入参数str
    std::string str = "hello world";

    m_xmlCore.xmlWrite("string",str);

    //写入参数matrix

    Eigen::MatrixXd matrix{3,2};

    matrix <<
    1.2 , 5.1 ,
    2.3 , 0.9 ,
    0 , 4;

    m_xmlCore.xmlWrite("matrix",matrix);

    //正常读取参数,需要初始化
    Eigen::MatrixXd m{3,2};

    m_xmlCore.xmlRead("matrix",m);

    std::cout<<m<<std::endl;

    m_xmlCore.xmlRead("string",str);

    std::cout<<str<<std::endl;

    //读取参数，参数存在但是数据类型不对的情况
    int b_int = 2;

    m_xmlCore.xmlRead("b",b_int);

    std::cout<<b_int<<std::endl;

    //读取参数，参数不存在的情况
    m_xmlCore.xmlRead("non",matrix);

    std::cout<<matrix<<std::endl;

    //多次写入同名参数,会发出警告
    b = 0.1;

    m_xmlCore.xmlWrite("b",b);

    //如果是一个其他类型的值，也可以读出来，返回QString
    QString qstr;

    Eigen::MatrixXd test1{2,3};

    m_xmlCore.xmlRead("test1",test1);

    std::cout<<test1<<std::endl;

    qstr = m_xmlCore.xmlRead("test1");

    qDebug()<<qstr;

    return 0;
}
