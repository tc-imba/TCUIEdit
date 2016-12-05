//
// Created by liu on 2016/12/4.
//

#ifndef TCUIEDIT_UIEXCEPTION_H
#define TCUIEDIT_UIEXCEPTION_H

#include "UICore.h"

namespace TCUIEdit
{
    class UIException : QException
    {
    };

    class UIExceptionUndefined : UIException
    {
    };

    class UIExceptionRedefined : UIException
    {
    };

    class UIExceptionNotFound : UIException
    {
    };


};

#endif //TCUIEDIT_UIEXCEPTION_H
