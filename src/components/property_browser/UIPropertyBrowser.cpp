//
// Created by liu on 2016/12/21.
//

#include "UIPropertyBrowser.h"

namespace TCUIEdit
{
    UIPropertyBrowser::UIPropertyBrowser(QWidget *parent) : QTreeView(parent)
    {
        this->model = new UIPropertyBrowserModel(this);
    }

    UIPropertyBrowser::~UIPropertyBrowser()
    {
        delete this->model;
    }

    void UIPropertyBrowser::addCategory()
    {

    }


};