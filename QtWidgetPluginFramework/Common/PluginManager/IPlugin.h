/**
 * @file    IPlugin.h
 * @brief   Defines the abstract base class for all plugins.
 *
 * @author  https://github.com/Kws128
 * @date    2025-07-17
 * @version 1.0
 *
 * @copyright MIT License
 */

#pragma once
#include <string>

enum class PluginExecuteError
{
	Success = 0,
	Failed,
};

struct PluginMeta
{
	std::string name;
	std::string path;
	std::string version;
	std::string description;
	std::string author;

	PluginMeta() : name("") , path("") , version(""), description(""), author("") 
	{}
};

/**
 *  @class IPlugin
 *  @brief Abstract interface for plugin modules.
 */
class IPlugin
{
public:
	virtual ~IPlugin(){}

	/*
	 *  @brief  Initializes the plugin.
	 *  @return true if initialization succeeds; false otherwise.
	 */
	virtual bool Initialize() = 0;

	/*
	 *  @brief  Shuts down the plugin and releases resources.
	 *  @return true if shutdown succeeds; false otherwise.
	 */
	virtual bool Shutdown() = 0;

	/*
	 *  @brief  Retrieves metadata information about the plugin.
	 *  @return PluginMeta structure containing plugin name, version, author, etc.
	 */
	virtual PluginMeta			GetMeta() const = 0;

	/*
	 *  @brief  Executes the plugin's primary functionality.
	 *  @return PluginExecuteError indicating execution result status.
	 */
	virtual PluginExecuteError	Execute() = 0;

};