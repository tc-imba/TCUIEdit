//
// Created by liu on 2016/12/4.
//

#pragma once

#include "core.h"
#include "ui/Base.h"
#include <QMultiHash>

namespace TCUIEdit { namespace core
{
    class Project
    {
        // friend class UIBase;

    protected:
        QMultiHash<QString, ui::Base *> m_uiMap;
        QMultiHash<QString, ui::WEString *> weStringMap;
        QList<package::Package *> m_packages;
    public:
        /*Map *getUIMap()
        { return &this->uiMap; }*/

        QMultiHash<QString, ui::WEString *> *getWEStringMap()
        { return &this->weStringMap; }

        package::Package *createPackage();

        package::Package *createPackage(const QString &basePath, const QString &name);

        QList<package::Package *> *packages();

        void addUI(ui::Base *UI);

        QList<ui::Base *> getUI(const QString &name) const;

        QList<ui::Base *> examineUI(const ui::Base *UI) const;

        void removeUI(ui::Base *UI);

        ui::Base *matchUI(const QString &name, ui::Base::TYPE type) const;



    };


}}


