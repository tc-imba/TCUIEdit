//
// Created by liu on 2016/12/4.
//

#pragma once

#include "core.h"
#include "Map.h"
#include <QMultiHash>

namespace TCUIEdit { namespace core
{
    class Project
    {
        // friend class UIBase;

    protected:
        Map uiMap;
        QMultiHash<QString, ui::WEString *> weStringMap;
        QList<package::Package *> uiPkg;
    public:
        Map *getUIMap()
        { return &this->uiMap; }

        QMultiHash<QString, ui::WEString *> *getWEStringMap()
        { return &this->weStringMap; }

        package::Package *createPackage();

        package::Package *createPackage(const QString &basePath, const QString &name);

        ui::Base *matchUI(const QString &name, ui::Base::TYPE type) const;


    };


}}


