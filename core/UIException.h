//
// Created by liu on 2016/12/4.
//

#ifndef TCUIEDIT_UIEXCEPTION_H
#define TCUIEDIT_UIEXCEPTION_H

#include "Core.h"

namespace TCUIEdit
{
    class UIException : std::exception
    {

    };

    class UIExceptionNotFound : UIException
    {

    };

};

#endif //TCUIEDIT_UIEXCEPTION_H
