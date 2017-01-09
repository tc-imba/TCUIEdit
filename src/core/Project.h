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
    protected:
        QMultiHash<QString, ui::Base *> m_uiMap;
        QMultiHash<QString, ui::WEString *> m_weStringMap;
        QMap<QString, QPair<bool, int> > m_categoryNumMap;
        QMap<QString, QPair<bool, int> > m_typeNumMap;
        QList<package::Package *> m_packages;
    public:

        QMultiHash<QString, ui::WEString *> &weStringMap();

        QMap<QString, QPair<bool, int> > &categoryNumMap();

        QMap<QString, QPair<bool, int> > &typeNumMap();

        package::Package *createPackage();

        package::Package *createPackage(const QString &basePath, const QString &name);

        const QList<package::Package *> &packages() const;

        void addUI(ui::Base *ui);

        QList<ui::Base *> getUI(const QString &name) const;

        QList<ui::Base *> examineUI(const ui::Base *ui) const;

        void removeUI(ui::Base *ui);

        ui::Base *matchUI(const QString &name, ui::Base::TYPE type) const;

    };


}}


