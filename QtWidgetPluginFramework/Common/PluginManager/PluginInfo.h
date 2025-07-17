/**
 * @file    PluginInfo.h
 * @brief   Defines the PluginInfo struct that holds plugin metadata, loader, instance, and destroy function pointer.
 *
 * @author  https://github.com/Kws128
 * @date    2025-07-17
 * @version 1.0
 *
 * @copyright MIT License
 */

#pragma  once

#include "IPlugin.h"
#include "PluginTypes.h"
#include "PluginLoader.h"

/**
*  @struct PluginInfo
*  @brief  Holds information about a loaded plugin, including its file path, loader, plugin instance, and destroy function.
*/
struct PluginInfo {

	std::string  path;
	PluginLoader loader;
	IPlugin*	 instance = nullptr;
	fnDestroy    destroy  = nullptr;

	PluginInfo() = default;
	PluginInfo(PluginLoader&& l, IPlugin* i, fnDestroy d, const std::string& p)
		  : loader(std::move(l)), instance(i), destroy(d), path(p)
	{}

	PluginInfo(const PluginInfo&) = delete;
	PluginInfo& operator=(const PluginInfo&) = delete;

	PluginInfo(PluginInfo&&) = default;
	PluginInfo& operator=(PluginInfo&&) = default;
};


