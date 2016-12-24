//
// Created by liu on 2016/12/4.
//

#include "Package.h"

namespace TCUIEdit { namespace core { namespace package
{

    // Constructors
    //

    Package::Package(Project *project)
    {
        this->init();
        m_proj = project;
    }


    Package::Package(Project *project, const QString &basePath, const QString &name)
    {
        this->init();
        m_proj = project;
        m_basePath = basePath;
        m_name = name;
    }

    Package::~Package()
    {
        delete m_weString;

    }

    // Protected Fcuntions
    //

    void Package::init()
    {
        m_weString = new WEString(this);

        m_base[ui::Base::TRIGGER_CATEGORY] = new Category(this);
        m_base[ui::Base::TRIGGER_TYPE] = new Type(this);
        m_base[ui::Base::TRIGGER_TYPE_DEFAULT] = new TypeDefault(this);
        m_base[ui::Base::TRIGGER_PARAM] = new Param(this);
        m_base[ui::Base::TRIGGER_EVENT] = new Event(this);
        m_base[ui::Base::TRIGGER_CONDITION] = new Condition(this);
        m_base[ui::Base::TRIGGER_ACTION] = new Action(this);
        m_base[ui::Base::TRIGGER_CALL] = new Call(this);

    }

    void Package::processTrigData(QString &line)
    {
        // Match the sign [\w] when a new ui is assigned.
        QRegExp rx("^\\[\\w+\\]$");
        if (rx.indexIn(line) > -1)
        {
            QString tempStr = rx.cap(0);
            tempStr = tempStr.mid(1, tempStr.length() - 2);
            for (int i = 0; i < ui::Base::TYPE_NUM; i++)
            {
                if (tempStr == ui::Base::typeName(ui::Base::TYPE(i)))
                {
                    if (m_baseTypeCurrent != i)
                    {
                        m_baseTypeCurrent = ui::Base::TYPE(i);
                        m_baseChangedFlag = true;
                    }
                    return;
                }
            }
            /**
             * @TODO throw an error here
             * The name of base type is wrong.
             * We won't change the current base.
             * But if we never have a correct one,
             * there will be a fatal error.
             */
            // m_baseTypeCurrent = ui::Base::UNKNOWN;
            return;
        }
        m_baseChangedFlag = false;


        // Match the comments
        rx.setPattern("^//");
        if (rx.indexIn(line) > -1)
        {
            this->baseCurrent()->readComment(line);
            return;
        }

        if (baseTypeCurrent() < ui::Base::TYPE(8))
        {
            this->baseCurrent()->readLine(line);
        }
    }

    void Package::processWEStrings(QString &line)
    {
        // Match the sign [\w] when a new ui is assigned.
        QRegExp rx("^\\[\\w+\\]$");
        if (rx.indexIn(line) > -1)return;
        rx.setPattern("^//");
        if (rx.indexIn(line) > -1)
        {
            return;
        }
        m_weString->readLine(line);
    }

    // Public Functions
    //

    Project *Package::project() const
    {
        return m_proj;
    }

    WEString *Package::weString() const
    {
        return m_weString;
    }

    Base *Package::base(ui::Base::TYPE type) const
    {
        if (type == ui::Base::UNKNOWN)return NULL;
        return m_base[type];
    }

    Base *Package::baseCurrent() const
    {
        return this->base(m_baseTypeCurrent);
    }

    const ui::Base::TYPE Package::baseTypeCurrent() const
    {
        return m_baseTypeCurrent;
    }

    const bool Package::isBaseChanged() const
    {
        return m_baseChangedFlag;
    }

    const QString &Package::name() const
    {
        return m_name;
    }

    void Package::setName(const QString &name)
    {
        m_name = name;
    }

    bool Package::openFile(FileInput::TYPE fileType)
    {
        m_file.open(m_basePath, fileType);
        if (m_file.is_open())
        {
            switch (fileType)
            {
            case FileInput::CLASSIC_TRIG_DATA:m_processLine = &Package::processTrigData;
                break;
            case FileInput::CLASSIC_WE_STRINGS:m_processLine = &Package::processWEStrings;
                break;
            default:return false;
            }
            return true;
        }
        return false;
    }

    int Package::readLine()
    {
        QString line;
        auto lineNum = m_file.readLineInto(line);
        if (lineNum > 0)
        {
            (this->*m_processLine)(line);
        }
        return lineNum;
    }
}}}

