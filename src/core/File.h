//
// Created by liu on 2016/12/10.
//

#pragma once

#include "core.h"
#include <QFile>
#include <QTextStream>
#include <QByteArray>

namespace TCUIEdit { namespace core
{

    class File
    {
    public:

        static const int CATEGORY_NUM = 2;
        enum CATEGORY
        {
            CLASSIC, YDWE, CATEGORY_UNKNOWN = -1
        };
        static const int TYPE_NUM = 7;
        enum TYPE
        {
            CLASSIC_TRIG_DATA, CLASSIC_TRIG_STRINGS, CLASSIC_WE_STRINGS,
            YDWE_DEFINE, YDWE_EVENT, YDWE_ACTION, YDWE_CALL,
            TYPE_UNKNOWN = -1
        };
        static const char *TYPE_FILENAME[TYPE_NUM];

    protected:

        int m_lineNum;
        bool m_readFlag;
        QFile *m_file;
        QByteArray m_data;
        QTextStream *m_stream;
        CATEGORY m_category;
        TYPE m_type;

    public:
        // Constructors
        //

        File();

        ~File();

        // Public Functions
        //

        CATEGORY category() const;

        TYPE type() const;

        void setType(TYPE type);

        void reset();

        void open(const QString &path, TYPE type, bool readFlag);

        bool is_open() const;

        bool eof() const;

        void close();

        int readLineInto(QString &line);

        void writeLine(const QString &text = "");

        void write(const QString &text = "");
    };

}}

