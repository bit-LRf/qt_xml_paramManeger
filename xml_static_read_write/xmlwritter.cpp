#include "xmlwritter.h"

xmlWritter::xmlWritter(std::string value)
{
    QString fileName = QString(QString::fromLocal8Bit(value.c_str()));

    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Truncate))
    {
        return;
    }

    QDomDocument doc;

    QDomProcessingInstruction instruction;

    instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");

    doc.appendChild(instruction);

    QDomElement root = doc.createElement("parameters");
    doc.appendChild(root);

    QDomElement book = doc.createElement("book");
    book.setAttribute("id",1);

    QDomAttr time = doc.createAttribute("time");
    time.setValue("2023/5/10");
    book.setAttributeNode(time);

    QDomElement title = doc.createElement("title");
    QDomText text;
    text = doc.createTextNode("c++ primer");
    book.appendChild(title);
    title.appendChild(text);

    QDomElement author = doc.createElement("author");
    text = doc.createTextNode("stanley Lippman");
    author.appendChild(text);
    book.appendChild(author);
    root.appendChild(book);

    book = doc.createElement("book");
    book.setAttribute("id",2);
    time = doc.createAttribute("time");
    time.setValue("2007/5/25");
    book.setAttributeNode(time);
    title = doc.createElement("title");
    text = doc.createTextNode("Thinking in Java");
    book.appendChild(title);
    title.appendChild(text);

    author = doc.createElement("author");
    text = doc.createTextNode("Bruce Eckel");
    author.appendChild(text);
    book.appendChild(author);
    root.appendChild(book);

    QDomElement matrix = doc.createElement("matrix");
    text = doc.createTextNode("\n\t1 0 2\n\t0 1 0\n\t2 3 5\n\t");
    matrix.appendChild(text);
    book.appendChild(matrix);

    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}
