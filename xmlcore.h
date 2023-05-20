#ifndef XMLCORE_H
#define XMLCORE_H

//eigne配置
#include    "Eigen/Dense"
#include    "eigen3/unsupported/Eigen/KroneckerProduct"

//xml配置
#include    <QtXml>
#include    <QDomDocument>
#include    <QXmlStreamReader>

//一般配置
#include "iostream"
#include "vector"

class xmlCore
{
public:
    xmlCore(std::string value);

    bool xmlExample();

    bool xmlWrite(std::string cName , int value);
    bool xmlWrite(std::string cName , double value);
    bool xmlWrite(std::string cName , std::string value);
    bool xmlWrite(std::string cName , Eigen::MatrixXd value);

    QString xmlRead(std::string cName);
    bool xmlRead(std::string cName,int& value);
    bool xmlRead(std::string cName,double& value);
    bool xmlRead(std::string cName,std::string& value);
    bool xmlRead(std::string cName,Eigen::MatrixXd& matrix);

    bool xmlCheck();

    bool paramNameCheck(QString paramName);

    bool isRight;

private:
    bool doc_load();

    bool doc_write();

    QVector<QString> paramName_vector;

    QString fileName;

    QString rootName;

    QFile* m_file;

    QDomDocument* m_document;

    QTextStream* m_out_stream;

    QDomText text;
};

#endif // XMLCORE_H
