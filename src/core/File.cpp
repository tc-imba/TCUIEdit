//
// Created by liu on 2016/12/10.
//

#include "File.h"

namespace TCUIEdit { namespace core
{
    const char *File::TYPE_FILENAME[File::TYPE_NUM] =
            {"TriggerData.txt", "TriggerStrings.txt", "WorldEditStrings.txt",
             "define.txt", "event.txt", "action.txt", "call.txt"
            };

    // Constructors
    //

    File::File()
    {
        m_stream = NULL;
        m_file = NULL;
        m_readFlag = true;
        this->reset();
    }

    File::~File()
    {
        if (m_stream)delete m_stream;
    }

    // Public Functions
    //

    File::CATEGORY File::category() const
    {
        if (m_category >= 0 && m_category < CATEGORY_NUM)return m_category;
        return CATEGORY_UNKNOWN;
    }

    File::TYPE File::type() const
    {
        if (m_type >= 0 && m_type < TYPE_NUM)return m_type;
        return TYPE_UNKNOWN;
    }

    void File::setType(TYPE type)
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

    void File::reset()
    {
        if (m_stream)delete m_stream;
        m_stream = NULL;
        this->close();
        m_file = NULL;
        m_lineNum = 0;
        m_data.clear();
        m_category = CATEGORY_UNKNOWN;
        m_type = TYPE_UNKNOWN;
    }

    void File::open(const QString &path, TYPE type, bool readFlag)
    {
        m_readFlag = readFlag;
        this->reset();
        this->setType(type);
        type = this->type();
        if (type == TYPE_UNKNOWN)return;
        m_file = new QFile(path + TYPE_FILENAME[type]);
        if (readFlag)
        {
            if (m_file->open(QFile::ReadOnly))
            {
                m_data = m_file->readAll();
                m_stream = new QTextStream(m_data);
                m_stream->setCodec("UTF-8");
                /**
                 * @TODO File Codec of input UI File
                 * The default format of UI File is UTF-8
                 * This version only supports UTF-8 encoding
                 * The support of ANSI and UNICODE may be added later
                 */
                m_lineNum = 0;
                m_file->close();
            }
            else
            {
                m_lineNum = -1;
            }
        }
        else
        {
            if (m_file->open(QFile::WriteOnly | QFile::Text))
            {
                m_stream = new QTextStream(m_file);
                m_stream->setCodec("UTF-8");
                m_lineNum = -1;
            }
        }
    }

    bool File::is_open() const
    {
        return m_stream != NULL;
    }

    bool File::eof() const
    {
        return m_lineNum < 0 && m_readFlag;
    }

    void File::close()
    {
        if (m_file)
        {
            m_file->close();
            delete m_file;
        }
    }

    int File::readLineInto(QString &line)
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

    void File::writeLine(const QString &text)
    {
        *m_stream << text << endl;
    }

    void File::write(const QString &text)
    {
        *m_stream << text;
    }

}}