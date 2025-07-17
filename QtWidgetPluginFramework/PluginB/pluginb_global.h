#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PLUGINB_LIB)
#  define PLUGINB_EXPORT Q_DECL_EXPORT
# else
#  define PLUGINB_EXPORT Q_DECL_IMPORT
# endif
#else
# define PLUGINB_EXPORT
#endif
