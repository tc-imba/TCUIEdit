//
// Created by liu on 2016/12/3.
//

#pragma once

#include <stdarg.h>
#include "../core.h"
#include "../Exception.h"
#include "../Error.h"

namespace TCUIEdit { namespace core { namespace ui
{
    class Base
    {
    public:

        // The Definition of TYPEs in TriggerData.txt
        // Used to recognize the type of a UIBase
        //

        // The total number of TYPEs
        static const int TYPE_NUM = 10;

        // TYPEs are enumed here according to the definitions
        enum TYPE
        {
            TRIGGER_CATEGORY, TRIGGER_TYPE, TRIGGER_TYPE_DEFAULT, TRIGGER_PARAM,
            TRIGGER_EVENT, TRIGGER_CONDITION, TRIGGER_ACTION, TRIGGER_CALL,
            DEFAULT_TRIGGER_CATEGORY, DEFAULT_TRIGGER, UNKNOWN = -1
        };

        // The name of the TYPEs in TriggerData.txt
        static const char *TYPE_NAME[TYPE_NUM];

    protected:
        // Protected Properties
        //

        // The parent Package
        package::Package *m_pkg;

        // The TYPE of the UI
        TYPE m_type = UNKNOWN;

        // The basic attributes
        QString m_name, m_display;

        // Protected Functions
        //

        // A common method to get the information to be displayed
        // Only called by virtual const QString formDisplay() const in child classes
        // const QString _formDisplay() const;

        QString _formArgument(int argc, ...);

        void _addArgument(QString &str, const QString &arg, bool firstFlag = false);

    public:
        // Constructors
        //

        Base(package::Package *package);

        virtual ~Base() = 0;

        // Public Functions
        //

        // Get the parent Package of the UI
        package::Package *package() const;

        // Return the TYPE of the UI
        TYPE type() const;

        // Return whether the UI is a function
        static bool isFunction(TYPE type);

        bool isFunction() const;

        // Return the name of the TYPE
        // If the TYPE is undefined or unknown, return "UNKNOWN_TYPE"
        static const char *typeName(TYPE type);

        const char *typeName() const;

        // Return the name of the UI
        const QString &name() const;

        // Set the name of the UI
        // The hashtable of UIs will be updated
        virtual void setName(const QString &name);

        // Examine whether the name of the UI is redefined
        // Return an Error with all the redefined UIs
        virtual Error examineName() const;

        // Return the display text of the UI (subsitituted by WE_STRINGs)
        // If origin is set to true, the origin value display will be returned
        const QString display(bool origin = false) const;

        // Set the display of the UI
        // TODO: judge whether the setting is valid
        void setDisplay(const QString &display);

        // A pure virtual function
        // Return the actual information to be displayed
        virtual const QString formDisplay() const;

        // Examine a flag of 0 or 1 or blank
        // Return an Error if a vialation exists
        virtual Error examineFlag(const QString &value, bool optionalFlag = false) const;


        virtual QString trigData()
        {
            return m_name;
        };
    };
}}}


