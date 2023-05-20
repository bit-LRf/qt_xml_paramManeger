#include "xmlcore.h"

bool xmlCore::xmlExample()
{
    m_file->setFileName("xmlParamExample.xml");

    m_document->clear();

    m_out_stream = new QTextStream(m_file);

    if(!m_file->open(QFile::WriteOnly | QFile::Truncate))
    {
        return false;
    }

    QDomProcessingInstruction instruction;

    instruction = m_document->createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");

    m_document->appendChild(instruction);

    QDomElement root = m_document->createElement(rootName);
    m_document->appendChild(root);

    QDomElement exampleParam1 = m_document->createElement("Param1");
    exampleParam1.setAttribute("type","int");

    QDomElement exampleParam1_value = m_document->createElement("value");
    text = m_document->createTextNode("100");

    exampleParam1_value.appendChild(text);
    exampleParam1.appendChild(exampleParam1_value);
    root.appendChild(exampleParam1);

    QDomElement exampleParam2 = m_document->createElement("Param2");
    exampleParam2.setAttribute("type","double");

    QDomElement exampleParam2_value = m_document->createElement("value");
    text = m_document->createTextNode("1.25");

    exampleParam2_value.appendChild(text);
    exampleParam2.appendChild(exampleParam2_value);
    root.appendChild(exampleParam2);

    QDomElement exampleParam3 = m_document->createElement("Param3");
    exampleParam3.setAttribute("type","Eigen::MatrixXd");

    QDomElement exampleParam3_value = m_document->createElement("value");
    text = m_document->createTextNode("\n\t1 0 2\n\t0 1 0\n\t2 3 5\n\t");

    exampleParam3_value.appendChild(text);
    exampleParam3.appendChild(exampleParam3_value);
    root.appendChild(exampleParam3);

    m_document->save(*m_out_stream,4);

    m_file->close();

    m_file->setFileName(fileName);

    m_document->clear();

    m_out_stream = new QTextStream(m_file);

    qDebug()<<"请查看案例,你可以自定义参数(Param)的名称";

    return true;
}
