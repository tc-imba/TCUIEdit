//
// Created by liu on 2016/12/21.
//

#include "UIPropertyBrowser.h"

namespace TCUIEdit
{
    UIPropertyBrowser::UIPropertyBrowser(QWidget *parent) : QTreeView(parent)
    {
        this->model = new QStandardItemModel(this);



    }

};