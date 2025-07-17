/**
 * @file    QIPlugin.h
 * @brief   Declares the QIPlugin interface for plugins exporting Qt QWidget-based user interfaces.
 *
 * This interface extends IPlugin to support plugins that provide a QWidget
 * for integration into Qt-based host applications.
 *
 * @author  https://github.com/Kws128
 * @date    2025-07-17
 * @version 1.0
 *
 * @copyright MIT License
 */

#pragma once

#include <QWidget>
#include "IPlugin.h"

class QIPlugin : public IPlugin
{
public:
	virtual ~QIPlugin() = default;

	/// @brief Retrieves the QWidget user interface provided by the plugin.
	/// @return Pointer to QWidget representing the plugin's UI.
	virtual QWidget* GetUI() = 0;
};