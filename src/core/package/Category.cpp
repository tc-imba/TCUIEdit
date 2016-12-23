//
// Created by liu on 2016/12/5.
//

#include "Category.h"
#include "../ui/Category.h"

namespace TCUIEdit { namespace Core { namespace Package
{
    Category::Category(Package *package) : Base(package)
    {

    }


    void Category::readLine(QString &str)
    {
        //QRegExp rx("$");

        auto pair = this->preprocessLine(str);
        auto item = static_cast<UI::Base *>(new UI::Category(this->_pkg, pair));
        this->data.push_back(item);

    }

    /*void Category::readComment(QString &str, COMMENT_TYPE cType)
    {
        QMessageBox msgBox;
        msgBox.setText(str);
        msgBox.exec();
    }*/

}}}