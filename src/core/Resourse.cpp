//
// Created by liu on 17-1-3.
//

#include <QFile>
#include <QTextStream>
#include "Resourse.h"

namespace TCUIEdit { namespace core
{

    Resourse *Resourse::m_singleton = NULL;

    Resourse::Resourse()
    {

    }

    Resourse::Resourse(const QString &path)
    {
        QFile file(path + "LICENSE");
        if (file.open(QFile::ReadOnly))
        {
            m_license = file.readAll();
        }
        file.close();
        QString filedir = path + "typeDefineText/";
        for (int i = 0; i < ui::Base::TYPE_NUM; i++)
        {
            QFile file(filedir + ui::Base::TYPE_NAME[i] + ".txt");
            if (file.open(QFile::ReadOnly))
            {
                QTextStream stream(m_typeDefineText + i);
                stream << "//***************************************************************************\n["
                       << ui::Base::TYPE_NAME[i] << "]\n" << file.readAll();
            }
            file.close();
        }
    }

    void Resourse::construct(const QString &path)
    {
        Resourse::destruct();
        Resourse::m_singleton = new Resourse(path);
    }

    void Resourse::destruct()
    {
        if (m_singleton)delete m_singleton;
    }

    const QString &Resourse::typeDefineText(ui::Base::TYPE type)
    {
        if (!m_singleton)m_singleton = new Resourse();
        if (type >= 0 && type < ui::Base::TYPE_NUM)
        {
            return m_singleton->m_typeDefineText[type];
        }
        else
        {
            return m_singleton->m_typeDefineText[ui::Base::TYPE_NUM];
        }
    }

    const QString &Resourse::license()
    {
        return m_singleton->m_license;
    }

}}