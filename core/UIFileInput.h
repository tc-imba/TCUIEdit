//
// Created by liu on 2016/12/10.
//

#ifndef TCUIEDIT_UIFILE_H
#define TCUIEDIT_UIFILE_H

#include "UICore.h"
#include <QTextStream>

namespace TCUIEdit
{

    class UIFileInput
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

        int lineNum;
        QByteArray data;
        QTextStream *stream;
        CATEGORY category;
        TYPE type;

    public:

        UIFileInput();

        UIFileInput(const QString &path, TYPE type);

        ~UIFileInput();

        void open(const QString &path, TYPE type);

        void reset();

        bool is_open() const
        { return !this->data.isEmpty(); }

        bool eof() const
        { return this->lineNum < 0; }

        int readLineInto(QString &line);

        CATEGORY getCategory() const;

        TYPE getType() const;

        void setType(TYPE type);
    };

};
#endif //TCUIEDIT_UIFILE_H
