#include "xmlcore.h"

xmlCore::xmlCore(std::string value)
{
//    std::string cstring;
//    QString qstring;
//    //从std::string 到QString
//    qstring = QString(QString::fromLocal8Bit(cstring.c_str()));
//    //从QString 到 std::string
//    cstring = std::string((const char *)qstring.toLocal8Bit().constData());

    isRight = false;

    fileName = QString(QString::fromLocal8Bit(value.c_str()));

    rootName = "parameters";

    m_file = new QFile(fileName);

    m_document = new QDomDocument;

    m_out_stream = new QTextStream(m_file);

    xmlCheck();
}

bool xmlCore::xmlCheck()
{
    if(!doc_load())
    {
        return false;
    }

    QDomElement root = m_document->documentElement();

    if(root.nodeName() != rootName)
    {
        qDebug()<<"Check:根目录错误";

        xmlExample();

        return false;
    }

    QDomNode node = root.firstChild();

    paramName_vector.clear();

    while (!node.isNull())
    {
        if(node.isElement())
        {
            QString paramName = node.nodeName();

            if(paramNameCheck(paramName))
            {
                paramName_vector.insert(paramName_vector.begin() , paramName);
            }
            else
            {
                isRight = false;

                return false;
            }
        }

        node = node.nextSibling();
    }

    isRight = true;

    return true;
}

bool xmlCore::paramNameCheck(QString paramName)
{
    int size = paramName_vector.size();

    for(int i = 0; i < size; i++)
    {
        if(paramName == paramName_vector[i])
        {
            qDebug()<<"Check:出现重复参数:"<<paramName<<"为避免错误请自行整理";

            return false;
        }
    }

    return true;
}

bool xmlCore::doc_load()
{
    if(!m_file->open(QFile::ReadOnly))
    {
        qDebug()<<"文件读取失败";

        return false;
    }
    if(!m_document->setContent(m_file))
    {
        qDebug()<<"文件解析错误";

        m_file->close();

        return false;
    }
    m_file->close();

    return true;
}

bool xmlCore::doc_write()
{
    if(!m_file->open(QFile::WriteOnly | QFile::Truncate))
    {
        qDebug()<<"文件写入失败";

        return false;
    }

    m_document->save(*m_out_stream,4);

    m_file->close();

    return true;
}


