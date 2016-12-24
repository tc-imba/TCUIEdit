//
// Created by liu on 2016/12/10.
//

#include "FileInput.h"

namespace TCUIEdit { namespace core
{
    const char *FileInput::TYPE_FILENAME[FileInput::TYPE_NUM] =
            {"TriggerData.txt", "TriggerStrings.txt", "WorldEditStrings.txt",
             "define.txt", "event.txt", "action.txt", "call.txt"
            };

    // Constructors
    //

    FileInput::FileInput()
    {
        m_stream = NULL;
        this->reset();
    }

    FileInput::FileInput(const QString &path, TYPE type)
    {
        m_stream = NULL;
        this->open(path, type);
    }

    FileInput::~FileInput()
    {
        if (m_stream)delete m_stream;
    }

    // Public Functions
    //

    FileInput::CATEGORY FileInput::category() const
    {
        if (m_category >= 0 && m_category < CATEGORY_NUM)return m_category;
        return CATEGORY_UNKNOWN;
    }

    FileInput::TYPE FileInput::type() const
    {
        if (m_type >= 0 && m_type < TYPE_NUM)return m_type;
        return TYPE_UNKNOWN;
    }

    void FileInput::setType(TYPE type)
    {
        m_type = type;
        if (type == TYPE_UNKNOWN)
        {
            m_category = CATEGORY_UNKNOWN;
        }
        else if (type <= CLASSIC_WE_STRINGS)
        {
            m_category = CLASSIC;
        }
        else if (type <= YDWE_CALL)
        {
            m_category = YDWE;
        }
        else
        {
            m_category = CATEGORY_UNKNOWN;
        }
    }

    void FileInput::reset()
    {
        if (m_stream)delete m_stream;
        m_stream = NULL;
        m_lineNum = 0;
        m_data.clear();
        m_category = CATEGORY_UNKNOWN;
        m_type = TYPE_UNKNOWN;
    }

    void FileInput::open(const QString &path, TYPE type)
    {
        this->reset();
        this->setType(type);
        type = this->type();
        if (type == TYPE_UNKNOWN)return;
        QFile qFile(path + TYPE_FILENAME[type]);
        if (qFile.open(QFile::ReadOnly))
        {
            m_data = qFile.readAll();
            m_stream = new QTextStream(m_data);
            m_stream->setCodec("UTF-8");
            /**
             * @TODO File Codec of input UI File
             * The default format of UI File is UTF-8
             * This version only supports UTF-8 encoding
             * The support of ANSI and UNICODE may be added later
             */
            m_lineNum = 0;
            qFile.close();
        }
        else
        {
            m_lineNum = -1;
        }
    }

    bool FileInput::is_open() const
    {
        return !m_data.isEmpty();
    }

    bool FileInput::eof() const
    {
        return m_lineNum < 0;
    }


    int FileInput::readLineInto(QString &line)
    {
        if (m_lineNum < 0)return 0;
        while (m_stream->readLineInto(&line))
        {
            m_lineNum++;
            auto pos = line.length();
            while (pos > 0)
            {
                if (!line[--pos].isSpace())break;
            }
            line = line.left(pos + 1);
            if (!line.isEmpty())
            {
                return m_lineNum;
            }
        }
        m_lineNum = -1;
        return 0;
    }

}}