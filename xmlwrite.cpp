#include "xmlcore.h"

bool xmlCore::xmlWrite(std::string cName, int value)
{
    if(!doc_load())
    {
        return false;
    }

    QDomElement root = m_document->documentElement();
    m_document->appendChild(root);

    QString qName = QString(QString::fromLocal8Bit(cName.c_str()));
    paramNameCheck(qName);

    QDomElement param = m_document->createElement(qName);
    param.setAttribute("type","int");

    QDomElement param_velue = m_document->createElement("value");

    QString value_qString = QString::number(value);
    text = m_document->createTextNode(value_qString);

    param_velue.appendChild(text);
    param.appendChild(param_velue);
    root.appendChild(param);

    if(!doc_write())
    {
        return false;
    }

    paramName_vector.insert(paramName_vector.begin() , qName);

    return true;
}

bool xmlCore::xmlWrite(std::string cName, double value)
{
    if(!doc_load())
    {
        return false;
    }

    QDomElement root = m_document->documentElement();
    m_document->appendChild(root);

    QString qName = QString(QString::fromLocal8Bit(cName.c_str()));
    paramNameCheck(qName);

    QDomElement param = m_document->createElement(qName);
    param.setAttribute("type","double");

    QDomElement param_velue = m_document->createElement("value");

    QString value_qString = QString::number(value);
    text = m_document->createTextNode(value_qString);

    param_velue.appendChild(text);
    param.appendChild(param_velue);
    root.appendChild(param);

    if(!doc_write())
    {
        return false;
    }

    paramName_vector.insert(paramName_vector.begin() , qName);

    return true;
}

bool xmlCore::xmlWrite(std::string cName, std::string value)
{
    if(!doc_load())
    {
        return false;
    }

    QDomElement root = m_document->documentElement();
    m_document->appendChild(root);

    QString qName = QString(QString::fromLocal8Bit(cName.c_str()));
    paramNameCheck(qName);

    QDomElement param = m_document->createElement(qName);
    param.setAttribute("type","string");

    QDomElement param_velue = m_document->createElement("value");

    QString value_qString = QString(QString::fromLocal8Bit(value.c_str()));
    text = m_document->createTextNode(value_qString);

    param_velue.appendChild(text);
    param.appendChild(param_velue);
    root.appendChild(param);

    if(!doc_write())
    {
        return false;
    }

    paramName_vector.insert(paramName_vector.begin() , qName);

    return true;
}

bool xmlCore::xmlWrite(std::string cName, Eigen::MatrixXd value)
{
    if(!doc_load())
    {
        return false;
    }

    QDomElement root = m_document->documentElement();
    m_document->appendChild(root);

    QString qName = QString(QString::fromLocal8Bit(cName.c_str()));
    paramNameCheck(qName);

    QDomElement param = m_document->createElement(qName);
    param.setAttribute("type","Eigen::MatrixXd");

    QDomElement param_velue = m_document->createElement("value");

    QString value_qString;

    value_qString.append("\n\t");

    for(int i = 0; i < value.rows(); i++)
    {
        for(int j = 0; j < value.cols(); j++)
        {
            value_qString.append(QString::number(value(i,j)));

            if(j != value.cols() - 1)
            {
                value_qString.append(" ");
            }
            else
            {
                value_qString.append("\n\t");
            }
        }
    }

    text = m_document->createTextNode(value_qString);

    param_velue.appendChild(text);
    param.appendChild(param_velue);
    root.appendChild(param);

    if(!doc_write())
    {
        return false;
    }

    paramName_vector.insert(paramName_vector.begin() , qName);

    return true;
}
