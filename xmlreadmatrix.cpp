#include "xmlcore.h"

bool xmlCore::xmlRead(std::string cName,Eigen::MatrixXd& matrix)
{
    QString matrix_qString = xmlRead(cName);

    if(matrix_qString == "")
    {
        return false;
    }

    QVector<double> matrix_vector;

    int size = matrix_qString.size();

    QString value;
    QString value_reverse;

    int row = matrix.rows();

    int col = matrix.cols();

    int i = 0;

    bool value_falg;

    while (i < size)
    {
        value_falg = false;

        value.clear();

        value_reverse.clear();

        while (matrix_qString[i] != "\t" && matrix_qString[i] != "\n" && matrix_qString[i] != " ")
        {
            value_falg = true;

            value_reverse.insert(0,matrix_qString[i]);

            i += 1;
        }

        if(value_falg)
        {
            for(int j = 0; j < value_reverse.size(); j++)
            {
                value.insert(0,value_reverse[j]);
            }

            matrix_vector.insert(matrix_vector.begin(),value.toDouble());

            value_falg = false;
        }

        i += 1;

    }

    if(matrix_vector.size() != row*col)
    {
        qDebug()<<"矩阵元素数量不一致";

        return false;
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            matrix(i,j) = matrix_vector[matrix_vector.size() - 1 - i*col - j];
        }
    }

    return true;
}
