//
// Created by liu on 2016/12/3.
//

#pragma once

#include "../core.h"
#include "../Exception.h"

namespace TCUIEdit { namespace Core { namespace UI
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
        Package::Package *_pkg;

        // The TYPE of the UI
        TYPE type = UNKNOWN;

        // The basic attributes
        QString name, display;

        // Protected Functions
        //

        // A common method to get the information to be displayed
        // Only called by virtual const QString getDisplayName() const in child classes
        const QString _getDisplayName() const;

    public:
        // Constructors
        //

        Base(Package::Package *package);

        ~Base();

        // Public Functions
        //

        // Get the parent Package of the UI
        Package::Package *getPackage() const;

        // Return the TYPE of the UI
        TYPE getType() const;

        // Return the name of the TYPE
        // If the TYPE is undefined or unknown, return "UNKNOWN_TYPE"
        static const char *getTypeName(TYPE type);

        // Return this->getTypeName(this->type)
        const char *getTypeName() const;

        // Return the name of the UI
        const QString &getName() const;

        // Set the name of the UI
        // The hashtable of UIs will be updated
        void setName(const QString &name);

        // Return the display text of the UI (subsitituted by WE_STRINGs)
        // If origin is set to true, the origin value display will be returned
        const QString getDisplay(bool origin = false) const;

        // Set the display of the UI
        // TODO: judge whether the setting is valid
        void setDisplay(const QString &display);

        // A pure virtual function
        // Return the actual information to be displayed
        virtual const QString getDisplayName() const = 0;

        // Deleted Functions
        //

        /*virtual void displayDetail(UIMainTree *tree) = delete;

        void initDisplayDetail(UIMainTree *tree) = delete;

        static QTreeWidgetItem *formRow(const QString &strName, const QString &strValue = "") = delete;*/
    };
}}}


