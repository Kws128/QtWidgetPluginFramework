#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PLUGINA_LIB)
#  define PLUGINA_EXPORT Q_DECL_EXPORT
# else
#  define PLUGINA_EXPORT Q_DECL_IMPORT
# endif
#else
# define PLUGINA_EXPORT
#endif
