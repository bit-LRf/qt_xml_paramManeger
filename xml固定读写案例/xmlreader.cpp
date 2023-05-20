#include "xmlreader.h"

xmlReader::xmlReader(std::string value)
{
    QString fileName = QString(QString::fromLocal8Bit(value.c_str()));

    QFile file(fileName);

    if(!file.open(QFile::ReadOnly))
    {
        return;
    }

    QDomDocument doc;

    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }

    file.close();

    QDomElement root = doc.documentElement();

    QDomNode node = root.firstChild();

    qDebug()<<root.nodeName();

    while(!node.isNull())
    {
        if(node.isElement())
        {
            QDomElement e = node.toElement();

            qDebug()<<e.tagName()<<": "<<e.attribute("id")<<": "<<e.attribute("time");

            qDebug()<<e.nodeName()<<": "<<e.toElement().text();

            QDomNodeList list = e.childNodes();

            for(int i = 0; i < list.count(); i++)
            {
                QDomNode n = list.at(i);

                if(node.isElement())
                {
                    qDebug()<<n.nodeName()<<": "<<n.toElement().text();
                }
            }
        }

        node = node.nextSibling();
    }
}
