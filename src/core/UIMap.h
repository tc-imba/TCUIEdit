//
// Created by liu on 2016/12/4.
//

#ifndef TCUIEDIT_UIMAP_H
#define TCUIEDIT_UIMAP_H

#include <QMultiHash>
#include <QList>
#include "UICore.h"
#include "base/UIBase.h"
#include "UIException.h"

namespace TCUIEdit
{
    class UIMap
    {
    private:

    protected:
        /**
         * The Map is saved as an unordered_map (hash map)
         */
        QMultiHash<QString, UIBase *> hashtable;
        //std::unordered_map<std::string, std::list<UIBase *>> map;
    public:
        UIMap();

        /**
         * Add a UI to the Map
         * @param UI
         */
        void addUI(UIBase *UI);

        /**
         * Get all UIs of this name from the Map
         * @param name
         * @return a reference to a list with all UIs of this name
         */
        //QList<UIBase *> getUI(QString &name) const;

        QList<UIBase *> getUI(const QString &name) const;

        /**
         * Remove a UI to the Map
         * @param UI
         */
        void removeUI(UIBase *UI);
    };
};


#endif //TCUIEDIT_UIMAP_H
