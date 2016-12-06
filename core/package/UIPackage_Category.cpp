//
// Created by liu on 2016/12/5.
//

#include <QRegExp>
#include "UIPackage_Category.h"
#include "../base/UIBase_Category.h"

namespace TCUIEdit
{
    UIPackage_Category::UIPackage_Category(UIPackage *package) : UIPackage_Base(package)
    {
        
    }


    void UIPackage_Category::readLine(QString &str)
    {
        //QRegExp rx("$");
        try
        {
            auto pair = this->preprocessLine(str);
            auto item = new UIBase_Category(this->_pkg, pair);
        }

        catch (QException &e)
        {
            throw e;
        }
    }

    /*void UIPackage_Category::readComment(QString &str, COMMENT_TYPE cType)
    {
        QMessageBox msgBox;
        msgBox.setText(str);
        msgBox.exec();
    }*/

};