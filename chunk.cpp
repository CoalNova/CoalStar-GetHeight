#include "chunk.h"

namespace Coal
{
	Chunk* chunkMap = nullptr;
	Point3 mapSize = {};

	bool InitializeChunkMap(const Point3& chunkMapSize)
	{
		if (chunkMap == nullptr)
		{
			mapSize = chunkMapSize;
			chunkMap = new Chunk[mapSize.x * mapSize.y * mapSize.z];
			for (int z = 0; z < mapSize.z; z++)
				for (int y = 0; y < mapSize.y; y++)
					for (int x = 0; x < mapSize.x; x++)
						chunkMap[x + y * mapSize.x + z * mapSize.x * mapSize.y].index = { x,y,z };

			return true;
		}
		return false;
	}

	bool ClearChunkMap()
	{
		if (chunkMap != nullptr)
		{
			mapSize = {};
			delete[] chunkMap;
			return true;
		}
		return false;
	}

	Chunk* GetChunk(const Point3& index)
	{
		if (!IsValidChunkindex(index))
			return nullptr;
		return &chunkMap[index.x + index.y * mapSize.x + index.z * mapSize.x * mapSize.y];
	}

	bool IsValidChunkindex(const Point3& index)
	{
		return index.x >= 0 && index.y >= 0 && index.z >= 0 && index.x < mapSize.x&& index.y < mapSize.y&& index.z < mapSize.z;
	}

	Point3 GetMapSize()
	{
		return mapSize;
	}

	float GetHeight(const Position& position)
	{
		//check if requested height could exist
		if (!IsValidChunkindex(position.index()))
			return 0.0f;
		//check if chunk has loaded height data
		if (GetChunk(position.index())->heights == nullptr)
			return 0.0f;
		//check if requested height is rounded value
		if ((position.raw.x & ((1 << 14) - 1)) == 0 && (position.raw.y & ((1 << 14) - 1)) == 0)
		{
			//check if position indices are odd and interpolate if so
			if ((position.raw.x >> 14 & 1) && (position.raw.y >> 14))
				return (
					GetHeight(position + Vector3(1.0f, 1.0f, 0.0f)) +
					GetHeight(position + Vector3(1.0f, -1.0f, 0.0f)) +
					GetHeight(position + Vector3(-1.0f, -1.0f, 0.0f)) +
					GetHeight(position + Vector3(-1.0f, 1.0f, 0.0f))
					) / 4.0f;
			if ((position.raw.x >> 14) & 1)
				return(
					GetHeight(position + Vector3(1.0f, 0.0f, 0.0f)) +
					GetHeight(position - Vector3(1.0f, 0.0f, 0.0f))
					) / 2.0f;
			if ((position.raw.y >> 14) & 1)
				return(
					GetHeight(position + Vector3(0.0f, 1.0f, 0.0f)) +
					GetHeight(position - Vector3(0.0f, 1.0f, 0.0f))
					) / 2.0f;
			//otherwise resolve directly
			Chunk* chunk = GetChunk(position.index());
			//height data is stored in chunks using a major and minor value
			//the major value is the heightmod, which blanketly sets the base height at some value in an unsigned char * 1024.0f
			//the minor value is an unsigned short * 0.02f, keeping per-height accuracy down to 2 centimeters (or two-hundredths of chosen unit of measure)
			return chunk->heights[(int)(position.axial().x / 2) + (int)((position.axial().y / 2) * 512)] * 0.02f + chunk->heightMod * 1024.0f;
		}

		//else all, utilize the nearest points 

		// c | d
		// - - -
		// a | b

		Point3 raw = Point3(position.raw.x & (((1 << 18) - 1) << 14), position.raw.y & (((1 << 18) - 1) << 14), position.raw.z & (((1 << 18) - 1) << 14));

		float
			a = GetHeight(Position(raw)),
			b = GetHeight(Position(raw + Point3(1 << 14, 0, 0))),
			c = GetHeight(Position(raw + Point3(0, 1 << 14, 0))),
			d = GetHeight(Position(raw + Point3(1 << 14, 1 << 14, 0)));

		//calculate ray plane slope intersection formula 
		Vector3
			origin = Vector3(0, 0, 1),
			ray = Vector3(0, 0, -1),
			alpha = (raw.x > raw.y) ?
			Vector3(1, 0, b - a) :
			Vector3(0, 1, c - a),
			gamma = Vector3(1, 1, d - a),
			normal = BadCross(alpha, gamma);

		float
			denom = VectorDot(normal, ray),
			dist = 0.0f;
		if (abs(denom) > 0.00001f)
			dist = VectorDot(Vector3() - origin, normal) / denom;

		return (dist >= 0) ? dist + a : a;

	}
}