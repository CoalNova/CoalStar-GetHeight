#pragma once
#include "points.h"
#include "vectors.h"
#include "position.h"

namespace Coal
{
	struct Chunk
	{
		Point3 index = {};
		unsigned short* heights = nullptr;
		unsigned int heightMod = 0;
		//various other data collections will be accessable through this struct
		//the struct should be persistant, and 'loading' and 'unloading' will be handled instead
	};

	/// <summary>
	/// Run on start to initialize the chunk map, subsequent tries will fail
	/// </summary>
	/// <param name="mapSize">The size of the map in width, length, and depth </param>
	/// <returns>Success of map creation, fail if map is already initialized</returns>
	bool InitializeChunkMap(const Point3& mapSize);

	/// <summary>
	/// Deletes and clears chunk map
	/// Currently this is only for closing the engine
	/// </summary>
	/// <returns>Success of map deletion, fail if map unable to be deleted</returns>
	bool ClearChunkMap();

	/// <summary>
	/// Get pointer to chunk at provided index
	/// </summary>
	/// <param name="index">dimensional index of requested chunk</param>
	/// <returns>pointer to chunk, or nullptr if provided index is outside of map scope</returns>
	Chunk* GetChunk(const Point3& index);

	/// <summary>
	/// Checks if provided index is in scope
	/// </summary>
	/// <param name="index">chunk dimensional index</param>
	/// <returns>true, if index exists within the scope of the mapSize supplied during initialization</returns>
	bool IsValidChunkindex(const Point3& index);

	/// <summary>
	/// Returns a copy of the map size provided during initialization
	/// </summary>
	/// <returns> chunk map size </returns>
	Point3 GetMapSize();

	/// <summary>
	/// Returns height as a float, from the requested position
	/// </summary>
	/// <param name="position"> the position of the height request </param>
	/// <returns> the height at the position requested </returns>
	float GetHeight(const Position& position);
}