#include "xmlcore.h"

QString xmlCore::xmlRead(std::string cName)
{
    QString qName = QString(QString::fromLocal8Bit(cName.c_str()));

    QString value_qString;

    if(!doc_load())
    {
        return "";
    }

    QDomElement root = m_document->documentElement();
    QDomNode node = root.firstChild();
    QDomElement param;
    bool breakFlag = false;
    while(!node.isNull())
    {
        if(node.nodeName() == qName)
        {
            param = node.toElement();

            QDomNodeList list = param.childNodes();

            for(int i = 0; i < list.count(); i++)
            {
                QDomNode n = list.at(i);

                if(n.nodeName() == "value")
                {
                    value_qString = n.toElement().text();

                    breakFlag = true;

                    break;
                }
            }

            if(breakFlag)
            {
                break;
            }
        }

        node = node.nextSibling();
    }

    if(breakFlag)
    {
        return value_qString;
    }
    else
    {
        qDebug()<<"read:找不到参数:"<<qName<<"的值";

        return "";
    }
}

bool xmlCore::xmlRead(std::string cName, int& value)
{
    QString value_qString = xmlRead(cName);

    if(value_qString == "")
    {
        return false;
    }

    value =value_qString.toInt();

    return true;
}

bool xmlCore::xmlRead(std::string cName, double& value)
{
    QString value_qString = xmlRead(cName);

    if(value_qString == "")
    {
        return false;
    }

    value =value_qString.toDouble();

    return true;
}

bool xmlCore::xmlRead(std::string cName, std::string& value)
{
    QString value_qString = xmlRead(cName);

    if(value_qString == "")
    {
        return false;
    }

    value =value_qString.toStdString();

    return true;
}




