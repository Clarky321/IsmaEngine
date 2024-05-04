#ifndef	CUBESHEET_H
#define CUBESHEET_H

#include <unordered_map>
#include <utility>

#include <SFML/Graphics.hpp>

#include <IsmaEngineCore\Graphics\CubeBuilder.h>
#include <IsmaEngineCore\World\Cube.h>

class CubeSheet
{
public:
	CubeSheet();

	void add(CubeID cubeID, const CubeMaterial& material);

	void orient(const CubeOrientation& orientation);

	CubeVisual& getCube(CubeID cubeID);
private:
	std::unordered_map<CubeID, std::pair<CubeMaterial, CubeVisual>> cubes;
	CubeOrientation orientation;
	float scale;
};

#endif