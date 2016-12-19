//
// Created by liu on 2016/12/5.
//

#ifndef TCUIEDIT_UIBASE_CATEGORY_H
#define TCUIEDIT_UIBASE_CATEGORY_H

#include "../UICore.h"
#include "UIBase.h"

namespace TCUIEdit
{
    //***************************************************************************
    // [TriggerCategories]
    // Defines categories for organizing trigger functions
    // Key: Arbitrary category identifier

    // Value 0: Display text
    // Value 1: Icon image file
    // Value 2: Optional flag (defaults to 0) indicating to disable display of category name


    class UIBase_Category : public UIBase
    {

    protected:
        QString icon, displayFlag;
    public:
        UIBase_Category(UIPackage *package, QPair<QString, QStringList> pair);

        const QString getDisplayName() const;

        void displayDetail(UIMainTree *tree);
    };
};


#endif //TCUIEDIT_UIBASE_CATEGORY_H
