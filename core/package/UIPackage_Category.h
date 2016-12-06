//
// Created by liu on 2016/12/5.
//

#ifndef TCUIEDIT_UIPACKAGE_CATEGORY_H
#define TCUIEDIT_UIPACKAGE_CATEGORY_H

#include "../UICore.h"
#include "UIPackage_Base.h"

namespace TCUIEdit
{
    class UIPackage_Category : public UIPackage_Base
    {
    protected:
        QVector<UIBase_Category *> data;
    public:
        UIPackage_Category(UIPackage* package);

        UIBase_Category *TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        void readLine(QString &str);

        //void readComment(QString &str, COMMENT_TYPE cType);
    };

};


#endif //TCUIEDIT_UIPACKAGE_CATEGORY_H
