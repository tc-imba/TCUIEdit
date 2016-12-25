//
// Created by liu on 2016/12/5.
//

#include "Category.h"
#include "../ui/Category.h"

namespace TCUIEdit { namespace core { namespace package
{
    Category::Category(Package *package) : Base(package)
    {

    }


    void Category::readLine(QString &str)
    {
        //QRegExp rx("$");

        auto pair = this->_preprocessLine(str);
        auto item = static_cast<ui::Base *>(new ui::Category(m_pkg, pair));
        m_data.push_back(item);

    }

    /*void Category::readComment(QString &str, COMMENT_TYPE cType)
    {
        QMessageBox msgBox;
        msgBox.setText(str);
        msgBox.exec();
    }*/

}}}