/**
 * @file    PluginContext.h
 * @brief   Declare the abstract PluginContext class to provide initialization data for the construction of the plugins.
 *
 * @author  https://github.com/Kws128
 * @date    2025-07-17
 * @version 1.0
 *
 * @copyright MIT License
 */

#pragma once

 /**
  * @class PluginContext
  * @brief Abstract context data structure passed to the constructor during plugins initialization.
  */
class PluginContext
{
public:
	virtual ~PluginContext() = default;
};