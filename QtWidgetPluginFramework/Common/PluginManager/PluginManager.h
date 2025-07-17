/**
 * @file    PluginManager.h
 * @brief   Declares the PluginManager class for managing plugin loading, unloading, execution, and metadata retrieval.
 *
 * @author  ethan
 * @date    2025-07-17
 * @version 1.0
 *
 * @copyright MIT License
 */

#pragma  once
#include <mutex>
#include <unordered_map>
#include "PluginInfo.h"

enum class PluginErrorCode
{
	Success = 0,
	NotLoaded,
	AlreadyLoaded,
	LoadLibraryFailed,
	GetCreateFuncFailed,
	GetDestroyFuncFailed,
	CreatePluginFailed,
	InitializeFailed,
	InvalidContext,
	ShutdownFailed
};

/**
 *  @class PluginManager
 *  @brief Manages the lifecycle of multiple plugins, including loading, unloading, reloading, execution, 
 *         and metadata retrieval in a thread-safe manner.
 */
class PluginManager
{
public:
	PluginManager();
	virtual ~PluginManager();

	PluginManager(const PluginManager& other) = delete;
	PluginManager& operator=(const PluginManager& other) = delete;

	PluginManager(PluginManager&& other) noexcept = default;
	PluginManager& operator=(PluginManager&& other) noexcept = default;

	/// @brief  Loads a plugin from the specified path and initializes it with the given context.
	/// @param  path Path to the plugin library.
	/// @param  ctx Pointer to PluginContext used for initialization.
	/// @return PluginErrorCode indicating operation status.
	PluginErrorCode LoadPlugin(const std::string& path, PluginContext* ctx);


	/// @brief  Unloads the plugin at the specified path.
	/// @param  path Path to the plugin library.
	/// @return PluginErrorCode indicating operation status.
	PluginErrorCode UnLoadPlugin(const std::string& path);

	/// @brief  Reloads the plugin at the specified path with the provided context.
	/// @param  path Path to the plugin library.
	/// @param  ctx Pointer to PluginContext used for initialization.
	/// @return PluginErrorCode indicating operation status.
	PluginErrorCode ReLoadPlugin(const std::string& path, PluginContext* ctx);

	/// @brief  Executes the Execute function for all loaded plugins.
	void ExecuteAll();

	/// @brief  Unloads all currently loaded plugins.
	void UnloadAll();

	/// @brief  Retrieves the metadata of the plugin at the specified path.
	/// @param  path Path to the plugin library.
	/// @return PluginMeta containing plugin metadata.
	PluginMeta  GetPluginMeta(const std::string& path);


	/// @brief  Retrieves the PluginInfo for the plugin at the specified path.
	/// @param  path Path to the plugin library.
	/// @return Pointer to PluginInfo if plugin is loaded; nullptr otherwise.
	PluginInfo* GetPluginInfo(const std::string& path);

protected:
	bool IsLoad(const std::string& path);

protected:
	std::mutex									m_mutex;
	std::unordered_map<std::string, PluginInfo>	m_plugins;
};