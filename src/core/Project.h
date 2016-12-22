//
// Created by liu on 2016/12/4.
//

#pragma once

#include "core.h"
#include "Map.h"
#include <QMultiHash>

namespace TCUIEdit { namespace Core
{
    class Project
    {
        // friend class UIBase;

    protected:
        Map uiMap;
        QMultiHash<QString, UI::WEString *> weStringMap;
        QList<Package::Package *> uiPkg;
    public:
        Map *getUIMap()
        { return &this->uiMap; }

        QMultiHash<QString, UI::WEString *> *getWEStringMap()
        { return &this->weStringMap; }

        Package::Package *createPackage();

        Package::Package *createPackage(const QString &basePath, const QString &name);

        UI::Base *matchUI(const QString &name, UI::Base::TYPE type) const;


    };


}}


