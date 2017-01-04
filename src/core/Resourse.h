//
// Created by liu on 17-1-3.
//

#pragma once

#include "core.h"
#include "ui/Base.h"

namespace TCUIEdit { namespace core
{
    class Resourse
    {
    private:
        Resourse();

        Resourse(const QString &path);

        static Resourse *m_singleton;

        QString m_typeDefineText[ui::Base::TYPE_NUM + 1];

        QString m_license;

    public:
        static void construct(const QString &path);

        static void destruct();

        static const QString &typeDefineText(ui::Base::TYPE type);

        static const QString &license();

    };

}}