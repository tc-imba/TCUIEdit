//
// Created by liu on 2016/12/4.
//

#pragma once

#include "core.h"
#include <QException>

namespace TCUIEdit { namespace core
{
    class Exception : QException
    {
    };

    class ExceptionUndefined : Exception
    {
    };

    class ExceptionRedefined : Exception
    {
    };

    class ExceptionNotFound : Exception
    {
    };

    class ExceptionFormatError : Exception
    {
    };

    class ExceptionTypeError : Exception
    {
    };

}}


