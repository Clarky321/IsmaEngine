#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include <IsmaEngineCore\Graphics\Camera.h>
#include <IsmaEngineCore\Graphics\CubeSheet.h>
#include <IsmaEngineCore\World\CubeChunk.h>
#include <IsmaEngineCore\Util\DistanceNoise.h>

class Application : private sf::Drawable
{
public:
	Application();

	void run();
private:
	void init();

	void handleEvent(const sf::Event& ev);

	void update();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	long long frame;

	enum class ChunkSize
	{
		SMALL, MEDIUM, LARGE
	};

	void chunkGen(ChunkSize size);

	enum class Cubes
	{
		EMPTY = -1,
		STONE,
		DIRT,
		GRASS,
		WATER,
		SAND,
		WOOD,
		LEAVES,
		COUNT
	};

	CubeID cbID(Cubes type);

	sf::Texture cubeSheetTexture;
	Camera camera;
	CubeSheet cubeSheet;
	CubeChunk chunk;
	DistanceNoise noise;

	float delta;
	float fps;

	void zeroVels();

	float zoom;
	float zoomVel;

	bool qPressed;
	bool ePressed;
	float spin;
	float spinVel;

	bool wPressed;
	bool aPressed;
	bool sPressed;
	bool dPressed;
	float x;
	float y;
	float xVel;
	float yVel;

	int width;
	int height;
};

#endif


